#include "mongodata.h"

#include <QQmlEngine>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

#include "database_connection.h"

MongoData::MongoData(QObject *parent) : QObject(parent)
{
    buildClusterComponents();
    /*using namespace bsoncxx::builder::basic;

    mongocxx::pipeline processornames{};



    mongocxx::pipeline processranks{};
    processranks.group(make_document(
                       kvp("_id", "$processrank"),
                       kvp("processorname", make_document(kvp("$first", "$processorname"))),
                       kvp("datasize", make_document(kvp("$sum", "$datasize")))));

    mongocxx::cursor cursor = coll.aggregate(processranks, mongocxx::options::aggregate{});
    for(auto doc : cursor) {
        bsoncxx::document::element processrank = doc["_id"];
        bsoncxx::document::element processorname = doc["processorname"];

        if(m_nodes.contains(Cluster_Node->getName(), "hallo"))

        std::string s = processorname.get_string().value.to_string();
        m_nodes << new Cluster_Node(nullptr,s);
        std::cout << m_nodes[0]->getName() << "\n";



        //std::cout << bsoncxx::to_json(doc) << "\n";
        //QString s = QString::fromStdString(bsoncxx::to_json(doc));
        //cl_nodes << new QString(s);
        //QString str = QString::fromStdString(bsoncxx::to_json(doc));
        //QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
        //arr.append(jsonDoc);
    }*/
}


//Hier werden nur die einzelnen Nodes herausgesucht und die jeweilige Anzahl an Cores definiert.
void MongoData::buildClusterComponents(){
    Database_Connection *db_conn = new Database_Connection();
    using namespace bsoncxx::builder::basic;
    mongocxx::pipeline componentFilter{};

    componentFilter.group(make_document(
                              kvp("_id", "$node"),
                              kvp("core", make_document(kvp("$addToSet", "$core")))
                              ));

    mongocxx::collection coll = db_conn->getCluster();

    auto start = std::chrono::high_resolution_clock::now();
    mongocxx::cursor cursor = coll.aggregate(componentFilter, mongocxx::options::aggregate{});
    auto stop1 = std::chrono::high_resolution_clock::now();
    for(auto doc : cursor) {
        bsoncxx::document::element processor = doc["_id"];
        bsoncxx::document::element processorranks = doc["core"];
        Cluster_Node* node = new Cluster_Node(nullptr, processor.get_string().value.to_string());
        m_nodes << node;
        //bsoncxx::array::view v = processorranks.get_array().value;

        if(processorranks.type()==bsoncxx::type::k_array){
            bsoncxx::array::view processors{processorranks.get_array().value};
            for (bsoncxx::array::element processor : processors){
                Cluster_Core* core = new Cluster_Core(nullptr, processor.get_int32());
                node->addCore(core);
            }
        }
    }

    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1-start);
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2-start);

    //std::cout << duration1.count() << "\n";
    //std::cout << duration2.count() << "\n";
}

//Destruktor
MongoData::~MongoData()
{
    qDeleteAll(m_nodes);
    m_nodes.clear();
}

int MongoData::count() const
{
    return m_nodes.count();
}

QObject* MongoData::nodeAt(int index)
{
    if(index < 0 || index >= m_nodes.count())
        return 0;

    //QQmlEngine::setObjectOwnership(m_cores[index], QQmlEngine::CppOwnership)

    return m_nodes[index];
}

