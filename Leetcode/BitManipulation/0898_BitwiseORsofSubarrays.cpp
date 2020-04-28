#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    int hammingWeight(int num) {
        num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        num = (num & 0x0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f);
        num = (num & 0x00ff00ff) + ((num >> 8) & 0x00ff00ff);
        num = (num & 0xffff) + ((num >> 16) & 0xffff);

        return num;
    }

    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return n;

        unordered_set<int> s;
        set<int> t;
        for (int i : A) {
            set<int> r;
            r.insert(i);
            for (int j : t)
                r.insert(j | i);
            t = r;
            for (int j : t)
                s.insert(j);
        }

        return s.size();
    }
};

void testSubarrayBitwiseORs() {
    Solution solution;

    vector<int> A1 { 0 };
    cout << solution.subarrayBitwiseORs(A1) << endl;

    vector<int> A2 { 1, 1, 2 };
    cout << solution.subarrayBitwiseORs(A2) << endl;

    vector<int> A3 { 1, 2, 4 };
    cout << solution.subarrayBitwiseORs(A3) << endl;

    vector<int> A4 { 3, 11 };
    cout << solution.subarrayBitwiseORs(A4) << endl;
}

int main() {
    testSubarrayBitwiseORs();

    return 0;
}