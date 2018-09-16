#include <iostream>
#include <vector>
#include <unordered_map>

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return node;
    if (mp.find(node) == mp.end()) {
        mp[node] = new UndirectedGraphNode(node->label);
        for (auto x : node->neighbors) {
            (mp[node]->neighbors).push_back(cloneGraph(x));
        }
    }
    return mp[node];
}

void testCloneGraph()
{
    UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);

    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);

    UndirectedGraphNode *result = cloneGraph(node0);
    std::cout << result->label << std::endl;
}

int main()
{
    testCloneGraph();
    system("pause");
    return 0;
}