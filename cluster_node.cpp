#include "cluster_node.h"
#include <iostream>
//#include "database_connection.h"

Cluster_Node::Cluster_Node(QObject *parent) : QObject(parent)
{
    //timerId = startTimer(5000);
    //connect(this, &Cluster_Node::destroyed, this, &Cluster_Node::onDestroyed);
}

Cluster_Node::Cluster_Node(QObject *parent, std::string name) : QObject(parent), m_name(name)
{
    //connect(this, &Cluster_Node::destroyed, this, &Cluster_Node::onDestroyed);
    //timerId = startTimer(5000);
}

void Cluster_Node::updateRanks(){
    //Database_Connection *db_conn = new Database_Connection;


    /*using namespace bsoncxx::builder::basic;

    //std::cout << "Start_ID: " << m_start_id << std::endl;

    mongocxx::pipeline componentFilter{};
    componentFilter.match(make_document(kvp("ident", make_document(kvp("$gt", m_start_id)))));
    componentFilter.match(make_document(kvp("processrank", make_document(kvp("$gt", m_cores.first()->getId()-1), kvp("$lte", m_cores.last()->getId())))));
    componentFilter.group(make_document(kvp("_id", "$processrank"),
                                        kvp("datasize", make_document(kvp("$sum", "$datasize"))),
                                        kvp("lastid", make_document(kvp("$last", "$ident")))));

    mongocxx::collection coll = db_conn->getColl();
    mongocxx::cursor cursor = coll.aggregate(componentFilter, mongocxx::options::aggregate{});
    for(auto doc : cursor) {
        //std::cout << bsoncxx::to_json(doc) << "\n";
        int id = doc["_id"].get_int32();
        bsoncxx::document::element ds = doc["datasize"];

        int first_id = this->m_cores.first()->getId();
        //std::cout << "First_id = " << first_id << "\n";
        //std::cout << "id = " << id << "\n";
        int datasize;
        if(ds.type()==bsoncxx::v_noabi::type::k_int32){
            datasize = ds.get_int32();
        }
        else {
            datasize = ds.get_int64();
        }
        int ident = doc["lastid"].get_int32();
        //std::cout << "lastid: " << ident << std::endl;
        if(ident>m_start_id) m_start_id = ident;
        //std::cout << "Difference = " << id-first_id << "\n";
    m_cores[id-first_id]->setDatasize(datasize);
    }*/
}

QVector<Cluster_Rank *> Cluster_Node::ranks(){
    return m_ranks;
}

void Cluster_Node::setRanks(QVector<Cluster_Rank *> list){

}

//Destruktor, m_cores will be deleted
Cluster_Node::~Cluster_Node()
{
    //qDebug() << "Hier wird ein Node gelöscht!";
    //qDeleteAll(m_ranks);
    //m_ranks.clear();
}

int Cluster_Node::count() const
{
    return m_ranks.count();
}

QString Cluster_Node::getName()const{
    return QString::fromStdString(this->m_name);
}

int Cluster_Node::getSmalestRankId(){
    return m_smalest_rank;
}

void Cluster_Node::addRank(Cluster_Rank* rank){
    if(m_ranks.empty()){
        m_ranks << rank;
        m_smalest_rank = rank->getId();
        m_biggest_rank = rank->getId();
    }
    else{
        /*for(int i = 0; i<m_ranks.size(); i++)
        {
            if(m_ranks[i]->getId()>rank->getId()){
               m_ranks.insert(i, rank);
               return;
            }
        }*/
        if(m_smalest_rank>rank->getId()) m_smalest_rank = rank->getId();
        if(m_biggest_rank<rank->getId()) m_biggest_rank = rank->getId();
        m_ranks.append(rank);
    }
}

Cluster_Rank* Cluster_Node::rankAt(int index)
{
    if(index < 0 || index >= m_ranks.count())
        return 0;

    //QQmlEngine::setObjectOwnership(m_cores[index], QQmlEngine::CppOwnership)

    return m_ranks[index];
}

/*void Cluster_Node::timerEvent(QTimerEvent* event){
    //updateRanks();
}*/
