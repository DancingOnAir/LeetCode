#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int m = haystack.size(), n = needle.size();
        if (n > m)
            return -1;
        
        vector<int> nxt(n);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j])
                j = nxt[j - 1];
            if (needle[i] == needle[j])
                ++j;
            nxt[i] = j;
        }

        for (int i = 0, j = 0; i < m; ++i) {
            while (j > 0 && haystack[i] != needle[j])
                j = nxt[j - 1];
            if (haystack[i] == needle[j])
                ++j;
            if (j == n)
                return i - n + 1;
        }

        return -1;
    }

    // brute force solution
    int strStr2(string haystack, string needle) {
        int result = -1;

        if (haystack.size() < needle.size())
            return result;

        if (needle.empty())
            return 0;

        for (decltype(haystack.size()) i = 0; i != haystack.size(); ++i) {
            if (haystack[i] == needle[0]) {
                for (decltype(needle.size()) j = 0; j != needle.size(); ++j) {
                    if (needle[j] != haystack[j + i])
                        break;
                    else if (j == needle.size() - 1)
                        return i;
                }
            }
        }

        return result;
    }


    vector<int> getNext(const string& pattern) {
        int i = -1, j = 0;
        vector<int> next(pattern.size());
        next[0] = -1;

        while (j < pattern.size() - 1) {
            if (i == -1 || pattern[i] == pattern[j]) {
                ++i;
                ++j;
                next[j] = i;
            }
            else {
                i = next[i];
            }
        }

        return next;
    }

    // KMP solution
    int strStr1(string haystack, string needle) {
        int s1 = haystack.size();
        int s2 = needle.size();

        if (s2 == 0)
            return 0;

        if (s1 < s2)
            return -1;

        int i = 0, j = 0;
        vector<int> next = getNext(needle);
        while (i < s1 && j < s2) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
            }
        }

        if (j == s2)
            return i - j;
        return -1;
    }
};

void testStrStr() {
    Solution solution;
    string needle1 = "ll";
    string haystack1 = "hello";
    assert(solution.strStr(haystack1, needle1) == 2);

    string needle2 = "bba";
    string haystack2 = "aaaaa";
    assert(solution.strStr(haystack2, needle2) == -1);

    assert(solution.strStr("", "") == 0);
}

int main() {
   testStrStr();

   return 0;
}
