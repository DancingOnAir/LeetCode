#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto& p : paths) {
            s.insert(p[0]);
        }

        for (auto& p : paths) {
            if (!s.count(p[1]))
                return p[1];
        }

        return "";
    }

    string destCity1(vector<vector<string>>& paths) {
        vector<string> vs;
        for (auto& p : paths) {
            vs.push_back(p[0]);
        }

        for (auto& p : paths) {
            if (find(vs.begin(), vs.end(), p[1]) == vs.end()) {
                return p[1];
            }
        }

        return "";
    }
};

void testDestCity() {
    Solution solution;
    vector<vector<string>> path1 = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    assert(solution.destCity(path1) == "Sao Paulo");

    vector<vector<string>> path2 = {{"B","C"},{"D","B"},{"C","A"}};
    assert(solution.destCity(path2) == "A");

    vector<vector<string>> path3 = {{"A","Z"}};
    assert(solution.destCity(path3) == "Z");
}

int main() {
    testDestCity();

    return 0;
}