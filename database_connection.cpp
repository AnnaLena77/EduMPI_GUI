#include "database_connection.h"

mongocxx::instance instance{};
mongocxx::uri uri("mongodb://10.35.8.10:27017");
//mongocxx::uri uri("mongodb://localhost:27017");
mongocxx::client conn(uri);

Database_Connection::Database_Connection()
{
    this->m_db = conn["DataFromMPI"];
    this->m_coll = this->m_db["MPI_Information"];
    this->m_cluster_info_coll = this->m_db["Cluster_Information"];
}

mongocxx::database Database_Connection::getDB () const{
    return this->m_db;
}

mongocxx::collection Database_Connection::getColl () const{
    return this->m_coll;
}

mongocxx::collection Database_Connection::getCluster() const{
    return this->m_cluster_info_coll;
}
