#ifndef AGRAPH
#define AGRAPH

#include <string>
#include <memory>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../jsoncpp/include/json/json.h"

#include "agraph_export.h"

/*
это реализация паттерна type erasure
задача - скрыть объекты разных классов с общим интерфейсом за одним типом данных с тем же самым интерфейсом
решение - поскольку мы не можем менять структуру классов (они могут быть сторонними компонентами),
то мы используем обертку над каждым объектом, делегирующую ему вызовы методов. Все обертки наследуются от
одного класса, определяющего интерфейс.
*/

/*
AGraph - обертка, скрывающая объекты за указателем.
Контейнеры stl хранят объекты по значению, поэтому если размещать в них объекты GraphConcept напрямую,
произойдет срезка. В данном случае она не особо нужна, так как в тестах можно использовать указатели.
*/

class FenwickTree {
private:
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> data;

    FenwickTree(int size);

    void setSize(int size);
    void update(int index, int newVal);

    int lastBit(int x){
        return x & (-x);
    }
public:
    FenwickTree(std::vector<int> data);

    int rmq(int l, int r);

    friend class FenwickTree2D;
};

class FenwickTree2D{
private:
    std::vector<FenwickTree> left;
    std::vector<FenwickTree> right;
    std::vector<FenwickTree> data;

    FenwickTree2D(int width, int height);
    void setSize (int width, int height);
    void update(int x, int y, int newVal);

    int lastBit(int x){
        return x & (-x);
    }

public:
    FenwickTree2D(std::vector<std::vector<int>> data);

    int rmq(int x1, int y1, int x2, int y2);
};






struct TVer{
    int number;
    std::string type;

    bool operator==(const TVer& v){
        if(number == v.number && type == v.type){
            return true;;
        }else
            return false;
    }
};

/* 2sat */
struct Var {
    std::string label;
    bool neg;
    bool used;
    int comp;

    Var() {
        label = "";
        neg = false;
        used = false;
        comp = -1;
    }
    Var(std::string s, bool b) {
        label = s;
        neg = b;
        used = false;
        comp = -1;
    }

    bool operator==(const Var& v){
    if(label == v.label && (neg == v.neg))
        return true;
    else
        return false;
    }

    Var negation(const Var&);
    bool findvar(const std::vector<Var>&, const Var&);
    int findplace(std::vector<Var>&, const Var&);
};

Var negation(const Var& v){
        Var nv = v;
        if(v.neg){
            nv.neg = false;
            return nv;
        }
        nv.neg = true;
        return nv;
    }

bool findvar(const std::vector<Var>& g, const Var& v){
    for(auto it : g){
        if(it == v)
            return true;
    }
    return false;
}

int findplace(std::vector<Var>& g, const Var& v){
    for(int i = 0; i < g.size(); i++){
        if(g[i] == v)
            return i;
    }
    return -1;
}


/* 2sat */


struct TValue {
    int road;
    int railway;
};

template<typename TNode, typename TEdge = int>
class VGraph {
public:
    VGraph() = default;
//    VGraph<TNode, TEdge>(std::vector<std::vector<int>>& e, std::vector<TNode>& v):
//        adjacencies(e),
//        Vertices(v)
//    {}

    VGraph<TNode, TEdge>(const VGraph<TNode, TEdge>&) = default;
    explicit VGraph<TNode, TEdge>(const std::vector<std::pair<int, int> >&, const std::vector<TNode>&);
    explicit VGraph<TNode, TEdge>(const std::vector<std::pair<Var, Var> >&);
    explicit VGraph<TNode, TEdge>(const std::vector<std::pair<std::pair<int, int>, TValue>>&, int, int);

    int findAnyplace(std::vector<TNode>& g, const TNode& v);
    VGraph<TNode, TEdge> transpose();

    void ShortestPath();

    void sat2();

    bool do_algorithm(){
        switch(algnum){
            case 1 : //2sat
                sat2();
                break;
            case 2 : //transport
                ShortestPath();
                break;
            default : std::cout << "ERROR" << std::endl;
        }
    }

protected:
    std::vector< std::vector<std::pair<int, TEdge>> > adjacencies;
    std::vector<TNode> Vertices;
    int source = 0;
    int destination1 = 0;
    int destination2 = 0;
    int algnum;
};


