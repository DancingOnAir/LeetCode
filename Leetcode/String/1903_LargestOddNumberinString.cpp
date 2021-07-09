#include <string>

using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        return num.substr(0, num.find_last_of("13579") + 1);
    }
};

void testLargestOddNumber() {
    Solution solution;
    
    string s = "12345";
    printf("%s\n", s.substr(0, 0).c_str());
    assert(solution.largestOddNumber("52") == "5");
    assert(solution.largestOddNumber("4206") == "");
    assert(solution.largestOddNumber("35427") == "35427");
}

int main() {
    testLargestOddNumber();

    return 0;
}