#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

class DisjointSet {
private:
    vector<int> parents;
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; ++i) {
            parents.emplace_back(i);
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            return parents[x] = find(parents[x]);
        }

        return x;
    }

    void merge(int x, int y) {
        parents[find(y)] = find(x);
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DisjointSet ds(m * n);
        for (int i = 0; i < m; ++i) {
            int j = 0;
            while (j < n && grid[i][j] == 0) {
                ++j;
            }

            for (int k = j + 1; k < n; ++k) {
                if (grid[i][k]) {
                    ds.merge(i * n + j, i * n + k);
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int i = 0;
            while (i < m && grid[i][j] == 0) {
                ++i;
            }

            for (int k = i + 1; k < m; ++k) {
                if (grid[k][j]) {
                    ds.merge(i * n + j, k * n + j);
                }
            }
        }

        unordered_map<int, int> count;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && ds.find(i * n + j) != i * n + j) {
                    count[ds.find(i * n + j)]++;
                }
            }
        }

        int res = 0;
        for (auto& iter : count) {
            res += iter.second + 1;
        }

        return res;
    }

    int countServers1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows(m);
        vector<int> cols(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && (rows[i] > 1 || cols[j] > 1)) {
                    ++res;
                }
            }
        }
        return res;
    }

    int countServers2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, vector<int>> counts;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    counts[j].emplace_back(i);
                    ++res;
                }
            }
        }

        for (auto& iter : counts) {
            if (iter.second.size() == 1) {
                vector<int> tempRow = grid[iter.second[0]];
                if (count(tempRow.begin(), tempRow.end(), 1) == 1) {
                    --res;
                } 
            }
        }
        return res;
    }
};

void testCountServers() {
    Solution solution;

    vector<vector<int>> grid1 = {{1, 0},{0, 1}};
    cout << solution.countServers(grid1) << endl;

    vector<vector<int>> grid2 = {{1, 0},{1, 1}};
    cout << solution.countServers(grid2) << endl;

    vector<vector<int>> grid3 = {{1, 1, 0, 0},{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 0, 1}};
    cout << solution.countServers(grid3) << endl;

    vector<vector<int>> grid4 = {{0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 1, 0},
                                {0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0, 1, 0, 0}};
    cout << solution.countServers(grid4) << endl;
}

int main() {
    testCountServers();

    return 0;
}