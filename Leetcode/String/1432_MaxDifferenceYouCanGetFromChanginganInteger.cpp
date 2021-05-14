#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    string replaceDigits(string s, char target, string dest) {
        if (s.find(target) == string::npos)
            return s;
        return replaceDigits(s.replace(s.find(target), 1, dest), target, dest);
    }
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = to_string(num);

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != '9') {
                a = replaceDigits(a, a[i], "9");
                break;
            }
        }

        if (b[0] != '1') {
            b = replaceDigits(b, b[0], "1");
        }
        else {
            for (int i = 1; i < b.size(); ++i) {
                if (b[i] != '0' && b[i] != '1') {
                    b = replaceDigits(b, b[i], "0");
                    break;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};

void testMaxDiff() {
    Solution solution;
    assert(solution.maxDiff(555) == 888);
    assert(solution.maxDiff(9) == 8);
    assert(solution.maxDiff(123456) == 820000);
    assert(solution.maxDiff(10000) == 80000);
    assert(solution.maxDiff(9288) == 8700);
}

int main() {
    testMaxDiff();

    return 0;
}