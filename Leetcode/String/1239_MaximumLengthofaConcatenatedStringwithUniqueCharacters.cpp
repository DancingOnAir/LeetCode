#include <bitset>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto& s : arr) {
            bitset<26> b;
            for (char c : s)
                b.set(c - 'a');

            int n = b.count();
            if (n < s.size())
                continue;

            for (int i = dp.size() - 1; i >= 0; --i) {
                bitset d = dp[i];
                if ((b & d).any())
                    continue;
                    
                dp.push_back(b | d);
                // count(): return the num of bitset set to true
                res = max(res, (int)d.count() + n);
            }
        }

        return res;
    }
};

void testMaxLength() {
    Solution solution;

    vector<string> arr1 = {"un","iq","ue"};
    assert(solution.maxLength(arr1) == 4);

    vector<string> arr2 = {"cha","r","act","ers"};
    assert(solution.maxLength(arr2) == 6);

    vector<string> arr3 = {"abcdefghijklmnopqrstuvwxyz"};
    assert(solution.maxLength(arr3) == 26);
}

int main() {
    testMaxLength();

    return 0;
}