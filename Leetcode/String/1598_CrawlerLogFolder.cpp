#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (auto& log : logs) {
            if (log == "../") {
                res = max(0, res - 1);
            }
            else if (log == "./") {
                continue;
            }
            else {
                ++res;
            }
        }

        return res;
    }
};

void testMinOperations() {
    Solution solution;

    vector<string> logs1{"d1/","d2/","../","d21/","./"};
    assert(solution.minOperations(logs1) == 2);

    vector<string> logs2{"d1/","d2/","./","d3/","../","d31/"};
    assert(solution.minOperations(logs2) == 3);

    vector<string> logs3{"d1/","../","../","../"};
    assert(solution.minOperations(logs3) == 0);
}

int main() {
    testMinOperations();

    return 0;
}
