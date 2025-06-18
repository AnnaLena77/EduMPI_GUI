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

                    float x = col * cellSize + spacing / 2.0f;
                    float y = row * cellSize + spacing / 2.0f;
                    float value = rowList[col].toDouble();

                    QColor color = value > 0 ? QColor("red") : QColor("blue");

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


