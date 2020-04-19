#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        return 0;
    }
};

void testFindMaximumXOR() {
    Solution solution;
    vector<int> nums {3, 10, 5, 25, 2, 8};
    cout << solution.findMaximumXOR(nums) << endl;
}

int main() {
    testFindMaximumXOR();

    return 0;
}