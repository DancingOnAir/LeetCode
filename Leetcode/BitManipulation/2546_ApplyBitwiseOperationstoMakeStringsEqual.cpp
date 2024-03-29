#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (count(s.begin(), s.end(), '1') > 0) == (count(target.begin(), target.end(), '1') > 0);
    }

    bool makeStringsEqual1(string s, string target) {
        return (s.find('1') != string::npos) == (target.find('1') != string::npos);
    }
};

void testMakeStringsEqual() {
    Solution solution;
    cout << solution.makeStringsEqual("1010", "0110") << endl;
    cout << solution.makeStringsEqual("11", "00") << endl;
}

int main(){
    testMakeStringsEqual();
    return 0;
}