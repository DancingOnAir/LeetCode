#include <string>
#include <unordered_set>
#include <vector>


using namespace std;
class Solution {
private:
    unordered_set<string> dfs(const string& expr, int& i) {
        unordered_set<string> res;
        unordered_set<string> s;

        while (i < expr.size() && expr[i] != '}') {
            if (expr[i] == ',') {
                for (auto& it : s) {
                    res.insert(it);
                }
                s.clear();
                ++i;
            }

            unordered_set<string> t;
            if (expr[i] == '{') {
                ++i;
                t = dfs(expr, i);
                ++i;
            } 
            else {
                t.insert(string(1, expr[i++]));
            }

            if (s.empty()) {
                s = t;
            }
            else {
                unordered_set<string> u;
                for (auto& it1 : s) {
                    for (auto& it2 : t) {
                        u.insert(it1 + it2);
                    }
                }

                swap(s, u);
            }
        }

        for (auto& it : s) {
            res.insert(it);
        }

        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto s = dfs(expression, i);

        vector<string> res;
        for (auto& it : s) {
            res.emplace_back(it);
        }

        sort(res.begin(), res.end());
        return res;
    }
};

void testBraceExpansionII() {
    Solution solution;

    assert(solution.braceExpansionII("{a,b}{c,{d,e}}") == vector<string>({"ac","ad","ae","bc","bd","be"}));
    assert(solution.braceExpansionII("{{a,z},a{b,c},{ab,z}}") == vector<string>({"a","ab","ac","z"}));
}

int main() {
    testBraceExpansionII();

    return 0;
}