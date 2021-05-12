#include <string>
#include <vector>


using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> cnt(5, 0);
        int frogs = 0;
        int maxFrogs = 0;
        for (char& c : croakOfFrogs) {
            auto idx = string("croak").find(c);
            ++cnt[idx];
            if (idx == 0) {
                maxFrogs = max(maxFrogs, ++frogs);
            }
            else if (idx == 4) {
                --frogs;
            }
            else if (--cnt[idx - 1] < 0) {
                return -1;
            }
        }

        return frogs == 0 ? maxFrogs : -1;
    }
};

void testMinNumberOfFrogs() {
    Solution solution;

    assert(solution.minNumberOfFrogs("croakcroak") == 1);
    assert(solution.minNumberOfFrogs("crcoakroak") == 2);
    assert(solution.minNumberOfFrogs("croakcrook") == -1);
    assert(solution.minNumberOfFrogs("croakcroa") == -1);
}

int main() {
    testMinNumberOfFrogs();

    return 0;
}