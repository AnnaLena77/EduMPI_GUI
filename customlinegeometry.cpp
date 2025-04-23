#include "customlinegeometry.h"
#include <QQuick3D>
#include <cfloat>

CustomLineGeometry::CustomLineGeometry(QQuick3DObject *parent): QQuick3DGeometry(parent)
{
}

void CustomLineGeometry::addLine(const QVector3D &start, const QVector3D &end)
{
    // Setze die neuen Start- und Endpunkte
    m_lines.append({start, end});

    // Aktualisiere die Geometrie
    //rebuildGeometry();

    //update();

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

    // Vertex- und Index-Daten vorbereiten
    QByteArray vertexData;
    QByteArray indexData;
    quint32 index = 0;

    QVector3D minBounds(FLT_MAX, FLT_MAX, FLT_MAX);
    QVector3D maxBounds(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    float shortenDistance = 2.0f; // Fester Wert in Millimetern, um den die Linie verkürzt wird (z.B. 3 mm)

    for (const auto &line : m_lines) {
        // Berechne die Richtung der Linie
        QVector3D direction = (line.end - line.start).normalized();

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


