#include <string>
#include <unordered_map>
#include <functional>

using namespace std;
class Solution {
private:
    struct pairHash {
        template <class T1, class T2>
        size_t operator() (const pair<T1, T2> &p) const {
            auto h1 = hash<T1>{} (p.first);
            auto h2 = hash<T2>{} (p.second);
            return h1 ^ h2;
        }
    };

    int cost(const string& s) {
        int res = 0;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--])
                ++res;
        }

        return res;
    }

    int dp(unordered_map<pair<int, int>, int, pairHash>& memo, string& s, int end, int k) {
        if (!memo.count(make_pair(end, k))) {
            if (1 == k) {
                memo[make_pair(end, k)] = cost(s.substr(0, end + 1));
            }
            else {
                // i < end && i + 1 >= k - 1
                for (int i = k - 2; i < end; ++i) {
                    if (!memo.count(make_pair(end, k)) || memo[make_pair(end, k)] > dp(memo, s, i, k - 1) + cost(s.substr(i + 1, end - i)))
                        memo[make_pair(end, k)] = dp(memo, s, i, k - 1) + cost(s.substr(i + 1, end - i));
                }
            }
        }

        return memo[make_pair(end, k)];
    }

public:
    int palindromePartition(string s, int k) {
        unordered_map<pair<int, int>, int, pairHash> memo;
        return dp(memo, s, s.size() - 1, k);
    }
};

void testPalindromePartition() {
    Solution solution;
    printf("%d", solution.palindromePartition("abc", 1));
    assert(solution.palindromePartition("abc", 2) == 1);
    assert(solution.palindromePartition("aabbc", 3) == 0);
    assert(solution.palindromePartition("leetcode", 8) == 0);
}

int main() {
    testPalindromePartition();

    return 0;
}