#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct DirectedGraphNode
{
    int label;
    vector<DirectedGraphNode *> in;
    vector<DirectedGraphNode *> out;
    DirectedGraphNode(int x) : label(x) {}
};

bool topologicalSortUtility(unordered_map<int, unordered_set<int>>& g, int vertex, unordered_set<int>& st, unordered_set<int>& visited)
{
    if (st.find(vertex) != st.end())
        return false;

    if (visited.find(vertex) != visited.end())
        return true;

    visited.insert(vertex);
    st.insert(vertex);

    for (auto& child : g[vertex])
        if (topologicalSortUtility(g, child, st, visited) == false)
            return false;

    st.erase(st.find(vertex));
    return true;
}

bool topologicalSort(unordered_map<int, unordered_set<int>>& g)
{
    unordered_set<int> st, visited;

    for (auto it = g.begin(); it != g.end(); ++it)
    {
        int vertex = it->first;
        topologicalSortUtility(g, vertex, st, visited);
    }

    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    unordered_map<int, unordered_set<int>> g;
    for (auto& p : prerequisites)
    {
        g[p.first].insert(p.second);
    }

    for (int i = 0; i < numCourses; ++i)
        g[i];


    return topologicalSort(g);
}

int main()
{
    system("pause");
    return 0;
}