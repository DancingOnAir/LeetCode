#include <string>
#include <sstream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        string temp, pre1, pre2;
        vector<string> res;

        while (iss >> temp) {
            if (pre1 == first && pre2 == second) {
                res.push_back(temp);
            }

            pre1 = pre2;
            pre2 = temp;
        }

        return res;
    }
};

void testFindOcurrences() {
    Solution solution;

    vector<string> res1{"girl", "student"};
    assert(solution.findOcurrences("alice is a good girl she is a good student", "a", "good") == res1);

    vector<string> res2{"we", "rock"};
    assert(solution.findOcurrences("we will we will rock you", "we", "will") == res2);
}

int main() {
    testFindOcurrences();

    return 0;
}