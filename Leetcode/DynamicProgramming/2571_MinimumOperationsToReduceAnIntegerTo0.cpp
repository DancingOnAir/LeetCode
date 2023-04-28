#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int dfs(int x) {
        if ((x & (x - 1)) == 0) {
            return 1;
        }

        int lowbit = (x & -x);
        return 1 + min(dfs(x + lowbit), dfs(x - lowbit));
    }

    int minOperations(int n) {
        return dfs(n);
    }
};

void testMinOperations() {
    Solution solution;
    cout << solution.minOperations(39) << endl;
    cout << solution.minOperations(54) << endl;
}

int main() {
    testMinOperations();
    return 0;
}