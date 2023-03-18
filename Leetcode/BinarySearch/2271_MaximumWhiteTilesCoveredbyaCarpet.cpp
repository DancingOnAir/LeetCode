#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int res = 0, cover = 0, i = 0, j = 0;
        while (i < tiles.size() && res < carpetLen) {
            if (tiles[j][0] + carpetLen > tiles[i][1]) {
                cover += tiles[i][1] - tiles[i][0] + 1;
                res = max(res, cover);
                ++i;
            }
            else {
                int compensate = max(0, tiles[j][0] + carpetLen - tiles[i][0]);
                res = max(res, cover + compensate);
                cover -= tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
        }

        return res;
    }
};

void testMaximumWhiteTiles() {
    Solution solution;
    vector<vector<int>> tiles {{1,5},{10,11},{12,18},{20,25},{30,32}};
    cout << solution.maximumWhiteTiles(tiles, 10) << endl;
}

int main() {
    testMaximumWhiteTiles();
    return 0;
}