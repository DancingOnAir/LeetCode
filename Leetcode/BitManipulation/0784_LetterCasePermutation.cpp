#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        return vector<string>();
    }
};

void printRes(vector<string>& strs) {
    if (strs.empty())
        return;

    for (string& str : strs) {
        cout << str << ", ";
    }

    cout << endl;
}

void testLetterCasePermutation() {
    Solution solution;

    string S1= "a1b2";
    auto res1 = solution.letterCasePermutation(S1);
    printRes(res1);

    string S2= "3z4";
    auto res2 = solution.letterCasePermutation(S2);
    printRes(res2);

    string S3= "12345";
    auto res3 = solution.letterCasePermutation(S3);
    printRes(res3);
}

int main() {
    testLetterCasePermutation();

    return 0;
}