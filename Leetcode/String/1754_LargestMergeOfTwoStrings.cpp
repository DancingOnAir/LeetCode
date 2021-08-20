#include <string>

using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;

        while (!word1.empty() && !word2.empty()) {
            if (word1 >= word2) {
                res += word1[0];
                word1 = word1.substr(1);
            }
            else {
                res += word2[0];
                word2 = word2.substr(1);
            }
        }

        return res + word1 + word2;
    }
};

void testLargestMerge() {
    Solution solution;

    assert(solution.largestMerge("cabaa", "bcaaa") == "cbcabaaaaa");
    assert(solution.largestMerge("abcabc", "abdcaba") == "abdcabcabcaba");
}

int main() {
    testLargestMerge();

    return 0;
}