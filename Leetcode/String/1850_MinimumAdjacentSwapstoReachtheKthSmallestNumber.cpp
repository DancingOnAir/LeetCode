#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    // int countSwapSteps(const string& s1, const string& s2) {
    //     int n = s1.size();
    //     int i = 0, j = 0;
    //     int res = 0;
    //     while (i < n) {
    //         j = i;
    //         while (s1[j] != s1[i])
    //             ++j;
    //         while (i < j) {
    //             std::swap(s1[i], s1[j - 1]);
    //             --j;
    //             ++res;
    //         }

    //         ++i;
    //     }

    //     return res;
    // }

    int getMinSwaps(string num, int k) {
        string target(num);
        while (k--)
            next_permutation(target.begin(), target.end());

        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (target[i] != num[i]) {
                int j = i + 1;
                while (target[i] != num[j]) {
                    ++j;
                }

                while (i < j) {
                    swap(num[j], num[j - 1]);
                    --j;
                    ++res;
                }
            }
        }

        return res;
    }
};

void testGetMinSwaps() {
    Solution solution;
    assert(solution.getMinSwaps("5489355142", 4) == 2);
    assert(solution.getMinSwaps("11112", 4) == 4);
    assert(solution.getMinSwaps("00123", 1) == 1);
}

int main() {
    testGetMinSwaps();

    return 0;
}

