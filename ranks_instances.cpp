#include "ranks_instances.h"
#include <QRandomGenerator>
#include <iostream>
#include <cmath>

Ranks_Instances::Ranks_Instances(QQuick3DObject *parent)
    :QQuick3DInstancing(parent)
{
    m_instanceCount = 125;
}

Ranks_Instances::~Ranks_Instances()
{
}
//Getter
int Ranks_Instances::instanceCount() const{
    return m_instanceCount;
}
int Ranks_Instances::outerCubeLength() const{
    return m_outerCubeLength;
}
int Ranks_Instances::innerCubeCount() const{
    return m_innerCubeCount;
}
double Ranks_Instances::innerCubeSpacing() const{
    return m_innerCubeSpacing;
}
int Ranks_Instances::rowsColumns() const{
    return m_rowsColumns;
}
double Ranks_Instances::innerCubeScale() const{
    return m_innerCubeScale;
}
//QVector<Cluster_Rank*>
Cluster_Node* Ranks_Instances::instanceRanks(){
    return m_instanceRanks;
}
long Ranks_Instances::send_datasize(){
    return m_send_datasize;
}
bool Ranks_Instances::p2p_show(){
    return m_p2p_show;
}
bool Ranks_Instances::coll_show(){
    return m_coll_show;
}

/*QByteArray Ranks_Instances::outerInstanceData(){
    return m_outerInstanceData;
}*/

//Setter (slots)
void Ranks_Instances::setInstanceCount(int count){
    m_instanceCount = count;
    emit instanceCountChanged();
}
void Ranks_Instances::setOuterCubeLength(int length){
    m_outerCubeLength = length;
    emit outerCubeLengthChanged();
}
void Ranks_Instances::setInnerCubeCount(int count){
    m_innerCubeCount = count;
    emit innerCubeCountChanged();
}
void Ranks_Instances::setInnerCubeSpacing(double spacing){
    m_innerCubeSpacing = spacing;
    emit innerCubeSpacingChanged();
}
void Ranks_Instances::setRowsColumns(int rowsColums){
    m_rowsColumns = rowsColums;
    emit rowsColumnsChanged();
}
void Ranks_Instances::setInnerCubeScale(double scale){
    m_innerCubeScale = scale;
    emit innerCubeScaleChanged();
}
//void Ranks_Instances::setInstanceRanks(QVector<Cluster_Rank *> ranks){
void Ranks_Instances::setInstanceRanks(Cluster_Node* node){
    m_instanceRanks = node;
    emit instanceRanksChanged();
}
void Ranks_Instances::set_p2pBool(bool show){
    m_p2p_show = show;
    markDirty();
    //emit p2pBoolChanged();
}
void Ranks_Instances::set_collBool(bool show){
    m_coll_show = show;
    markDirty();
    //emit collBoolChanged();
}
/*void Ranks_Instances::setOuterInstanceData(QByteArray arr){
    m_outerInstanceData = arr;
    emit outerInstanceDataChanged();
}*/

void Ranks_Instances::timerRanksChanged(){
    markDirty();
}
void Ranks_Instances::set_sendDatasize(long ds){
    //std::cout << "Changed\n" << std::endl;
    markDirty();
}

//Funktion wird automatisch aufgerufen und sorgt für die Positionierung der Inner-Cubes
QByteArray Ranks_Instances::getInstanceBuffer(int* instanceCount)
{
    //std::cout << "test " << m_instanceRanks->rankAt(0)->recv_datasize() << std::endl;
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

        float send_data, recv_data;
        float red, green, blue;

        if(m_p2p_show && m_coll_show){
            send_data = m_instanceRanks->rankAt(i)->p2p_send_datasize() + m_instanceRanks->rankAt(i)->coll_send_datasize();
            recv_data = m_instanceRanks->rankAt(i)->p2p_recv_datasize() + m_instanceRanks->rankAt(i)->coll_recv_datasize();
        }
        else if(m_p2p_show){
            send_data = m_instanceRanks->rankAt(i)->p2p_send_datasize();
            recv_data = m_instanceRanks->rankAt(i)->p2p_recv_datasize();
        }
        else if(m_coll_show){
            send_data = m_instanceRanks->rankAt(i)->coll_send_datasize();
            recv_data = m_instanceRanks->rankAt(i)->coll_recv_datasize();
        }
        else {
            send_data = 0;
            recv_data = 0;
        }

        if(m_combobox == "Send/Recv Ratio"){
            float full_percent = send_data + recv_data;
            float send_percent = send_data / full_percent;
            float recv_percent = recv_data / full_percent;

            red = recv_percent * 255; // Je höher der Empfangsanteil, desto mehr Rot
            green = send_percent * 255; // Je höher der Sendeanteil, desto mehr Grün
            blue = 255 - (red + green); // Rest wird in Blau gemischt
        } else if(m_combobox == "Max Send Ratio"){

        }

        QColor col(red, green, blue);

        //std::cout << "Instance " << i << ": x=" << x << ", y=" << y << ", z=" << z << std::endl;
        auto entry = calculateTableEntry({ x, y, z }, {scale, scale, scale}, {}, {col}, {});
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
