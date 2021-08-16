#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string minInteger(string num, int k) {
        if (k <= 0)
            return num;

        int n = num.size();
        if (k >= n * (n - 1) / 2) {
            sort(num.begin(), num.end());
            return num;
        }

        auto sortedNum = num;
        sort(sortedNum.begin(), sortedNum.end());
        if (sortedNum == num)
            return num;
            
        for(int i = 0; i < 10; ++i){
            int idx = num.find(to_string(i));
            if(idx >= 0 && idx <= k)
                return num[idx] + minInteger(num.substr(0, idx) + num.substr(idx + 1), k - idx);
        }

        return num;
    }
};

void testMinInteger() {
    Solution solution;

    assert(solution.minInteger("4321", 4) == "1342");
    assert(solution.minInteger("100", 1) == "010");
    assert(solution.minInteger("36789", 1000) == "36789");
    assert(solution.minInteger("22", 22) == "22");
    assert(solution.minInteger("9438957234785635408", 23) == "0345989723478563548");
}

int main() {
    testMinInteger();

    return 0;
}