#include <vector>
#include "jsoncpp/include/json/json.h"
#include "agraph/agraph.h"

#include "catch.hpp"

#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

/*SCENARIO("scenario1"){
    std::ifstream ifs;
    Json::Value root;
    Json::Reader reader;

    ifs.open("../mipt/2sat.json", std::ifstream::in);
    bool res = reader.parse(ifs, root);
    REQUIRE( res != false );

    cout << "pairs:" << endl;

    Json::Value g = root["2sat"];
    for(unsigned int i = 0; i < g.size(); ++i){
        cout << g[i][0].asString() << " : " << g[i][1].asString() << endl;
    }

}*/

//SCENARIO("scenario1"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/2sat0.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//    /* тестируем со страшной силой */
//
///*  Json::Value r = root["graphs"][0]["graph"];
//    cout << "nodes:" << endl;
//    for (auto& n : r["nodes"]) {
//        cout << n["id"].asString() << " : " << n["label"].asString() << endl;
//    }
//
//    cout << "edges:" << endl;
//    for (auto& e : r["edges"]) {
//        cout << e["source"].asString() << " -> " << e["target"].asString() << endl;
//    }*/
//}
//
//SCENARIO("scenario2"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/2sat1.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//}
//
//SCENARIO("scenario3"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/2sat2.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//}
//
//SCENARIO("scenario4"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/2sat3.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//    std::cout << std::endl << "++++++++++++++++++++++++++++++++++++" << std::endl;
//
//}
//
//
//SCENARIO("scenario5"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/transport0.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//}
//
//SCENARIO("scenario6"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/transport1.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//}
//
//SCENARIO("scenario7"){
//    std::ifstream ifs;
//    Json::Value root;
//    Json::Reader reader;
//
//    ifs.open("/home/glutolik/mipt/transport2.json", std::ifstream::in);
//    bool res = reader.parse(ifs, root);
//    REQUIRE( res != false );
//    //throw "BABABBAD";
//
//    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
//    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
//    g->algorithm();
//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
//    std::cout << std::endl << "++++++++++++++++++++++++++++++++++++" << std::endl;
//}

SCENARIO("scenario8"){
    std::ifstream ifs;
    Json::Value root;
    Json::Reader reader;

    ifs.open("/home/glutolik/mipt/Aho0.json", std::ifstream::in);
    bool res = reader.parse(ifs, root);
    REQUIRE( res != false );
    //throw "BABABBAD";

    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
    g->algorithm();

    std::string s;
    std::ifstream fin("ResultAho.txt");

    Json::Value ans = root["algorithm"]["RightAnswer"];

    int i = 0;
    int pos;
    int length;
    while (fin >> pos) {
        fin >> length;
        REQUIRE(ans[i]["match"]["pos"] == pos);
        REQUIRE(ans[i]["match"]["length"] == length);
        i++;
    }

    fin.close();


//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
}

SCENARIO("scenario9"){
    std::ifstream ifs;
    Json::Value root;
    Json::Reader reader;

    ifs.open("/home/glutolik/mipt/Aho1.json", std::ifstream::in);
    bool res = reader.parse(ifs, root);
    REQUIRE( res != false );
    //throw "BABABBAD";

    /* создаем граф, подходящий под алгоритм (тип алгоритма описан в json) */
    std::unique_ptr<AGraph> g(GraphFactory::makeGraph(root));
    g->algorithm();

    std::string s;
    std::ifstream fin("ResultAho.txt");

    Json::Value ans = root["algorithm"]["RightAnswer"];

    int i = 0;
    int pos;
    int length;
    while (fin >> pos) {
        fin >> length;
        REQUIRE(ans[i]["match"]["pos"] == pos);
        REQUIRE(ans[i]["match"]["length"] == length);
        i++;
    }

    fin.close();


//    std::string answer = root["algorithm"]["RightAnswer"].asString();
//    std::cout << "<=>" << answer << std::endl;
//    std::cout << "====================================" << std::endl;
}

SCENARIO("scenario10"){
    std::ifstream ifs;
    Json::Value root;
    Json::Reader reader;

    ifs.open("/home/glutolik/mipt/Fenwick0.json", std::ifstream::in);
    bool res = reader.parse(ifs, root);
    REQUIRE( res != false );
    //throw "BABABBAD";
    Json::Value g = root["algorithm"]["array"];
    std::vector<std::vector<int>> data(root["algorithm"]["xdim"].asInt());
    for(int i = 0; i < data.size(); i++){
        data[i] = std::vector<int>(root["algorithm"]["ydim"].asInt());
        for(int j = 0; j < data[i].size(); j++){
            data[i][j] = g[i][j]["num"].asInt();
            //std::cout << data[i][j];
        }
        std::cout << std::endl;
    }
    g = root["algorithm"]["queries"];
    int x1, y1, x2, y2;
    FenwickTree2D tree(data);
    for(int i = 0; i < root["algorithm"]["numberOfQueries"].asInt(); i++){
        x1 = g[i]["first"]["x1"].asInt();
        y1 = g[i]["first"]["y1"].asInt();
        x2 = g[i]["second"]["x2"].asInt();
        y2 = g[i]["second"]["y2"].asInt();

        REQUIRE(tree.rmq(x1, y1, x2, y2) == root["algorithm"]["RightAnswers"][i]["ans"].asInt());
    }
}

/*
SCENARIO("scenario3", "[tag1][tag2]"){
    GIVEN("vector"){
        std::vector<int> v( 5 );

        WHEN( "the size is increased" ) {
            v.resize( 10 );
            THEN( "the size and capacity change" ) {
                REQUIRE( v.size() == 10 );
                REQUIRE( v.capacity() >= 10 );
            }
        }
        WHEN( "nothing happened" ) {
            REQUIRE( v.size() != 5 ); //неправильная проверка
        }
    }
}*/
//макс число, такое что минимум на отрезке [l, newR] известен
