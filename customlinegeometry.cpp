#include "customlinegeometry.h"
#include <QQuick3D>
#include <cfloat>

CustomLineGeometry::CustomLineGeometry(QQuick3DObject *parent): QQuick3DGeometry(parent)
{
}

void CustomLineGeometry::addLine(const QVector3D &start, const QVector3D &end)
{
    // Setze die neuen Start- und Endpunkte
    m_lines.append({start, end, 0.0f});

    // Aktualisiere die Geometrie
    //rebuildGeometry();

    //update();

}

void CustomLineGeometry::addLine(const QVector3D &start, const QVector3D &end, float width)
{
    m_lines.append({start, end, width});
}

void CustomLineGeometry::setCubeHalfSize(float v)
{
    if (qFuzzyCompare(1.0f + m_cubeHalfSize, 1.0f + v)) {
        return;
    }
    m_cubeHalfSize = v;
    emit cubeHalfSizeChanged();
}

void CustomLineGeometry::setLateralOffset(float v)
{
    if (qFuzzyCompare(1.0f + m_lateralOffset, 1.0f + v)) {
        return;
    }
    m_lateralOffset = v;
    emit lateralOffsetChanged();
}

void CustomLineGeometry::setDirectionOffset(float v)
{
    if (qFuzzyCompare(1.0f + m_directionOffset, 1.0f + v)) {
        return;
    }
    m_directionOffset = v;
    emit directionOffsetChanged();
}

// The arrow starts and ends at the surface of the (axis-aligned) rank cubes: a ray in the
// direction d leaves a cube with half edge h at distance h / max(|dx|, |dy|, |dz|).
float CustomLineGeometry::gapFor(const QVector3D &direction) const
{
    if (m_cubeHalfSize <= 0.0f) {
        return 2.0f; // the old fixed gap from the center
    }
    const float m = std::max({qAbs(direction.x()), qAbs(direction.y()), qAbs(direction.z())});
    return m_cubeHalfSize / std::max(m, 0.001f) + 0.5f;
}

void CustomLineGeometry::newFrame(){
    if (m_lines.isEmpty()) {
        return; // Nichts zu tun, wenn keine Linien vorhanden sind
    }
    rebuildGeometry();
    update();
}

void CustomLineGeometry::clearLines()
{
    if (m_lines.isEmpty()) {
        return; // Nichts zu tun, wenn keine Linien vorhanden sind
    }
    m_lines.clear();

    // Aktualisiere die Geometrie (leer)
    rebuildGeometry();
    update();
}


