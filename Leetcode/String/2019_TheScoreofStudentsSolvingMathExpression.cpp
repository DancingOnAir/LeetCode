#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
private:
    unordered_set<int> dp(const string& s, int i, int j) {
        unordered_set<int> res;
        if (i == j) {
            res.insert((s[i] - '0'));
            return res;
        }

        for (int k = i + 1; k < j; k += 2) {
            unordered_set<int> v1 = dp(s, i, k - 1);
            for (int a : v1) {
                unordered_set<int> v2 = dp(s, k + 1, j);
                for (int b : v2) {
                    int cur = (s[k] == '+') ? a + b : a * b;
                    if (cur <= 1000)
                        res.insert(cur);
                }
            }
        }
        return res;
    }

    int calculateCorrectAnswer(const string& s) {
        int res = 0;
        for (int i = 1, j = 0; i <= s.size(); i += 2) {
            if (i == s.size() || s[i] == '+') {
                int mul = 1;
                for (; j < i; j += 2) {
                    mul *= (s[j] - '0' );
                }

                res += mul;
            }
        }

        return res;
    }

public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int correct = calculateCorrectAnswer(s);
        unordered_set<int> wrongSeq = dp(s, 0, s.size() - 1);

        int res = 0;
        for (int ans : answers) {
            if (ans == correct) {
                res += 5;
            }
            else if (wrongSeq.count(ans)) {
                res += 2;
            }
        }

        return res;
    }
};

void testScoreOfStudents() {
    Solution solution;

    vector<int> a1{20,13,42};
    assert(solution.scoreOfStudents("7+3*1*2", a1) == 7);
    vector<int> a2{13,0,10,13,13,16,16};
    assert(solution.scoreOfStudents("3+5*2", a2) == 19);
    vector<int> a3{12,9,6,4,8,6};
    assert(solution.scoreOfStudents("6+0*1", a3) == 10);
    vector<int> a4{13,21,11,15};
    assert(solution.scoreOfStudents("1+2*3+4", a4) == 11);
}

int main() {
    testScoreOfStudents();

    return 0;
}