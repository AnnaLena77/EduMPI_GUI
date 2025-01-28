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

    for (const auto &line : m_lines) {
        // Füge Start- und Endpunkt zur Vertex-Daten hinzu
        float vertices[] = {
            line.start.x(), line.start.y(), line.start.z(),
            line.end.x(), line.end.y(), line.end.z()
        };
        vertexData.append(reinterpret_cast<const char *>(vertices), sizeof(vertices));

        // Füge Indizes hinzu
        quint32 indices[] = {index, index + 1};
        indexData.append(reinterpret_cast<const char *>(indices), sizeof(indices));

        index += 2; // Zwei neue Punkte wurden hinzugefügt

        // Berechne die minimalen und maximalen Werte für die Bounds
        minBounds.setX(std::min({minBounds.x(), line.start.x(), line.end.x()}));
        minBounds.setY(std::min({minBounds.y(), line.start.y(), line.end.y()}));
        minBounds.setZ(std::min({minBounds.z(), line.start.z(), line.end.z()}));

        maxBounds.setX(std::max({maxBounds.x(), line.start.x(), line.end.x()}));
        maxBounds.setY(std::max({maxBounds.y(), line.start.y(), line.end.y()}));
        maxBounds.setZ(std::max({maxBounds.z(), line.start.z(), line.end.z()}));

        // Berechne den Mittelpunkt
        QVector3D midPoint = (line.start + line.end) * 0.5f;

        // Berechne die Richtung
        QVector3D direction = (line.end - line.start).normalized();

        // Berechne zwei Vektoren für den Pfeilkopf (senkrecht zur Linie)
        QVector3D perpendicular1(-direction.y(), direction.x(), 0); // 2D senkrecht
        QVector3D perpendicular2 = QVector3D::crossProduct(direction, QVector3D(0, 0, 1)).normalized();

        float arrowLength = 5.0f; // Länge des Pfeilkopfs
        QVector3D arrowPoint1 = midPoint - direction * arrowLength + perpendicular1 * arrowLength * 0.5f;
        QVector3D arrowPoint2 = midPoint - direction * arrowLength - perpendicular1 * arrowLength * 0.5f;

        // Füge den Pfeilkopf hinzu
        float arrowVertices[] = {
            midPoint.x(), midPoint.y(), midPoint.z(),
            arrowPoint1.x(), arrowPoint1.y(), arrowPoint1.z(),
            midPoint.x(), midPoint.y(), midPoint.z(),
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
