#include "agraph.h"
#include <limits>


#include <iostream>
#include "../jsoncpp/include/json/json.h"
const int INF = std::numeric_limits<int>::max();

FenwickTree::FenwickTree(int size){
    setSize(size);
}

FenwickTree::FenwickTree(std::vector<int> arr){
    setSize(arr.size());

    for(int i = 0; i < arr.size(); i++){
        update(i + 1, arr[i]);
    }
}

void FenwickTree::setSize(int size){
    int  newSize = 1;
    while(newSize <= size){
        newSize = newSize << 1;
    }
    left = std::vector<int>(newSize, INF);
    right = std::vector<int>(newSize, INF);
    data = std::vector<int>(newSize, INF);
}

void FenwickTree::update(int index, int newVal){
    data[index - 1] = newVal;
    for(int i = index; i <= data.size(); i += lastBit(i)){
        left[i] = std::min(left[i], newVal);
    }

    for(int j = index - 1; j > 0; j -= lastBit(j)){
        right[j] = std::min(right[j], newVal);
    }
}

int FenwickTree::rmq(int l, int r){
    int ans = data[l -1];
    int newR = l;
    while(newR + lastBit(newR) <= r){
        ans = std::min(ans, right[newR]);
        newR = newR + lastBit(newR);
    }

    int newL = r;
    while(newL > newR){
        ans = std::min(ans, left[newL]);
        newL = newL - lastBit(newL);
    }

    return ans;
}

void FenwickTree2D::update(int x, int y, int newVal){
    data[x-1].update(y, newVal);
    for(int i = x; i < data.size(); i += lastBit(i)){
        left[i].update(y, newVal);
    }

    for(int j = x - 1; j > 0; j -= lastBit(j)){
        right[j].update(y, newVal);
    }
}

FenwickTree2D::FenwickTree2D(std::vector<std::vector<int>> arr){
    setSize(arr.size(), arr[0].size());

    std::vector<std::pair<int, std::pair<int, int>>> elems;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            data[i].update(j + 1, arr[i][j]);
            elems.push_back(std::make_pair(arr[i][j], std::make_pair(i + 1, j + 1)));
        }
    }
    std::sort(elems.begin(), elems.end());
    for(int i = elems.size(); i > 0; i--){
        update(elems[i-1].second.first, elems[i-1].second.second, elems[i-1].first);
    }
}

FenwickTree2D::FenwickTree2D(int width, int height){
    setSize(width, height);
}

void FenwickTree2D::setSize(int width, int height){
    int newWidth = 1;
    int newHeight = 1;
    while(newWidth <= width){
        newWidth = newWidth << 1;
    }
    while(newHeight <= height){
        newHeight = newHeight << 1;
    }

    left = std::vector<FenwickTree>(newWidth, FenwickTree(newHeight));
    right = std::vector<FenwickTree>(newWidth, FenwickTree(newHeight));
    data = std::vector<FenwickTree>(newWidth, FenwickTree(newHeight));
}

int FenwickTree2D::rmq(int x1, int y1, int x2, int y2){
    int ans = data[x1 - 1].rmq(y1, y2);
    int newR = x1;
    while(newR + lastBit(newR) <= x2){
        ans = std::min(ans, right[newR].rmq(y1, y2));
        newR = newR + lastBit(newR);
    }

    int newL = x2;
    while(newL > newR){
        ans = std::min(ans, left[newL].rmq(y1, y2));
        newL = newL - lastBit(newL);
    }

    return ans;
}




void dfs1 (int v, std::vector<Var>& Vertices, const std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& order){
	Vertices[v].used = true;
	for (size_t i = 0; i < g[v].size(); ++i){
		int to = g[v][i].first;
		if (!Vertices[to].used)
			dfs1(to, Vertices, g, order);
	}
	order.push_back(v);
}

void dfs2 (int v, int cl, std::vector<Var>& Vertices, const std::vector<std::vector<std::pair<int, int>>>& gt) {
	Vertices[v].comp = cl;
	for (size_t i = 0; i < gt[v].size(); ++i) {
		int to = gt[v][i].first;
		if (Vertices[to].comp == -1)
			dfs2(to, cl, Vertices, gt);
	}
}

template<typename TNode, typename TEdge>
void VGraph<TNode, TEdge>::sat2(){
    std::cout << std::endl;
}