template<typename TNode, typename TEdge>
int VGraph<TNode, TEdge>::findAnyplace(std::vector<TNode>& g, const TNode& v){
    for(int i = 0; i < g.size(); i++){
        if(g[i] == v)
            return i;
    }
    return -1;
}

template<typename TNode, typename TEdge>
VGraph<TNode, TEdge>::VGraph(const std::vector<std::pair<std::pair<int, int>, TValue>>& g, int s, int d){
    adjacencies.resize(g.size() * 2 - 1);
    TVer ver1, ver2, ver3, ver4;
    for(auto it : g){
        if(it.first.first == s){
            ver1.number = s;
            ver1.type = "";
            ver2.number = it.first.second;
            ver2.type = "road";
            ver3.number = it.first.second;
            ver3.type = "railway";
            if(findAnyplace(Vertices, ver1) == -1){
                Vertices.push_back(ver1);
            }
            if(findAnyplace(Vertices, ver2) == -1){
                Vertices.push_back(ver2);
            }
            if(findAnyplace(Vertices, ver3) == -1){
                Vertices.push_back(ver3);
            }
            adjacencies[findAnyplace(Vertices, ver1)].push_back(std::make_pair(findAnyplace(Vertices, ver2), it.second.road));
            adjacencies[findAnyplace(Vertices, ver1)].push_back(std::make_pair(findAnyplace(Vertices, ver3), it.second.railway));
        }else if(it.first.second == s){
            ver1.number = s;
            ver2.number = it.first.first;
            ver3.number = it.first.first;
            ver2.type = "road";
            ver3.type = "railway";
            if(findAnyplace(Vertices, ver1) == -1){
                Vertices.push_back(ver1);
            }
            if(findAnyplace(Vertices, ver2) == -1){
                Vertices.push_back(ver2);
            }
            if(findAnyplace(Vertices, ver3) == -1){
                Vertices.push_back(ver3);
            }
            adjacencies[findAnyplace(Vertices, ver2)].push_back(std::make_pair(findAnyplace(Vertices, ver1), it.second.road));
            adjacencies[findAnyplace(Vertices, ver3)].push_back(std::make_pair(findAnyplace(Vertices, ver1), it.second.railway));
        }else{
            ver1.number = it.first.first;
            ver1.type = "road";
            ver2.number = it.first.first;
            ver2.type = "railway";
            if(findAnyplace(Vertices, ver1) == -1){
                Vertices.push_back(ver1);
            }
            if(findAnyplace(Vertices, ver2) == -1){
                Vertices.push_back(ver2);
            }
            ver3.number = it.first.second;
            ver3.type = "road";
            ver4.number = it.first.second;
            ver4.type = "railway";
            if(findAnyplace(Vertices, ver3) == -1){
                Vertices.push_back(ver3);
            }
            if(findAnyplace(Vertices, ver4) == -1){
                Vertices.push_back(ver4);
            }
            adjacencies[findAnyplace(Vertices, ver1)].push_back(std::make_pair(findAnyplace(Vertices, ver3), 0.8 * it.second.road));
            adjacencies[findAnyplace(Vertices, ver2)].push_back(std::make_pair(findAnyplace(Vertices, ver4), 0.8 * it.second.railway));
            adjacencies[findAnyplace(Vertices, ver1)].push_back(std::make_pair(findAnyplace(Vertices, ver4), it.second.road));
            adjacencies[findAnyplace(Vertices, ver2)].push_back(std::make_pair(findAnyplace(Vertices, ver3), it.second.railway));
        }
    }
    adjacencies.shrink_to_fit();
    source = s;
    TVer verd1, verd2;
    verd1.number = d;
    verd2.number = d;
    verd1.type = "road";
    verd2.type = "railway";
    destination1 = findAnyplace(Vertices, verd1);
    destination2 = findAnyplace(Vertices, verd2);
    algnum = 2;
}

