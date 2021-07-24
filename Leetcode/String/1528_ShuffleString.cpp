#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for (int i = 0; i < indices.size(); ++i) {
            res[indices[i]] = s[i];
        }

        return res;
    }

    string restoreString1(string s, vector<int>& indices) {
        for (auto i = 0; i < indices.size(); ++i) {
            while (indices[i] != i) {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }

        return s;
    }
};

void testRestoreString() {
    Solution solution;

    vector<int> indices1{4,5,6,7,0,2,1,3};
    assert(solution.restoreString("codeleet", indices1) == "leetcode");

    vector<int> indices2{4,0,2,6,7,3,1,5};
    assert(solution.restoreString("aaiougrt", indices2) == "arigatou");
}

int main() {
    testRestoreString();

    return 0;
}