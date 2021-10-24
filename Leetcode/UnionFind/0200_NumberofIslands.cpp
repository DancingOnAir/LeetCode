#include <vector>

using namespace std;
class Solution {
private:
    vector<int> parents;

    int find(int idx) {
        if (idx != parents[idx])
            idx = find(parents[idx]);
        return idx;
    }

    void merge(int idx1, int idx2, int& cnt) {
        int p1 = find(idx1);
        int p2 = find(idx2);

        if (p1 == p2) {
            return;
        }

        parents[p1] = p2;
        --cnt;
    }

public:

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row * col; ++i) {
            parents.push_back(i);
        }

        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0')
                    continue;
                
                ++res;
                int idx = i * col + j;
                if (j + 1 < col && grid[i][j + 1] == '1') {
                    merge(idx, idx + 1, res);
                }

                if (i + 1 < row && grid[i + 1][j] == '1') {
                    merge(idx, idx + col, res);
                }
            }
        }

        return res;
    }
};

void testNumIsLands() {
    Solution solution;

    vector<vector<char>> grid1 = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};
    // assert(solution.numIslands(grid1) == 1);

    vector<vector<char>> grid2 = {{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};
    assert(solution.numIslands(grid2) == 3);
}

int main() {
    testNumIsLands();

    return 0;
}