void CustomLineGeometry::rebuildGeometry()
{
    clear(); // Alte Geometrie entfernen

    // Arrows with a width are drawn as triangles, all others as thin line primitives
    for (const auto &line : m_lines) {
        if (line.width > 0.0f) {
            rebuildThickGeometry();
            return;
        }
    }

    // Vertex- und Index-Daten vorbereiten
    QByteArray vertexData;
    QByteArray indexData;
    quint32 index = 0;

    QVector3D minBounds(FLT_MAX, FLT_MAX, FLT_MAX);
    QVector3D maxBounds(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    for (const auto &line : m_lines) {
        // Berechne die Richtung der Linie
        QVector3D direction = (line.end - line.start).normalized();
        // Die Linie wird am Start- und Endpunkt verkürzt (bis zur Oberfläche der Würfel)
        const float shortenDistance = gapFor(direction);

        // Verkürze die Linie sowohl am Startpunkt als auch am Endpunkt
        QVector3D newStart = line.start + direction * shortenDistance;
        QVector3D newEnd = line.end - direction * shortenDistance;

        // Füge Start- und Endpunkt zur Vertex-Daten hinzu (mit verkürztem Start- und Endpunkt)
        float vertices[] = {
            newStart.x(), newStart.y(), newStart.z(),
            newEnd.x(), newEnd.y(), newEnd.z()
        };
        vertexData.append(reinterpret_cast<const char *>(vertices), sizeof(vertices));

        // Füge Indizes hinzu
        quint32 indices[] = {index, index + 1};
        indexData.append(reinterpret_cast<const char *>(indices), sizeof(indices));

        index += 2; // Zwei neue Punkte wurden hinzugefügt

        // Berechne die minimalen und maximalen Werte für die Bounds
        minBounds.setX(std::min({minBounds.x(), newStart.x(), newEnd.x()}));
        minBounds.setY(std::min({minBounds.y(), newStart.y(), newEnd.y()}));
        minBounds.setZ(std::min({minBounds.z(), newStart.z(), newEnd.z()}));

        maxBounds.setX(std::max({maxBounds.x(), newStart.x(), newEnd.x()}));
        maxBounds.setY(std::max({maxBounds.y(), newStart.y(), newEnd.y()}));
        maxBounds.setZ(std::max({maxBounds.z(), newStart.z(), newEnd.z()}));

        // Nutze das Ende der Linie als Basis für den Pfeil
        QVector3D arrowBase = newEnd;

        // Berechne den Vektor senkrecht zur Richtung der Linie
        QVector3D perpendicular1;
        QVector3D perpendicular2;

        // Wenn die Richtung in der Z-Achse liegt, wähle X- oder Y-Achse als Referenz.
        if (qAbs(direction.z()) > 0.9f) {
            perpendicular1 = QVector3D(0, -direction.z(), direction.y()).normalized();
            perpendicular2 = QVector3D(direction.y(), -direction.x(), 0).normalized();
        } else {
            perpendicular1 = QVector3D(-direction.y(), direction.x(), 0).normalized(); // 2D senkrecht zur XY-Ebene
            perpendicular2 = QVector3D::crossProduct(direction, QVector3D(0, 0, 1)).normalized(); // Kreuzprodukt zur Z-Achse
        }



        // Berechne die beiden Pfeilspitzen
        QVector3D arrowLength = direction * 5.0f; // Länge des Pfeilkopfes
        QVector3D arrowPoint1 = arrowBase - arrowLength + perpendicular1 * arrowLength.length() * 0.25f;
        QVector3D arrowPoint2 = arrowBase - arrowLength - perpendicular1 * arrowLength.length() * 0.25f;


        // Füge den Pfeilkopf hinzu
        float arrowVertices[] = {
            arrowBase.x(), arrowBase.y(), arrowBase.z(),
            arrowPoint1.x(), arrowPoint1.y(), arrowPoint1.z(),
            arrowBase.x(), arrowBase.y(), arrowBase.z(),
            arrowPoint2.x(), arrowPoint2.y(), arrowPoint2.z(),
        };
        vertexData.append(reinterpret_cast<const char *>(arrowVertices), sizeof(arrowVertices));

        quint32 arrowIndices[] = {
            index, index + 1,
            index, index + 2,
        };
        indexData.append(reinterpret_cast<const char *>(arrowIndices), sizeof(arrowIndices));

        index += 4; // Vier neue Punkte wurden hinzugefügt
    }

    // Geometrie konfigurieren
    setVertexData(vertexData);
    //setIndexData(indexData);

    // Attribute für Position (x, y, z)
    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Lines); // Zeichne Linien
    setStride(3 * sizeof(float)); // Schrittweite für Vertex-Daten

    // Setze die berechneten Bounds
    setBounds(minBounds, maxBounds);



    emit geometryChanged();
}




// ---------------------------------------------------------------------------
// Thick arrows: a prism with a square cross-section for the shaft and a four-sided
// pyramid as the head. The geometry consists of triangles with flat normals.
// ---------------------------------------------------------------------------
namespace {

void appendVertex(QByteArray &vertexData, const QVector3D &p, const QVector3D &n)
{
    const float v[6] = {p.x(), p.y(), p.z(), n.x(), n.y(), n.z()};
    vertexData.append(reinterpret_cast<const char *>(v), sizeof(v));
}

// "outward" points from the axis of the arrow to the side where the triangle is
void appendTriangle(QByteArray &vertexData, const QVector3D &a, const QVector3D &b,
                    const QVector3D &c, const QVector3D &outward)
{
    QVector3D n = QVector3D::crossProduct(b - a, c - a);
    if (n.lengthSquared() < 1e-12f) {
        return; // degenerate triangle
    }
    n.normalize();
    if (QVector3D::dotProduct(n, outward) < 0.0f) {
        n = -n;
    }
    appendVertex(vertexData, a, n);
    appendVertex(vertexData, b, n);
    appendVertex(vertexData, c, n);
}

void growBounds(QVector3D &minB, QVector3D &maxB, const QVector3D &p)
{
    minB.setX(std::min(minB.x(), p.x()));
    minB.setY(std::min(minB.y(), p.y()));
    minB.setZ(std::min(minB.z(), p.z()));
    maxB.setX(std::max(maxB.x(), p.x()));
    maxB.setY(std::max(maxB.y(), p.y()));
    maxB.setZ(std::max(maxB.z(), p.z()));
}

} // namespace

