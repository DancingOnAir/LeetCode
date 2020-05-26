#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> m;
        for (int a : A) {
            m[a]++;
        }

        vector<int> keys;
        for (auto iter : m) {
            keys.emplace_back(iter.first);
        }

        sort(keys.begin(), keys.end(), [](int a, int b) { return abs(a) < abs(b); });
        for (int x : keys) {
            if (m[x] > m[2 * x])
                return false;
            m[2 * x] -= m[x];
        }

        return true;
    }

    bool canReorderDoubled1(vector<int>& A) {
        map<int, int> m;
        for (int a : A) {
            m[abs(a)]++;
        }

        auto iter = m.begin();
        while (iter != m.end()) {
            if (iter->second > 0) {
                if (!m.count(iter->first * 2) || m[iter->first * 2] <= 0)
                    return false;

                --iter->second;
                --m[iter->first * 2];
            }
            else {
                ++iter;
            }
        }

        return true;
    }
};

void testCanReorderDoubled() {
    Solution solution;

    vector<int> A1 {3, 1, 3, 6};
    cout << (solution.canReorderDoubled(A1)? "True" : "False") << endl;

    vector<int> A2 {2, 1, 2, 6};
    cout << (solution.canReorderDoubled(A2)? "True" : "False") << endl;

    vector<int> A3 {4, -2, 2, -4};
    cout << (solution.canReorderDoubled(A3)? "True" : "False") << endl;

    vector<int> A4 {1, 2, 4, 16, 8, 4};
    cout << (solution.canReorderDoubled(A4)? "True" : "False") << endl;

    vector<int> A5 {1, 2, 4, 8};
    cout << (solution.canReorderDoubled(A5)? "True" : "False") << endl;
}

int main() {
    testCanReorderDoubled();

    return 0;
}