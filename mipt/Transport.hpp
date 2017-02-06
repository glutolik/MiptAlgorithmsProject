const int INF = 1000000000;
template<typename TNode>
VGraph<TNode>::VGraph(const std::vector<std::vector<std::pair<int, TValue>>>& g){
    adjacencies = g;
    std::vector<TNode> gv;
    vertices = gv;
}
template<typename TNode>
std::vector<std::pair<int, char>> VGraph<TNode>::ShortestPath(const VGraph<TNode>& g, int s){
    int n = g.adjacencies.size();
    int len;
    char lastPath;
	std::vector<int> dist(n, INF);
	std::vector<std::pair<int, char>> parent(n);
	dist[s] = 0;
	std::vector<bool> used(n, false);
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || dist[j] < dist[v]))
				v = j;
		if (dist[v] == INF)
			break;
		used[v] = true;

		for (size_t j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first;
			if(lastPath == g[v][j].second.road.first){
				len = min(0.8*g[v][j].second.road.second, g[v][j].second.railway.second);
				lastPath = 0.8*g[v][j].second.road.second < g[v][j].second.railway.second ? g[v][j].second.road.first : g[v][j].second.railway.first;
			}
			else{
                len = min(g[v][j].second.road.second, 0.8*g[v][j].second.railway.second);
				lastPath = g[v][j].second.road.second < 0.8*g[v][j].second.railway.second ? g[v][j].second.road.first : g[v][j].second.railway.first;
			}
			if (dist[v] + len < dist[to]) {
				dist[to] = dist[v] + len;
				parent[to] = std::make_pair(v, lastPath);
			}
		}
	}
	return parent;
}

std::vector<std::pair<int, char>> RevivePath(const std::vector<std::pair<int, char>> parent, int t, int s){
    std::vector<std::pair<int, char>> path;
    char type;
    for (int v = t; v != s; v = parent[v].first){
        path.push_back(std::make_pair(v, parent[v].second));
        type = parent[v].second;
    }
    path.push_back(std::make_pair(s, type));
    std::reverse(path.begin(), path.end());
    return path;
}
