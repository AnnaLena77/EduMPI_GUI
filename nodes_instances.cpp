#include "nodes_instances.h"
#include <QRandomGenerator>
#include <iostream>

Nodes_Instances::Nodes_Instances(QQuick3DObject *parent)
    :QQuick3DInstancing(parent)
{
    //m_instanceCount = 170;
}

Nodes_Instances::~Nodes_Instances()
{
}

void Nodes_Instances::setInstanceCount(int count){
    m_instanceCount = count;
    emit instanceCountChanged();
}

int Nodes_Instances::instanceCount() const{
    return m_instanceCount;
}

//Funktion wird automatisch aufgerufen und sorgt für die Positionierung der Outer-Cubes
QByteArray Nodes_Instances::getInstanceBuffer(int* instanceCount)
{
    m_instanceData.resize(0);

    int instanceNumber = 0;
    for (int i = 0; i < m_instanceCount; ++i)
    {
        // Beispiel: Setze die Position für jede Instanz
        float x = ((i % 2) * 600 - 300);
        float y = ((i / 2) % 4) * 150 - 220;
        float z = (i / 8) * -150;

        //std::cout << "Instance " << i << ": x=" << x << ", y=" << y << ", z=" << z << std::endl;
        auto entry = calculateTableEntry({ x, y, z }, { 1.0, 1.0, 1.0 }, {}, {}, {});
        m_instanceData.append(reinterpret_cast<const char *>(&entry), sizeof(entry));
        instanceNumber++;
    }
    m_instanceCount = instanceNumber;

    // Setze den Wert von instanceCount
    *instanceCount = m_instanceCount;

    if (instanceCount)
        *instanceCount = m_instanceCount;

    return m_instanceData;
}
