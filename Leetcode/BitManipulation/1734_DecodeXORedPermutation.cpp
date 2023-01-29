#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/decode-xored-permutation/solutions/1031107/java-c-python-straight-forward-solution/
    vector<int> decode(vector<int>& encoded) {
        int first = 0;
        for (int i = 1; i < encoded.size() + 2; ++i) {
            first ^= i;

            if ((i & 1) && i < encoded.size()) {
                first ^= encoded[i];
            }
        }

        vector<int> res {first};
        for (int i = 0; i < encoded.size(); ++i) {
            res.push_back(res.back() ^ encoded[i]);
        }

        return res;
    }
};

void testDecode() {
    Solution solution;

    vector<int> encoded1 {3, 1};
    auto res1 = solution.decode(encoded1);
    for (auto& x : res1) {
        cout << x << ", ";
    }
    cout << endl;

    vector<int> encoded2 {6, 5, 4, 6};
    auto res2 = solution.decode(encoded2);
    for (auto& x : res2) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
    testDecode();
    return 0;
}