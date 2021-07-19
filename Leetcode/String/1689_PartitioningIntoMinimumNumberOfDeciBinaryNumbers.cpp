#include <string>
#include <algorithm>

using namespace  std;
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};

void testMinPartitions() {
    Solution solution;

    assert(solution.minPartitions("32") == 3);
    assert(solution.minPartitions("82734") == 8);
    assert(solution.minPartitions("27346209830709182346") == 9);
}

int main() {
    testMinPartitions();

    return 0;
}