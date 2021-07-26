#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, maxCost = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] != s[i - 1])
                maxCost = 0;
            res += min(maxCost, cost[i]);
            maxCost = max(maxCost, cost[i]);
        }

        return res;
    }
};

void testMinCost() {
    Solution solution;

    vector<int> cost1{1, 2, 3, 4, 5};
    assert(solution.minCost("abaac", cost1) == 3);

    vector<int> cost2{1, 2, 3};
    assert(solution.minCost("abc", cost2) == 0);

    vector<int> cost3{1, 2, 3, 4, 1};
    assert(solution.minCost("aabaa", cost3) == 2);
}

int main() {
    testMinCost();

    return 0;
}