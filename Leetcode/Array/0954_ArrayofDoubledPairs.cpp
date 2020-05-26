#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool canReorderDoubled(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> m;
        
        for (int a : A) {
            m[a]++;
        }

        sort(A.begin(), A.end());
        int delimiter = 0;
        while (delimiter < n && A[delimiter] < 0) {
            ++delimiter;
        }

        int count = 0;
        for (int i = delimiter - 1; i >= 0 && count < delimiter / 2; --i) {
            if (m.count(A[i]) && m.count(A[i] * 2)) {
                if (--m[A[i]] < 0 || --m[A[i] * 2] < 0)
                    return false;
            }
            else {
                return false;
            }

            ++count;
        }

        count = 0;
        for (int i = delimiter; i < n && count < (n - delimiter) / 2; ++i) {
            if (m.count(A[i]) && m.count(A[i] * 2)) {
                if (--m[A[i]] < 0 || --m[A[i] * 2] < 0)
                    return false;
            }
            else {
                return false;
            }

            ++count;
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
}

int main() {
    testCanReorderDoubled();

    return 0;
}