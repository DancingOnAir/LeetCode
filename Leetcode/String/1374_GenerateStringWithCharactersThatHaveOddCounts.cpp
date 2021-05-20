#include <string>

using namespace std;
class Solution {
public:
    string generateTheString(int n) {
        return string(n - 1, 'a'+ n % 2) + "b";
    }
};

void testGenerateTheString() {
    Solution solutino;
    assert(solutino.generateTheString(4) == "aaab");
    assert(solutino.generateTheString(2) == "ab");
    assert(solutino.generateTheString(7) == "bbbbbbb");
}

int main() {
    testGenerateTheString();

    return 0;
}