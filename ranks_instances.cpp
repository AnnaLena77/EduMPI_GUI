#include "ranks_instances.h"
#include "qdatetime.h"
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
bool Ranks_Instances::components_build(){
    return m_components_build;
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
void Ranks_Instances::setComponents_build(bool comp){
    m_components_build = comp;
    markDirty();
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
    //std::cout << "test " << m_nodes->coll_send_max() << std::endl;

    m_instanceData.resize(0);

    int instanceNumber = 0;
    for (int i = 0; i < m_instanceCount; ++i)
    {
        // Beispiel: Setze die Position für jede Instanz
        float x = (i % m_rowsColumns) * (m_outerCubeLength/m_rowsColumns + m_innerCubeSpacing) - m_outerCubeLength/2 + m_outerCubeLength/(2*m_rowsColumns);
        float y = int(floor(i/m_rowsColumns)) % m_rowsColumns * (m_outerCubeLength/m_rowsColumns + m_innerCubeSpacing) - m_outerCubeLength/2 + m_outerCubeLength/(2*m_rowsColumns);
        float z = floor(i / (m_rowsColumns * m_rowsColumns)) * (-m_outerCubeLength/m_rowsColumns) + m_outerCubeLength/2 - m_outerCubeLength/(m_rowsColumns * 2) - m_innerCubeSpacing;

        m_instanceRanks->rankAt(i)->set_position({x,y,z});

        float scale = m_innerCubeScale;

        long send_data, recv_data;
        float red, green, blue;

        if(m_p2p_show && m_coll_show){
            send_data = m_instanceRanks->rankAt(i)->p2p_send_datasize() + m_instanceRanks->rankAt(i)->coll_send_datasize();
            recv_data = m_instanceRanks->rankAt(i)->p2p_recv_datasize() + m_instanceRanks->rankAt(i)->coll_recv_datasize();
            //max_send = m_instanceRanks.
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

        double full_percent = 0, send_percent = 0, recv_percent = 0;

        if(m_combobox == "Send/Recv Ratio (per Proc)"){
            full_percent = static_cast<double>(send_data) + static_cast<double>(recv_data);
            send_percent = send_data / full_percent;
            recv_percent = recv_data / full_percent;

            /*std::cout << "Full_Percent: " << full_percent << " Send_Percent: " << send_percent << " Recv_Percent: " << recv_percent << std::endl;
            QDateTime current_time = QDateTime::currentDateTime();
            std::cout << "Frontend-Time: " << current_time.toString("yyyy-MM-dd HH:mm:ss").toStdString() << std::endl;*/

            red = recv_percent * 255; // Je höher der Empfangsanteil, desto mehr Rot
            green = send_percent * 255; // Je höher der Sendeanteil, desto mehr Grün
            blue = 255 - (red + green); // Rest wird in Blau gemischt
        } else if(m_combobox == "Max Send Ratio (over all Procs)"){
            if(m_p2p_show && m_coll_show){
                full_percent = static_cast<double>(m_nodes->coll_send_max()) + static_cast<double>(m_nodes->p2p_send_max());
            } else if(m_p2p_show){
                full_percent = static_cast<double>(m_nodes->p2p_send_max());
            } else if(m_coll_show){
                full_percent = static_cast<double>(m_nodes->coll_send_max());
            }
            send_percent = send_data / full_percent;
            green = 255;
            red = 255 - send_percent*255;
            blue = 255 - send_percent*255;

            //std::cout << "Send_data: " << send_data << " Full_Perc: " << full_percent << " Send_Perc: " << send_percent << " Coll_send_max: " << m_nodes->coll_send_max() << " p2p_send_max: " << m_nodes->p2p_send_max() << std::endl;

        } else if(m_combobox == "Max Recv Ratio (over all Procs)"){
            if(m_p2p_show && m_coll_show){
                full_percent = static_cast<double>(m_nodes->coll_recv_max()) + static_cast<double>(m_nodes->p2p_recv_max());
            } else if(m_p2p_show){
                full_percent = static_cast<double>(m_nodes->p2p_recv_max());
            } else if(m_coll_show){
                full_percent = static_cast<double>(m_nodes->coll_recv_max());
            }
            recv_percent = recv_data / full_percent;
            //std::cout << "Recv_data: " << recv_data << " Full_Perc: " << full_percent << " Recv_Perc: " << recv_percent << std::endl;
            red = 255;
            green = 255 - recv_percent*255;
            blue = 255 - recv_percent*255;

        } else if(m_combobox == "Wait for Late Sender (per Proc)"){

            float lateSenderData = 0;
            float coll_data = m_instanceRanks->rankAt(i)->coll_late_sender();
            float p2p_data = m_instanceRanks->rankAt(i)->p2p_late_sender();
            float coll_time_diff = m_instanceRanks->rankAt(i)->coll_timediff();
            float p2p_time_diff = m_instanceRanks->rankAt(i)->p2p_timediff();

            if(m_p2p_show && m_coll_show){
                if(coll_data == 0) {
                    lateSenderData = p2p_data/p2p_time_diff;
                } else if (p2p_data == 0){
                    lateSenderData = coll_data/coll_time_diff;
                } else {
                    float p2p_lates = p2p_data/p2p_time_diff;
                    float coll_lates = coll_data/coll_time_diff;
                    float time_diff = p2p_time_diff + coll_time_diff;

                    float weight_p2p = (p2p_time_diff/time_diff) * p2p_lates;
                    float weight_coll = (coll_time_diff/time_diff) * coll_lates;

                    lateSenderData = weight_p2p + weight_coll;
                }
            } else if(m_p2p_show) {
                lateSenderData = p2p_data/p2p_time_diff;
            } else if(m_coll_show) {
                lateSenderData = coll_data/coll_time_diff;;
            }
            blue = 255;
            red = 255 - lateSenderData*255;
            green = 255 - lateSenderData*255;

        } else if(m_combobox == "Wait for Late Recver (per Proc)"){
            float lateRecvrData = 0;
            float coll_data = m_instanceRanks->rankAt(i)->coll_late_recvr();
            float p2p_data = m_instanceRanks->rankAt(i)->p2p_late_recvr();
            float coll_time_diff = m_instanceRanks->rankAt(i)->coll_timediff();
            float p2p_time_diff = m_instanceRanks->rankAt(i)->p2p_timediff();

            if(m_p2p_show && m_coll_show){
                if(coll_data == 0) {
                    lateRecvrData = p2p_data/p2p_time_diff;
                } else if (p2p_data == 0){
                    lateRecvrData = coll_data/coll_time_diff;
                } else {
                    float p2p_lates = p2p_data/p2p_time_diff;
                    float coll_lates = coll_data/coll_time_diff;
                    float time_diff = p2p_time_diff + coll_time_diff;

                    float weight_p2p = (p2p_time_diff/time_diff) * p2p_lates;
                    float weight_coll = (coll_time_diff/time_diff) * coll_lates;

                    lateRecvrData = weight_p2p + weight_coll;
                }
            } else if(m_p2p_show) {
                lateRecvrData = p2p_data/p2p_time_diff;
            } else if(m_coll_show) {
                lateRecvrData = coll_data/coll_time_diff;
            }
            blue = 255;
            red = 255 - lateRecvrData*255;
            green = 255 - lateRecvrData*255;
        }

        QColor col(red, green, blue);

        //std::cout << "Instance " << i << ": x=" << x << ", y=" << y << ", z=" << z << std::endl;
        auto entry = calculateTableEntry({ x, y, z }, {scale, scale, scale}, {}, {col}, {x,y,z,0});
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
