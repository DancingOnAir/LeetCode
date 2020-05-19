#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> presum(n + 1);
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + (S[i] - '0');
        }

        int res = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            res = min(res, presum[i] + n - i - (presum[n] - presum[i]));
        }

        return res;
    }

    int minFlipsMonoIncr1(string S) {
        int n = S.size();
        if (n < 2)
            return 0;
        
        int numOfZero = 0;
        for (char c : S) {
            if (c == '0')
                ++numOfZero;
        }

        int res = INT_MAX;
        int l = 0, r = numOfZero;
        for (char c : S) {
            res = min(res, l + r);

            if (c == '1')
                ++l;
            else
                --r;
        }

        return min(res, min(numOfZero, n - numOfZero));
    }
};

void testMinFlipsMonoIncr() {
    Solution solution;

    string S1 = "00110";
    cout << solution.minFlipsMonoIncr(S1) << endl;

    string S2 = "010110";
    cout << solution.minFlipsMonoIncr(S2) << endl;

    string S3 = "00011000";
    cout << solution.minFlipsMonoIncr(S3) << endl;
    
    string S4 = "0101100011";
    cout << solution.minFlipsMonoIncr(S4) << endl;
}

int main() {
    testMinFlipsMonoIncr();

    return 0;
}