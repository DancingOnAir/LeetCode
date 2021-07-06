#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
private:
    unordered_map<int, int> mp;
    bool isSubsequence(string& s, string& p, int x) {
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(i) && mp[i] < x)
                continue;
            if (k < p.size() && s[i] == p[k])
                ++k;
        }

        return k == p.size();
    }

public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        for (int i = 0; i < removable.size(); ++i) {
            mp[removable[i]] = i;
        }

        int lo = -1;
        int hi = removable.size();
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (isSubsequence(s, p, mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};

void testMaximumRemovals() {
    Solution solution;

    vector<int> removable1({3,1,0});
    assert(solution.maximumRemovals("abcacb", "ab", removable1) == 2);

    vector<int> removable2({3,2,1,4,5,6});
    assert(solution.maximumRemovals("abcbddddd", "abcd", removable2) == 1);

    vector<int> removable3({0,1,2,3,4});
    assert(solution.maximumRemovals("abcab", "abc", removable3) == 0);
}

int main() {
    testMaximumRemovals();

    return 0;
}