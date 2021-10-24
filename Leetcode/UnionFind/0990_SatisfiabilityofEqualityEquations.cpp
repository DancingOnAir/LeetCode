#include <vector>
#include <string>

using namespace std;
class Solution {
private:
    vector<int> parents_;
public:
    int find(int idx) {
        while (idx != parents_[idx]) {
            idx = parents_[idx];
        }

        return idx;
    }

    void merge(int idx1, int idx2) {
        int p1 = find(idx1);
        int p2 = find(idx2);

        if (p1 == p2)
            return;
        parents_[p1] = p2;
    }

    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) {
            parents_.emplace_back(i);
        }
        
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '=')
                merge(equations[i][0] - 'a', equations[i][3] - 'a');
        }

        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '!') {
                if (find(equations[i][0] - 'a') == find(equations[i][3] - 'a'))
                    return false;
            }
        }

        return true;
    }
};

void testEequationsPossible() {
    Solution solution;

    vector<string> e1{"a==b","b!=a"};
    assert(!solution.equationsPossible(e1));

    vector<string> e2{"b==a","a==b"};
    assert(solution.equationsPossible(e2));

    vector<string> e3{"a==b","b==c","a==c"};
    assert(solution.equationsPossible(e3));

    vector<string> e4{"a==b","b!=c","c==a"};
    assert(!solution.equationsPossible(e4));

    vector<string> e5{"c==c","b==d","x!=z"};
    assert(solution.equationsPossible(e5));
}

int main() {
    testEequationsPossible();

    return 0;
}