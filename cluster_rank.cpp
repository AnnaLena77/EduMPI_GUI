#include "cluster_rank.h"
#include "qdebug.h"
#include "database_connection.h"


Cluster_Rank::Cluster_Rank(QObject *parent)
    : QObject(parent)
{
}
Cluster_Rank::Cluster_Rank(QObject *parent, int id) : QObject(parent), m_id(id)
{
    //connect(this, &Cluster_Rank::destroyed, this, &Cluster_Rank::onDestroyed);
    m_p2p_send_datasize = 0;
    m_p2p_recv_datasize = 0;
    m_coll_send_datasize = 0;
    m_coll_recv_datasize = 0;
    m_p2p_late_recvr = 0.0;
    m_coll_late_recvr = 0.0;
    m_p2p_late_sender = 0.0;
    m_coll_late_sender = 0.0;
    m_coll_timediff = 0.0;
    m_p2p_timediff = 0.0;
}

int Cluster_Rank::getId() const{
    return this->m_id;
}

Cluster_Rank::~Cluster_Rank()
{
    //qDebug() << "Hier wird ein Rank gelöscht!";
}

long Cluster_Rank::p2p_send_datasize() {
    return m_p2p_send_datasize;
}
long Cluster_Rank::coll_send_datasize() {
    return m_coll_send_datasize;
}

long Cluster_Rank::p2p_recv_datasize() {
    return m_p2p_recv_datasize;
}
long Cluster_Rank::coll_recv_datasize() {
    return m_coll_recv_datasize;
}

float Cluster_Rank::p2p_late_sender() {
    return m_p2p_late_sender;
}
float Cluster_Rank::p2p_late_recvr() {
    return m_p2p_late_recvr;
}
float Cluster_Rank::p2p_timediff(){
    return m_p2p_timediff;
}
float Cluster_Rank::coll_late_sender(){
    return m_coll_late_sender;
}
float Cluster_Rank::coll_late_recvr(){
    return m_coll_late_recvr;
}
float Cluster_Rank::coll_timediff(){
    return m_coll_timediff;
}

void Cluster_Rank::set_p2p_sendDatasize(long datasize){
    m_p2p_send_datasize = datasize;
    emit send_p2p_datasizeChanged();
}
void Cluster_Rank::set_coll_sendDatasize(long datasize){
    m_coll_send_datasize = datasize;
    emit send_coll_datasizeChanged();
}
void Cluster_Rank::set_p2p_recvDatasize(long datasize){
    m_p2p_recv_datasize = datasize;
    emit recv_p2p_datasizeChanged();
}
void Cluster_Rank::set_coll_recvDatasize(long datasize){
    m_coll_recv_datasize = datasize;
    emit recv_coll_datasizeChanged();
}

void Cluster_Rank::set_p2p_late_sender(float time){
    m_p2p_late_sender = time;
    emit p2p_late_senderChanged();
}
void Cluster_Rank::set_p2p_late_recvr(float time){
    m_p2p_late_recvr = time;
    emit p2p_late_recvrChanged();
}
void Cluster_Rank::set_p2p_timediff(float time){
    m_p2p_timediff = time;
    emit p2p_timediffChanged();
}
void Cluster_Rank::set_coll_late_sender(float time){
    m_coll_late_sender = time;
    emit coll_late_senderChanged();
}
void Cluster_Rank::set_coll_late_recvr(float time){
    m_coll_late_recvr = time;
    emit coll_late_recvrChanged();
}
void Cluster_Rank::set_coll_timediff(float time){
    m_coll_timediff = time;
    emit coll_timediffChanged();
}


/*void Cluster_Rank::timerEvent(QTimerEvent* event){
    //updateDatasize();
    //emit datasizeChanged();
}*/
