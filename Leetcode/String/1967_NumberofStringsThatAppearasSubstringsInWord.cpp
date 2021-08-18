#include <string>
#include <algorithm>
#include <vector>


using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        return count_if(patterns.begin(), patterns.end(), [&](const auto& p){ return word.find(p) != string::npos; });
    }
};

void testNumOfStrings() {
    Solution solution;

    vector<string> p1{"a","abc","bc","d"};
    assert(solution.numOfStrings(p1, "abc") == 3);

    vector<string> p2{"a","b","c"};
    assert(solution.numOfStrings(p2, "aaaaabbbbb") == 2);

    vector<string> p3{"a","a","a"};
    assert(solution.numOfStrings(p3, "ab") == 3);
}

int main() {
    testNumOfStrings();

    return 0;
}