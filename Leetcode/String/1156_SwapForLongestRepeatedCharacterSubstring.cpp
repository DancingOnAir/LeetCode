#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxRepOpt1(string text) {
        int res = 0;
        for (auto c = 'a'; c <= 'z'; ++c) {
            int i = 0, j = 0, gap = 0;
            while (i < text.size()) {
                gap += text[i++] != c;
                if (gap > 1)
                    gap -= text[j++] != c;
            }

            res = max(res, min(i - j, (int)count_if(text.begin(), text.end(), [&](char c1){ return c1 == c; })));
        }

        return res;
    }
};

void testMaxRepOpt1() {
    Solution solution;

    assert(solution.maxRepOpt1("ababa") == 3);
    assert(solution.maxRepOpt1("aaabaaa") == 6);
    assert(solution.maxRepOpt1("aaabbaaa") == 4);
    assert(solution.maxRepOpt1("aaaaa") == 5);
    assert(solution.maxRepOpt1("abcdef") == 1);
}

int main() {
    testMaxRepOpt1();

    return 0;
}