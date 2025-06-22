
#include <QQuickItem>
#include <QOpenGLTexture>

class Heatmap_matrix : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> matrix READ matrix WRITE setMatrix NOTIFY matrixChanged)
    Q_PROPERTY(int gridSize READ gridSize WRITE setGridSize NOTIFY gridSizeChanged)
    Q_PROPERTY(QString combobox MEMBER m_combobox NOTIFY combobox_optionChanged)
    Q_PROPERTY(long matrix_max MEMBER m_matrix_max NOTIFY matrix_maxChanged)
    QML_ELEMENT

public:
    Heatmap_matrix();
    ~Heatmap_matrix();

    QList<QVariant> matrix() const;
    void setMatrix(const QList<QVariant> &data);

    int gridSize() const;
    void setGridSize(int size);

    QColor getHeatmapColor(double value, double max);

signals:
    void matrixChanged();
    void gridSizeChanged();

    void combobox_optionChanged();
    void matrix_maxChanged();


protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;

private:
    QList<QVariant> m_matrix;
    int m_gridSize = 0;
    QOpenGLTexture *m_dummyTexture = nullptr;  // Dummy-Textur speichern
    QString m_combobox;
    long m_matrix_max;
};