template<typename TNode, typename TEdge>
VGraph<TNode, TEdge>::VGraph(const std::vector<std::pair<Var, Var> >& disj){

    std::vector<TNode> ver;
    std::vector<std::vector<std::pair<int, int>>> edges;
    int i = 0;

    for(auto it : disj){
            ver.push_back(it.first);
            ver.push_back(negation(it.first));
            ver.push_back(it.second);
            ver.push_back(negation(it.second));
        }

    edges.resize(ver.size() + 1);

    for(auto it : disj){
        int j = findplace(ver, negation(it.first));
        int k = findplace(ver, negation(it.second));
        if(j != -1 && k != -1){
            edges[j].push_back({findplace(ver, it.second), 0});
            edges[k].push_back({findplace(ver, it.first), 0});
        }
        else
            std::cout << "Something went wrong! No such ver!" << std::endl;
    }

    adjacencies.resize(ver.size() + 1);

    adjacencies = edges;

    adjacencies.shrink_to_fit();
    Vertices = ver;
    algnum = 1;
}



template<typename TNode, typename TEdge>
VGraph<TNode, TEdge> VGraph<TNode, TEdge>::transpose(){
    VGraph<TNode> gt;
    gt.adjacencies.resize(adjacencies.size());
    for(int i = 0; i < adjacencies.size(); i++){
          for(auto it : adjacencies[i]){
              gt.adjacencies[it.first].push_back({i, it.second});

          }
    }
    return gt;
}

/*Aho*/

struct BorNode{
    int objNum;
    bool isTerm;
    char charToParent;
};

class AhoCorasic : public VGraph<BorNode>{
public:
    AhoCorasic() : sz(26), parent(26), suffLink(27), goodSuffLink(28) {}

    AhoCorasic(std::vector<std::string> objects) : sz(26), parent(26), suffLink(27), goodSuffLink(28) {
        strings = objects;

        superRoot = CreateVertice(0, 0);
        root = CreateVertice(superRoot, 0);

        for (int i = 0; i < sz; i++)
            adjacencies[superRoot][i].first = root;
        adjacencies[superRoot][suffLink].first = superRoot;
        adjacencies[superRoot][goodSuffLink].first = superRoot;
        adjacencies[root][suffLink].first = superRoot;
        adjacencies[root][goodSuffLink].first = superRoot;

        for (int i = 0; i < strings.size(); i++)
            addStringToBor(strings[i], i);

        for (int v = 0; v < Vertices.size(); v++) {
            for (int ch = 0; ch < sz; ch++)
                adjacencies[v][ch].first = go(v, ch);
            adjacencies[v][suffLink].first = getSuffLink(v);
            adjacencies[v][goodSuffLink].first = getGoodSuffLink(v);
        }
    }

    void accept(std::string s) {
        str = s;
    }

    std::vector< std::pair<int, int> > findAllMatches() {

        std::vector<std::pair<int, int> > matches;

        int currNodeIndex = root;
        for (int i = 0; i < str.length(); i++) {
            currNodeIndex = adjacencies[currNodeIndex][str[i] - 'a'].first;

            if (Vertices[currNodeIndex].isTerm) {
                int objNum = Vertices[currNodeIndex].objNum;
                matches.push_back(std::make_pair(i - strings[objNum].length() + 1, strings[objNum].length()));
            }

            int nodeIndex = adjacencies[currNodeIndex][goodSuffLink].first;
            while (nodeIndex != superRoot) {
                int objNum = Vertices[nodeIndex].objNum;
                matches.push_back(std::make_pair(i - strings[objNum].length() + 1, strings[objNum].length()));
                nodeIndex = adjacencies[nodeIndex][goodSuffLink].first;
            }
        }

        return matches;
    }

    bool do_algorithm() {
        std::vector<std::pair<int, int> > matches = findAllMatches();

        std::ofstream fout("ResultAho.txt");
        for (size_t i = 0; i < matches.size(); i++) {
            fout << matches[i].first << ' ' << matches[i].second << std::endl;
        }
    }



private:
    const int sz; //size of alphabet
    const int parent; // adjacencies[v][parent]
    const int suffLink; // adjacencies[v][suffLink]
    const int goodSuffLink; // adjacencies[v][goodSuffLink]
    std::vector<std::string> strings;
    std::string str;
    int root, superRoot;


