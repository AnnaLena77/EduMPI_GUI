#include <QtQuick3D/qquick3dinstancing.h>

QT_FORWARD_DECLARE_CLASS(QRandomGenerator)

class Nodes_Instances : public QQuick3DInstancing
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int instanceCount READ instanceCount WRITE setInstanceCount NOTIFY instanceCountChanged)

public:
    explicit Nodes_Instances(QQuick3DObject *parent = nullptr);
    ~Nodes_Instances() override;

    int instanceCount() const;

public slots:
    void setInstanceCount(int count);

signals:
    void instanceCountChanged();

protected:
    QByteArray getInstanceBuffer(int *instanceCount) override;

private:
    int m_instanceCount = 0;
    QByteArray m_instanceData;

};
