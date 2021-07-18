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
    assert(solution.minPartitions("32") == 3);
    assert(solution.minPartitions("32") == 3);
}

int main() {
    testMinPartitions();

    return 0;
}