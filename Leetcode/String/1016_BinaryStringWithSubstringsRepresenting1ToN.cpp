#include <string>
#include <bitset>

using namespace std;
class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = n; i > n / 2; --i) {
            auto x = bitset<32>(i).to_string();
            if (s.find(x.substr(x.find('1'))) == string::npos)
                return false;
        }

        return true;
    }
};

void testQueryString() {
    Solution solution;
    assert(solution.queryString("0110", 3));
    assert(!solution.queryString("0110", 4));
}

int main() {
    testQueryString();

    return 0;
}