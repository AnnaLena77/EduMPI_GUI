#include <QtQuick3D/qquick3dinstancing.h>

QT_FORWARD_DECLARE_CLASS(QRandomGenerator)

class Cores_Instances : public QQuick3DInstancing
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int instanceCount READ instanceCount WRITE setInstanceCount NOTIFY instanceCountChanged)
    Q_PROPERTY(int outerCubeLength READ outerCubeLength WRITE setOuterCubeLength NOTIFY outerCubeLengthChanged)
    Q_PROPERTY(int innerCubeCount READ innerCubeCount WRITE setInnerCubeCount NOTIFY innerCubeCountChanged)
    Q_PROPERTY(double innerCubeSpacing READ innerCubeSpacing WRITE setInnerCubeSpacing NOTIFY innerCubeSpacingChanged)
    Q_PROPERTY(int rowsColumns READ rowsColumns WRITE setRowsColumns NOTIFY rowsColumnsChanged)
    Q_PROPERTY(double innerCubeScale READ innerCubeScale WRITE setInnerCubeScale NOTIFY innerCubeScaleChanged)
    Q_PROPERTY(QByteArray outerInstanceData READ outerInstanceData WRITE setOuterInstanceData NOTIFY outerInstanceDataChanged)

public:
    explicit Cores_Instances(QQuick3DObject *parent = nullptr);
    ~Cores_Instances() override;

    int instanceCount() const;
    int outerCubeLength() const;
    int innerCubeCount() const;
    double innerCubeSpacing() const;
    int rowsColumns() const;
    double innerCubeScale() const;
    QByteArray outerInstanceData();

public slots:
    void setInstanceCount(int count);
    void setOuterCubeLength(int length);
    void setInnerCubeCount(int count);
    void setInnerCubeSpacing(double spacing);
    void setRowsColumns(int rowsColums);
    void setInnerCubeScale(double scale);
    void setOuterInstanceData(QByteArray arr);

signals:
    void instanceCountChanged();
    void outerCubeLengthChanged();
    void innerCubeCountChanged();
    void innerCubeSpacingChanged();
    void rowsColumnsChanged();
    void innerCubeScaleChanged();
    void outerInstanceDataChanged();

protected:
    QByteArray getInstanceBuffer(int *instanceCount) override;

private:
    int m_instanceCount = 0;
    QByteArray m_outerInstanceData;
    QByteArray m_instanceData;
    int m_outerCubeLength = 0;
    int m_innerCubeCount = 0;
    double m_innerCubeSpacing = 0.0;
    int m_rowsColumns = 0;
    double m_innerCubeScale = 0.0; // Berechnung der Skalierung des inneren Würfel
};

