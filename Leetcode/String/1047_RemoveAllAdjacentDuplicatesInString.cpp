#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c : s) {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }

        return res;
    }
};

void testRemoveDuplicates() {
    Solution solution;

    assert(solution.removeDuplicates("abbaca") == "ca");
    assert(solution.removeDuplicates("azxxzy") == "ay");
}

int main() {
    testRemoveDuplicates();

    return 0;
}