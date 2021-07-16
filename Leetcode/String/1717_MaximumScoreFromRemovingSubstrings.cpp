#include <string>

using namespace std;
class Solution {
private:
    string greedy(string s, char a, char b) {
        string res;
        for (char c : s) {
            if (!res.empty() && res.back() == a && c == b) {
                res.pop_back();
            }
            else
                res.push_back(c);
        }

        return res;
    }

public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }

        auto s1 = greedy(s, a, b);
        auto s2 = greedy(s1, b, a);
        return (s.size() - s1.size()) * x / 2 + (s1.size() - s2.size()) * y / 2;
    }
};

void testMaximumGain() {
    Solution solution;

    assert(solution.maximumGain("cdbcbbaaabab", 4, 5) == 19);
    assert(solution.maximumGain("aabbaaxybbaabb", 5, 4) == 20);
}

int main() {
    testMaximumGain();

    return 0;
}