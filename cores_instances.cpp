#include "cores_instances.h"
#include <QRandomGenerator>
#include <iostream>
#include <cmath>

Cores_Instances::Cores_Instances(QQuick3DObject *parent)
    :QQuick3DInstancing(parent)
{
    m_instanceCount = 125;
}

Cores_Instances::~Cores_Instances()
{
}
//Getter
int Cores_Instances::instanceCount() const{
    return m_instanceCount;
}
int Cores_Instances::outerCubeLength() const{
    return m_outerCubeLength;
}
int Cores_Instances::innerCubeCount() const{
    return m_innerCubeCount;
}
double Cores_Instances::innerCubeSpacing() const{
    return m_innerCubeSpacing;
}
int Cores_Instances::rowsColumns() const{
    return m_rowsColumns;
}
double Cores_Instances::innerCubeScale() const{
    return m_innerCubeScale;
}
QByteArray Cores_Instances::outerInstanceData(){
    return m_outerInstanceData;
}

//Setter (slots)
void Cores_Instances::setInstanceCount(int count){
    m_instanceCount = count;
    emit instanceCountChanged();
}
void Cores_Instances::setOuterCubeLength(int length){
    m_outerCubeLength = length;
    emit outerCubeLengthChanged();
}
void Cores_Instances::setInnerCubeCount(int count){
    m_innerCubeCount = count;
    emit innerCubeCountChanged();
}
void Cores_Instances::setInnerCubeSpacing(double spacing){
    m_innerCubeSpacing = spacing;
    emit innerCubeSpacingChanged();
}
void Cores_Instances::setRowsColumns(int rowsColums){
    m_rowsColumns = rowsColums;
    emit rowsColumnsChanged();
}
void Cores_Instances::setInnerCubeScale(double scale){
    m_innerCubeScale = scale;
    emit innerCubeScaleChanged();
}
void Cores_Instances::setOuterInstanceData(QByteArray arr){
    m_outerInstanceData = arr;
    emit outerInstanceDataChanged();
}

//Funktion wird automatisch aufgerufen und sorgt für die Positionierung der Outer-Cubes
QByteArray Cores_Instances::getInstanceBuffer(int* instanceCount)
{
    //std::cout << "test " << m_outerInstanceData.data() << std::endl;
    //std::cout << "m_rowsColumns " << m_rowsColumns << ": m_outerCubeLength= " << m_outerCubeLength << ", m_innerCubeSpacing =" << m_innerCubeSpacing << std::endl;
    m_instanceData.resize(0);

    int instanceNumber = 0;
    for (int i = 0; i < m_instanceCount; ++i)
    {
        // Beispiel: Setze die Position für jede Instanz
        float x = (i % m_rowsColumns) * (m_outerCubeLength/m_rowsColumns + m_innerCubeSpacing) - m_outerCubeLength/2 + m_outerCubeLength/(2*m_rowsColumns);
        float y = int(floor(i/m_rowsColumns)) % m_rowsColumns * (m_outerCubeLength/m_rowsColumns + m_innerCubeSpacing) - m_outerCubeLength/2 + m_outerCubeLength/(2*m_rowsColumns);
        float z = floor(i / (m_rowsColumns * m_rowsColumns)) * (-m_outerCubeLength/m_rowsColumns) + m_outerCubeLength/2 - m_outerCubeLength/(m_rowsColumns * 2) - m_innerCubeSpacing;

        float scale = m_innerCubeScale;

        //std::cout << "Instance " << i << ": x=" << x << ", y=" << y << ", z=" << z << std::endl;
        auto entry = calculateTableEntry({ x, y, z }, {scale, scale, scale}, {}, {}, {});
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
