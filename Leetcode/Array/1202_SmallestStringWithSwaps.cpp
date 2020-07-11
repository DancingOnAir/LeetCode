#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> indices;
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;

public:
    int find(vector<int>& ds, int x) {
        if (ds[x] == -1)
            return x;

        return ds[x] = find(ds, ds[x]);
    }

    void merge(vector<int>& ds, int x, int y) {
        int i = find(ds, x);
        int j = find(ds, y);

        if (i != j)
            ds[j] = i;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> ds(s.size(), -1);

        for (auto& p : pairs) {
            int i = find(ds, p[0]);
            int j = find(ds, p[1]);

            if (i != j)
                merge(ds, i, j);
        }

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < s.size(); ++i) {
            m[find(ds, i)].push_back(i);
        }

        for (auto& iter : m) {
            string str = "";
            int j = 0;

            for (auto i : iter.second) {
                str += s[i];
            }

            sort(str.begin(), str.end());
            for (auto i : iter.second) {
                s[i] = str[j++];
            }
        }

        return s;
    }

    void dfs(string& s, int i) {
        visited[i] = true;
        indices.emplace_back(i);
        indiceString += s[i];

        for (int j : adjList[i]) {
            if (!visited[j]) {
                dfs(s, j);
            }
        }
    }

    string smallestStringWithSwaps1(string s, vector<vector<int>>& pairs) {
        adjList.resize(s.size());
        visited.resize(s.size(), false);

        for (auto& p : pairs) {
            adjList[p[0]].emplace_back(p[1]);
            adjList[p[1]].emplace_back(p[0]);
        }

        for (int i = 0; i < s.size(); ++i) {
            if (!visited[i]) {
                indiceString = "";
                indices.clear();

                dfs(s, i);

                sort(indiceString.begin(), indiceString.end());
                sort(indices.begin(), indices.end());

                for (int j = 0; j < indices.size(); ++j) {
                    s[indices[j]] = indiceString[j];
                }
            }
        }

        return s;
    }
};

void testSmallestStringWithSwaps() {
    Solution solution;

    // string s1 = "dcab";
    // vector<vector<int>> pairs1 = {{0, 3},{1, 2}};
    // cout << solution.smallestStringWithSwaps(s1, pairs1) << endl;

    // string s2 = "dcab";
    // vector<vector<int>> pairs2 = {{0, 3},{1, 2}, {0, 2}};
    // cout << solution.smallestStringWithSwaps(s2, pairs2) << endl;

    // string s3 = "cba";
    // vector<vector<int>> pairs3 = {{0, 1},{1, 2}};
    // cout << solution.smallestStringWithSwaps(s3, pairs3) << endl;

    string s4 = "dcabheaf";
    vector<vector<int>> pairs4 = {{0, 3},{1, 2}, {0, 2}};
    cout << solution.smallestStringWithSwaps(s4, pairs4) << endl;
}

int main() {
    testSmallestStringWithSwaps();

    return 0;
}