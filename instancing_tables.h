#ifndef INSTANCING_TABLES_H
#define INSTANCING_TABLES_H

#include <QtQuick3D/qquick3dinstancing.h>


class Instancing_Tables : public QQuick3DInstancing
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit Instancing_Tables(QQuick3DObject *parent = nullptr);
    ~Instancing_Tables() override;

    int gridSize() const;
    float gridSpacing() const;
    int randomSeed() const;

public slots:
    void setGridSize(int gridSize);
    void setGridSpacing(float gridSpacing);
    void setRandomSeed(int randomSeed);

signals:
    void gridSizeChanged();
    void gridSpacingChanged();
    void randomSeedChanged();

protected:
    QByteArray getInstanceBuffer(int *instanceCount) override;

private:
    int m_instanceCount = 0;
    QByteArray m_instanceData;
    bool m_dirty = true;
    int m_nodesCount;
    int m_randomSeed;
};

#endif // INSTANCING_TABLES_H
