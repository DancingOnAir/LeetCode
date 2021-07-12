#include <string>

using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

void testCheckOnesSegment() {
    Solution solution;

    assert(!solution.checkOnesSegment("1001"));
    assert(solution.checkOnesSegment("110"));
}

int main() {
    testCheckOnesSegment();

    return 0;
}