template<>
void VGraph<Var>::sat2(){

    std::vector<int> order;
    VGraph<Var> gt = transpose();
	int n = Vertices.size();
	for (int i = 0; i < n; ++i){
		if (!Vertices[i].used)
			dfs1(i, Vertices, adjacencies, order);
	}

	for (int i = 0, j = 0; i < n; ++i) {
		int v = order[n - i - 1];
		if (Vertices[v].comp == -1)
			dfs2(v, j++, Vertices, gt.adjacencies);
	}

	for (int i=0; i<n; ++i){
        int j = findplace(Vertices, negation(Vertices[i]));
		if (Vertices[i].comp == Vertices[j].comp) {
			std::cout << "NO SOLUTION!" << std::endl;
			return;
		}
	}
    std::cout << "THERE IS 1 OR MORE SOLUTIONS!" << std::endl;
//    for (int i=0; i<n; ++i) {
//		int ans = comp[i] > comp[i^1] ? i : i^1;
//		std::cout << ans << std::endl;
//	}

}
/////////////////////////////////////////////////////////////////
template<typename TNode, typename TEdge>
void VGraph<TNode, TEdge>::ShortestPath(){
    std::cout << std::endl;
}

template<>
void VGraph<TVer,double>::ShortestPath(){
    int n = adjacencies.size();
    double len;
	std::vector<double> dist(n, INF);
	std::vector<int> parent(n);
	dist[source] = 0;
	std::vector<bool> used(n, false);
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || dist[j] < dist[v])){
				v = j;
            }
		if (dist[v] == INF)
			break;
		used[v] = true;
		for (size_t j = 0; j < adjacencies[v].size(); ++j) {
			int to = adjacencies[v][j].first;
			len = adjacencies[v][j].second;
			if (dist[v] + len < dist[to]) {
				dist[to] = dist[v] + len;
				parent[to] = v;
			}
		}
	}
	double destination;
	destination = dist[destination1] < dist[destination2] ? destination1 : destination2;
	std::vector<int> path;
    for (int v = destination; v != source; v = parent[v]){
        path.push_back(v);
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    for(int l = 0; l < path.size(); l++){
        std::cout << Vertices[path[l]].number << " " <<  Vertices[path[l]].type << std::endl;
    }
    std::cout << dist[destination] << std::endl;
}

/* ваша реализация фабричного метода */
AGraph* GraphFactory::makeGraph(Json::Value &root){
    std::string AlgName = root["algorithm"]["type"].asString();
    if(AlgName == "2sat"){
        Json::Value g = root["algorithm"]["2sat"];

        std::vector<std::pair<Var, Var>> disj;

        for(int i = 0; i < g.size(); ++i){
            Var var1, var2;

            var1.label = g[i]["first"]["label"].asString();
            var1.neg = g[i]["first"]["neg"].asBool();

            var2.label = g[i]["second"]["label"].asString();
            var2.neg = g[i]["second"]["neg"].asBool();

            disj.push_back(std::make_pair(var1, var2));
        }

        //sat2(edges);


        return new AGraph( VGraph<Var>(disj) );
    }
    else if(AlgName == "transport"){
        Json::Value g = root["algorithm"]["graph"];

        std::vector<std::pair<std::pair<int, int>, TValue>> edges;
        TValue value;

        for(int i = 0; i < g.size(); i++){
            value.road = g[i]["value"]["road"].asInt();

            value.railway = g[i]["value"]["railway"].asInt();

            edges.push_back(std::make_pair(std::make_pair(g[i]["edge"]["source"].asInt(), g[i]["edge"]["destination"].asInt()), value));
        }
        return new AGraph( VGraph<TVer, double>(edges, root["algorithm"]["source"].asInt(), root["algorithm"]["destination"].asInt()) );
    }
    else if(AlgName == "Aho"){
        Json::Value g = root["algorithm"]["objects"];

        std::vector<std::string> objects;
        std::string s = root["algorithm"]["string"].asString();

        for(int i = 0; i < g.size(); i++){
            objects.push_back(g[i]["str"].asString());
        }

        AhoCorasic ac(objects);
        ac.accept(s);
        return new AGraph(ac);
    }
    else{
        std::cout << "Nothing" << std::endl;
        exit(0);
    }

}