void CustomLineGeometry::rebuildThickGeometry()
{
    QByteArray vertexData;
    QVector3D minBounds(FLT_MAX, FLT_MAX, FLT_MAX);
    QVector3D maxBounds(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    // corners of the square cross-section as multiples of (u, v)
    static const float su[4] = {1.0f, -1.0f, -1.0f, 1.0f};
    static const float sv[4] = {1.0f, 1.0f, -1.0f, -1.0f};

    for (const auto &line : m_lines) {
        const QVector3D axis = line.end - line.start;
        const float length = axis.length();
        const QVector3D d = axis / std::max(length, 0.0001f);
        const float shortenDistance = gapFor(d);
        if (length <= 2.0f * shortenDistance + 0.1f) {
            continue; // too short to show
        }

        // orthonormal basis (u, v) perpendicular to the direction
        const QVector3D helper = (qAbs(d.y()) < 0.9f) ? QVector3D(0, 1, 0) : QVector3D(1, 0, 0);
        const QVector3D u = QVector3D::crossProduct(d, helper).normalized();
        const QVector3D v = QVector3D::crossProduct(d, u).normalized();

        // Own lane: the type of the arrow (lateralOffset: send up, receive down) and its direction
        // (directionOffset: the two directions of one pair of points on separate lines). The
        // comparison of the end points is exactly opposite for the reverse arrow of the pair.
        const bool forward = (line.start.x() != line.end.x()) ? (line.start.x() < line.end.x())
                           : (line.start.y() != line.end.y()) ? (line.start.y() < line.end.y())
                                                              : (line.start.z() < line.end.z());
        const float lane = m_lateralOffset + (forward ? m_directionOffset : -m_directionOffset);
        const QVector3D shift = (qAbs(d.y()) > 0.9f) ? QVector3D(lane, 0.0f, 0.0f)
                                                      : QVector3D(0.0f, lane, 0.0f);
        const QVector3D start = line.start + shift + d * shortenDistance;
        const QVector3D end = line.end + shift - d * shortenDistance;

        // thin arrows (small volume) still need a readable head
        const float r = std::max(line.width, 0.2f) * 0.5f;   // half the shaft width
        const float headR = std::max(1.8f, r * 2.2f);         // half the head width
        const float headLength = std::max(5.5f, headR * 2.6f);
        const float shaftLength = std::max(0.0f, (end - start).length() - headLength);
        const QVector3D headBase = start + d * shaftLength;

        QVector3D off[4];
        for (int k = 0; k < 4; ++k) {
            off[k] = u * su[k] + v * sv[k];
        }

        for (int k = 0; k < 4; ++k) {
            const int n = (k + 1) % 4;
            const QVector3D outward = off[k] + off[n];

            // shaft: one side face (two triangles)
            const QVector3D s0 = start + off[k] * r;
            const QVector3D s1 = start + off[n] * r;
            const QVector3D e0 = headBase + off[k] * r;
            const QVector3D e1 = headBase + off[n] * r;
            appendTriangle(vertexData, s0, s1, e0, outward);
            appendTriangle(vertexData, s1, e1, e0, outward);

            // head: one side face of the pyramid, plus its base ring facing backwards
            const QVector3D q0 = headBase + off[k] * headR;
            const QVector3D q1 = headBase + off[n] * headR;
            appendTriangle(vertexData, q0, q1, end, outward);
            appendTriangle(vertexData, q0, q1, headBase, -d);

            growBounds(minBounds, maxBounds, s0);
            growBounds(minBounds, maxBounds, q0);
        }
        growBounds(minBounds, maxBounds, end);
    }

    if (vertexData.isEmpty()) {
        setBounds(QVector3D(0, 0, 0), QVector3D(0, 0, 0));
        emit geometryChanged();
        return;
    }

    setVertexData(vertexData);
    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic, 0,
                 QQuick3DGeometry::Attribute::F32Type);
    addAttribute(QQuick3DGeometry::Attribute::NormalSemantic, 3 * sizeof(float),
                 QQuick3DGeometry::Attribute::F32Type);
    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);
    setStride(6 * sizeof(float));
    setBounds(minBounds, maxBounds);
    emit geometryChanged();
}
