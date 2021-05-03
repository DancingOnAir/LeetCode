#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getBiggerStr(const string& s1, const string& s2) {
        if (s1.size() == s2.size())
            return max(s1, s2);
        return s1.size() > s2.size() ? s1 : s2;
    }

    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<vector<string>> dp(n + 1, vector<string>(target + 1, ""));
        for (int j = 1; j < target + 1; ++j) {
            dp[0][j] = "#";
        }
        dp[0][0] = "";

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < target + 1; ++ j) {
                if (j - cost[i - 1] >= 0 && dp[i][j - cost[i - 1]] != "#") {
                    dp[i][j] = getBiggerStr(dp[i - 1][j], to_string(i) + dp[i][j - cost[i - 1]]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target] == "#"? "0" : dp[n][target];
    }
};

void testLargestNumber() {
    Solution solution;

    vector<int> cost1{4, 3, 2, 5, 6, 7, 2, 5, 5};
    assert(solution.largestNumber(cost1, 9) == "7772");
    vector<int> cost2{7, 6, 5, 5, 5, 6, 8, 7, 8};
    assert(solution.largestNumber(cost2, 12) == "85");
    vector<int> cost3{2,4,6,2,4,6,4,4,4};
    assert(solution.largestNumber(cost3, 5) == "0");
    vector<int> cost4{6,10,15,40,40,40,40,40,40};
    assert(solution.largestNumber(cost4, 47) == "32211");
}

int main() {
    testLargestNumber();

    return 0;
}