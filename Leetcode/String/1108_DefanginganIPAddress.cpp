#include <string>
#include <regex>
#include <iostream>

using namespace std;
class Solution {
private:
    void replaceString(const string& target, const string& rep, string& text) {
        auto i = 0;
        while ((i = text.find(target, i)) != string::npos) {
            text.replace(i, target.size(), rep);
            i += rep.size();
        }
    }

public:
    string defangIPaddr(string address) {
        return regex_replace(address, regex("[.]"), "[.]");
    }

    string defangIPaddr1(string address) {
        replaceString(".", "[.]", address);
        return address;
    }
};

void testDefangIPAddr() {
    Solution solution;

    assert(solution.defangIPaddr("1.1.1.1") == "1[.]1[.]1[.]1");
    assert(solution.defangIPaddr("255.100.50.0") == "255[.]100[.]50[.]0");
}

int main() {
    testDefangIPAddr();

    return 0;
}