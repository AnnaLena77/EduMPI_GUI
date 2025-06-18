
#include <QQuickItem>
#include <QOpenGLTexture>

class Heatmap_matrix : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> matrix READ matrix WRITE setMatrix NOTIFY matrixChanged)
    Q_PROPERTY(int gridSize READ gridSize WRITE setGridSize NOTIFY gridSizeChanged)
    QML_ELEMENT

public:
    Heatmap_matrix();
    ~Heatmap_matrix();

    QList<QVariant> matrix() const;
    void setMatrix(const QList<QVariant> &data);

    int gridSize() const;
    void setGridSize(int size);

signals:
    void matrixChanged();
    void gridSizeChanged();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;

private:
    QList<QVariant> m_matrix;
    int m_gridSize = 0;
    QOpenGLTexture *m_dummyTexture = nullptr;  // Dummy-Textur speichern
};
