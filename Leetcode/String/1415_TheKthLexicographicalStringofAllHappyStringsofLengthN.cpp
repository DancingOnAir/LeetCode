#include <string>

using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        auto prem = 1 << (n - 1);
        if (k > 3 * prem)
            return "";

        string res = string(1, 'a' + (k - 1) / prem);
        while (prem > 1) {
            k = (k - 1) % prem + 1;
            prem >>= 1;

            res += (k - 1) / prem == 0? 'a' + (res.back() == 'a') : 'b' + (res.back() != 'c');
        }

        return res;
    }
};

void testGetHappyString() {
    Solution solution;

    assert(solution.getHappyString(1, 3) == "c");
    assert(solution.getHappyString(1, 4) == "");
    assert(solution.getHappyString(3, 9) == "cab");
    assert(solution.getHappyString(2, 7) == "");
    assert(solution.getHappyString(10, 100) == "abacbabacb");
}

int main() {
    testGetHappyString();

    return 0;
}