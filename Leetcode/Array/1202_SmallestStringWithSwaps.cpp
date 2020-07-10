#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<int> indices;
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;

public:

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

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
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

    string s1 = "dcab";
    vector<vector<int>> pairs1 = {{0, 3},{1, 2}};
    cout << solution.smallestStringWithSwaps(s1, pairs1) << endl;

    string s2 = "dcab";
    vector<vector<int>> pairs2 = {{0, 3},{1, 2}, {0, 2}};
    cout << solution.smallestStringWithSwaps(s2, pairs2) << endl;

    string s3 = "cba";
    vector<vector<int>> pairs3 = {{0, 1},{1, 2}};
    cout << solution.smallestStringWithSwaps(s3, pairs3) << endl;
}

int main() {
    testSmallestStringWithSwaps();

    return 0;
}