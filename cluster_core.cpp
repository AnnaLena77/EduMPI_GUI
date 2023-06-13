#include "cluster_core.h"
#include "qdebug.h"
#include "database_connection.h"


Cluster_Core::Cluster_Core(QObject *parent)
    : QObject(parent)
{
    timerId = startTimer(500);
}
Cluster_Core::Cluster_Core(QObject *parent, int id) : QObject(parent), m_id(id)
{
    timerId = startTimer(500);
    m_datasize = 0;
}

int Cluster_Core::getId() const{
    return this->m_id;
}

Cluster_Core::~Cluster_Core()
{
        killTimer(timerId);
}

void Cluster_Core::updateDatasize(){
    Database_Connection *db_conn = new Database_Connection;
    using namespace bsoncxx::builder::basic;

    mongocxx::pipeline componentFilter{};

    componentFilter.match(make_document(kvp("processrank", this->m_id)));
    componentFilter.group(make_document(kvp("_id", "$processrank"),
                                        kvp("datasize", make_document(kvp("$sum", "$datasize")))));

    mongocxx::collection coll = db_conn->getColl();
    mongocxx::cursor cursor = coll.aggregate(componentFilter, mongocxx::options::aggregate{});
    for(auto doc : cursor) {
        bsoncxx::document::element ds = doc["datasize"];
        int datasize;
        if(ds.type()==bsoncxx::v_noabi::type::k_int32){
            datasize = ds.get_int32();
        }
        else {
            datasize = ds.get_int64();
        }
        m_datasize = datasize;
    }

}

int Cluster_Core::datasize() {
    return m_datasize;
}

void Cluster_Core::setDatasize(int datasize){
    m_datasize = datasize;
    emit datasizeChanged();
}


void Cluster_Core::timerEvent(QTimerEvent* event){
    //updateDatasize();
    //emit datasizeChanged();
}