    int CreateVertice(int p, char ch) {
        BorNode node;
        node.isTerm = false;
        node.charToParent = ch;

        Vertices.push_back(node);
        adjacencies.push_back(std::vector< std::pair<int, int> >(sz + 3, std::make_pair(-1, 0)));

        int newVertexIndex = Vertices.size() - 1;
        adjacencies[newVertexIndex][parent].first = p;
        adjacencies[newVertexIndex][suffLink].first = -1;
        adjacencies[newVertexIndex][goodSuffLink].first = -1;

        return newVertexIndex;
    }

    void addStringToBor(std::string str, int index) {
        int curNodeIndex = root;
        for (size_t i = 0; i < str.size(); i++) {
            int ch = str[i] - 'a';
            if (adjacencies[curNodeIndex][ch].first == -1) {
                int nextNodeIndex = CreateVertice(curNodeIndex, ch);
                adjacencies[curNodeIndex][ch].first = nextNodeIndex;
            }
            curNodeIndex = adjacencies[curNodeIndex][ch].first;
        }
        Vertices[curNodeIndex].isTerm = true;
        Vertices[curNodeIndex].objNum = index;
    }

    int getSuffLink(int v) {
        if(adjacencies[v][suffLink].first == -1){
            int vertexIndex = getSuffLink(adjacencies[v][parent].first);
            int ch = Vertices[v].charToParent;
            adjacencies[v][suffLink].first = go(vertexIndex, ch);
        }
        return adjacencies[v][suffLink].first;
    }

    int getGoodSuffLink(int v){
        if(adjacencies[v][goodSuffLink].first == -1){
            int u = getSuffLink(v);
            adjacencies[v][goodSuffLink].first = (Vertices[u].isTerm) ? u : getGoodSuffLink(u);
        }
        return adjacencies[v][goodSuffLink].first;
    }

    int go(int nodeIndex, int ch) {
        if (adjacencies[nodeIndex][ch].first == -1)
            adjacencies[nodeIndex][ch].first = go(getSuffLink(nodeIndex), ch);
        return adjacencies[nodeIndex][ch].first;
    }
};



/*=======================================================================================*/

class AGraph {

	/* GraphConcept - общий интерфейc обобщенного класса граф */
    struct GraphConcept {
        virtual bool algorithm() = 0;
        virtual ~GraphConcept() {}
    };

	/*
	GraphModel - реализация интерфейса на основе произвольного класса
	При этом от класса требуется не явное соответсвие какому-либо интерфейсу,
	а всего лишь наличие подходящих методов, иногда это называют неявной спецификацией.
	Например, bool algorithm() может вызывать X object.do_algorithm(), если определено
	приведение типа T::operator bool() и т.п.
	*/
    template<typename T>
    struct GraphModel : GraphConcept {
        GraphModel( const T& t ) : object( t ) {}
        virtual bool algorithm() {
            return object.do_algorithm();
        }
        virtual ~GraphModel() {}
    private:
        T object;
    };

	/* вот так можно восстановить объект */
	/*
	template<typename U>
	U cast() const
	{
		if(typeid(U) != object->type_info())
			throw std::runtime_error("Bad graph cast");
		return static_cast<GraphModel<U>* >(object)->object;
	}
	*/

private:
    std::unique_ptr<GraphConcept> object;

public:
    template<typename T>
    AGraph(const T& obj):object( new GraphModel<T>( obj ) ) {}

    bool algorithm() {
        return object->algorithm();
    }
};

/* это паттерн фабричный метод, что-то вроде виртуального конструктора */
/*
атрибут PROJECT_EXPORT явно указывает, что этот интерфейс библиотеки доступен для вызова из другого места.
без него под MSVC приложение не соберется
*/
class AGRAPH_EXPORT GraphFactory {
public:
    /* static AGraph* makeGraph(const std::string&, enum TASK); если без json */
    static AGraph* makeGraph(Json::Value&);

    virtual ~GraphFactory() = 0;
private:
    GraphFactory(){}
};

#endif
