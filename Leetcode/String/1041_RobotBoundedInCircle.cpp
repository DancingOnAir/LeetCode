#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, idx = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (char c : instructions) {
            if (c == 'L') {
                idx = (idx + 3) % 4;
            }
            else if (c == 'R') {
                idx = (idx + 1) % 4;
            }
            else {
                x += d[idx][0];
                y += d[idx][1];
            }
        }

        return (x == 0 && y == 0) || (idx > 0);
    }
};

void testIsRobotBounded() {
    Solution solution;

    assert(solution.isRobotBounded("GGLLGG"));
    assert(!solution.isRobotBounded("GG"));
    assert(solution.isRobotBounded("GL"));
}

int main() {
    testIsRobotBounded();

    return 0;
}