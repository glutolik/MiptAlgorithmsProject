
template<typename TNode>
class VGraph {
public:
    struct TValue {
        std::pair<char, int> road;
        std::pair<char, int> railway;
    };

    std::vector<std::vector<std::pair<int, TValue>>> adjacencies;
    std::vector<TNode> vertices;
    VGraph() = default;
    VGraph<TNode>(const VGraph<TNode>&) = default;
    explicit VGraph<TNode>(const std::vector<std::vector<std::pair<int, TValue>>>&);



    std::vector<std::pair<int, char>> ShortestPath(const VGraph<TNode>&, int s);
    std::vector<std::pair<int, char>> RevivePath(const std::vector<std::pair<int, char>> parent, int t, int s);
//    bool AddVertex(const TNode&);
//    bool AddEdge(const TNode&, const TNode&);
//    void dfs1(TNode v);
//    void dfs2(TNode v);
};


#include "Graph.hpp"
