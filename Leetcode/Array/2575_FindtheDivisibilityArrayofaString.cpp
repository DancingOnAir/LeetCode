#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        for (long long i = 0, mod = 0; i < word.size(); ++i) {
            mod = (mod * 10 + (word[i] - '0')) % m;
            res.push_back(mod == 0);
        }
        return res;
    }
};

void print(vector<int>& nums) {
    if (nums.empty())
        return;

    for (auto x: nums) {
        cout << x  << ", ";
    }
    cout << endl;
}

void testDivisibilityArray() {
    Solution solution;
    auto res1 = solution.divisibilityArray("998244353", 3);
    print(res1);
    auto res2 = solution.divisibilityArray("1010", 10);
    print(res2);
}

int main() {
    testDivisibilityArray();
    return 0;
}
