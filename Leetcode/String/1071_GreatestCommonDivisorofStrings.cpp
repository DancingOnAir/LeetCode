#include <string>
#include <algorithm>

using namespace std;
class Solution {
private:
    int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }
        
        while (a % b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return b;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2) == (str2 + str1)? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};

void testGcdOfStrings() {
    Solution solution;

    assert(solution.gcdOfStrings("ABCABC", "ABC") == "ABC");
    assert(solution.gcdOfStrings("ABABAB", "ABAB") == "AB");
    assert(solution.gcdOfStrings("LEET", "CODE") == "");
    assert(solution.gcdOfStrings("ABCDEF", "ABC") == "");
}

int main() {
    testGcdOfStrings();

    return 0;
}