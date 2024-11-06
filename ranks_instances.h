#include "cluster_node.h"
#include "cluster_architecture.h"
#include <QtQuick3D/qquick3dinstancing.h>

QT_FORWARD_DECLARE_CLASS(QRandomGenerator)

class Ranks_Instances : public QQuick3DInstancing
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int instanceCount READ instanceCount WRITE setInstanceCount NOTIFY instanceCountChanged)
    Q_PROPERTY(int outerCubeLength READ outerCubeLength WRITE setOuterCubeLength NOTIFY outerCubeLengthChanged)
    Q_PROPERTY(int innerCubeCount READ innerCubeCount WRITE setInnerCubeCount NOTIFY innerCubeCountChanged)
    Q_PROPERTY(double innerCubeSpacing READ innerCubeSpacing WRITE setInnerCubeSpacing NOTIFY innerCubeSpacingChanged)
    Q_PROPERTY(int rowsColumns READ rowsColumns WRITE setRowsColumns NOTIFY rowsColumnsChanged)
    Q_PROPERTY(double innerCubeScale READ innerCubeScale WRITE setInnerCubeScale NOTIFY innerCubeScaleChanged)
    Q_PROPERTY(long send_datasize READ send_datasize WRITE set_sendDatasize NOTIFY send_datasizeChanged)

    Q_PROPERTY(bool p2p_show READ p2p_show WRITE set_p2pBool NOTIFY p2pBoolChanged)
    Q_PROPERTY(bool coll_show READ coll_show WRITE set_collBool NOTIFY collBoolChanged)
    Q_PROPERTY(QString combobox MEMBER m_combobox NOTIFY combobox_optionChanged)

    Q_PROPERTY(bool components_build READ components_build WRITE setComponents_build NOTIFY components_buildChanged)

    Q_PROPERTY(Cluster_Architecture* nodes MEMBER m_nodes NOTIFY nodesChanged)
    Q_PROPERTY(Cluster_Node* instanceRanks READ instanceRanks WRITE setInstanceRanks NOTIFY instanceRanksChanged)


public:
    explicit Ranks_Instances(QQuick3DObject *parent = nullptr);
    ~Ranks_Instances() override;

    int instanceCount() const;
    int outerCubeLength() const;
    int innerCubeCount() const;
    double innerCubeSpacing() const;
    int rowsColumns() const;
    double innerCubeScale() const;
    //QByteArray outerInstanceData();
    //QVector<Cluster_Rank *> instanceRanks();
    Cluster_Node* instanceRanks();
    void timerRanksChanged();
    long send_datasize();
    bool p2p_show();
    bool coll_show();
    bool components_build();

public slots:
    void setInstanceCount(int count);
    void setOuterCubeLength(int length);
    void setInnerCubeCount(int count);
    void setInnerCubeSpacing(double spacing);
    void setRowsColumns(int rowsColums);
    void setInnerCubeScale(double scale);
    //void setInstanceRanks(QVector<Cluster_Rank *> ranks);
    void setInstanceRanks(Cluster_Node* ranks);
    void set_sendDatasize(long ds);
    //void setOuterInstanceData(QByteArray arr);
    void set_p2pBool(bool show);
    void set_collBool(bool show);
    void setComponents_build(bool comp);

signals:
    void instanceCountChanged();
    void outerCubeLengthChanged();
    void innerCubeCountChanged();
    void innerCubeSpacingChanged();
    void rowsColumnsChanged();
    void innerCubeScaleChanged();
    void instanceRanksChanged();
    void send_datasizeChanged();

    void nodesChanged();
    //void outerInstanceDataChanged();

    void p2pBoolChanged();
    void collBoolChanged();
    void combobox_optionChanged();
    void components_buildChanged();

protected:
    QByteArray getInstanceBuffer(int *instanceCount) override;

private:
    long m_send_datasize = 0;
    int m_instanceCount = 0;
    QByteArray m_outerInstanceData;
    QByteArray m_instanceData;
    int m_outerCubeLength = 0;
    int m_innerCubeCount = 0;
    double m_innerCubeSpacing = 0.0;
    int m_rowsColumns = 0;
    double m_innerCubeScale = 0.0; // Berechnung der Skalierung des inneren Würfel
    //QVector<Cluster_Rank *> m_instanceRanks;
    Cluster_Node* m_instanceRanks;
    Cluster_Architecture* m_nodes;

    bool m_p2p_show;
    bool m_coll_show;
    QString m_combobox;
    bool m_components_build;
};

