#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n & 1) {
            res.emplace_back(0);
            --n;
        }

        int i = 1;
        while (n) {
            res.emplace_back(i);
            res.emplace_back(-i);
            
            ++i;
            n -= 2;
        }

        return res;
    }
};

void printNums(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testSumZero() {
    Solution solution;

    auto res1 = solution.sumZero(5);
    printNums(res1);

    auto res2 = solution.sumZero(3);
    printNums(res2);

    auto res3 = solution.sumZero(1);
    printNums(res3);
}

int main() {
    testSumZero();

    return 0;
}