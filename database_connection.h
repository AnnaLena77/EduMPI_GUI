#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/string/to_string.hpp>


class Database_Connection
{
public:
    Database_Connection();
    mongocxx::database getDB() const;
    mongocxx::collection getColl() const;
    mongocxx::collection getCluster() const;
private:
    mongocxx::database m_db;
    mongocxx::collection m_coll;
    mongocxx::collection m_cluster_info_coll;

};

#endif // DATABASE_CONNECTION_H
