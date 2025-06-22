#include "heatmap_matrix.h"

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QColor>
#include <QQuickWindow>
#include <qsgflatcolormaterial.h>
#include <heatmapmaterial.h>

Heatmap_matrix::Heatmap_matrix()
    : m_dummyTexture(nullptr)  // Textur hier nur auf nullptr setzen, nicht erzeugen!
{
    setFlag(ItemHasContents, true);
}

Heatmap_matrix::~Heatmap_matrix() {
    delete m_dummyTexture;
    m_dummyTexture = nullptr;
}

QList<QVariant> Heatmap_matrix::matrix() const { return m_matrix; }
void Heatmap_matrix::setMatrix(const QList<QVariant> &data) {
    m_matrix = data;
    update();
    emit matrixChanged();
}

int Heatmap_matrix::gridSize() const { return m_gridSize; }
void Heatmap_matrix::setGridSize(int size) {
    if (m_gridSize != size) {
        m_gridSize = size;
        update();
        emit gridSizeChanged();
    }
}

QSGNode *Heatmap_matrix::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) {
    if (m_matrix.isEmpty() || m_gridSize <= 0)
        return oldNode;


    const float cellSize = 10.0f;
    const float spacing = 2.0f;
    const float adjustedSize = cellSize - spacing;

    const int chunkSize = 32; // 32x32 Zellen pro Chunk
    const int chunksPerRow = (m_gridSize + chunkSize - 1) / chunkSize;

    QSGNode *rootNode = oldNode;
    if (!rootNode) {
        rootNode = new QSGNode();
    } else {
        delete rootNode;
        rootNode = new QSGNode();
    }

    for (int chunkRow = 0; chunkRow < chunksPerRow; ++chunkRow) {
        for (int chunkCol = 0; chunkCol < chunksPerRow; ++chunkCol) {

            int cellsWide = std::min(chunkSize, m_gridSize - chunkCol * chunkSize);
            int cellsHigh = std::min(chunkSize, m_gridSize - chunkRow * chunkSize);
            int cellCount = cellsWide * cellsHigh;

            QSGGeometryNode *chunkNode = new QSGGeometryNode();
            QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), cellCount * 6);
            geometry->allocate(cellCount * 6);
            geometry->setDrawingMode(QSGGeometry::DrawTriangles);
            chunkNode->setGeometry(geometry);
            chunkNode->setFlag(QSGNode::OwnsGeometry);

            HeatmapMaterial *mat = new HeatmapMaterial();
            chunkNode->setMaterial(mat);
            chunkNode->setFlag(QSGNode::OwnsMaterial);

            auto *vertices = geometry->vertexDataAsColoredPoint2D();
            int index = 0;

            for (int localRow = 0; localRow < cellsHigh; ++localRow) {
                int row = chunkRow * chunkSize + localRow;
                const auto rowList = m_matrix[row].toList();

                for (int localCol = 0; localCol < cellsWide; ++localCol) {
                    int col = chunkCol * chunkSize + localCol;

                    float x = (col * cellSize) + (spacing / 2.0f);
                    float y = (row * cellSize) + (spacing / 2.0f);
                    float value = rowList[col].toDouble();

                    QColor color = getHeatmapColor(value, m_matrix_max);

                    //qDebug() << "Test " << m_combobox;

                    vertices[index++].set(x, y, color.red(), color.green(), color.blue(), color.alpha());
                    vertices[index++].set(x + adjustedSize, y, color.red(), color.green(), color.blue(), color.alpha());
                    vertices[index++].set(x, y + adjustedSize, color.red(), color.green(), color.blue(), color.alpha());

                    vertices[index++].set(x + adjustedSize, y, color.red(), color.green(), color.blue(), color.alpha());
                    vertices[index++].set(x + adjustedSize, y + adjustedSize, color.red(), color.green(), color.blue(), color.alpha());
                    vertices[index++].set(x, y + adjustedSize, color.red(), color.green(), color.blue(), color.alpha());
                }
            }

            chunkNode->markDirty(QSGNode::DirtyGeometry);
            rootNode->appendChildNode(chunkNode);
        }
    }

    return rootNode;
}
QColor Heatmap_matrix::getHeatmapColor(double value, double max) {
    if (value <= 0.0 || max <= 0.0)
        return QColor("#eeeeee");  // Hellgrau für genau 0 – deutlich unterscheidbar

    double ratio = value / max;
    ratio = std::clamp(ratio, 0.0, 1.0);

    // Interpolationsverlauf: Blau → Cyan → Grün → Gelb → Rot
    if (ratio < 0.25) {
        // Blau (0,0,255) → Cyan (0,255,255)
        double t = ratio / 0.25;
        return QColor(0, int(255 * t), 255);
    } else if (ratio < 0.5) {
        // Cyan → Grün
        double t = (ratio - 0.25) / 0.25;
        return QColor(0, 255, int(255 * (1 - t)));
    } else if (ratio < 0.75) {
        // Grün → Gelb
        double t = (ratio - 0.5) / 0.25;
        return QColor(int(255 * t), 255, 0);
    } else {
        // Gelb → Rot
        double t = (ratio - 0.75) / 0.25;
        return QColor(255, int(255 * (1 - t)), 0);
    }
}




