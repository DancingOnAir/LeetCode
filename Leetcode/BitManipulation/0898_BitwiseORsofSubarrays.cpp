#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return n;

        int orSum = 0;
        unordered_set<int> s(A.begin(), A.end());

        for (int num : s) {
            orSum |= num;
        }

        if (!orSum)
            return 0;

        int count = 0;
        while (orSum) {
            orSum &= (orSum - 1);
            ++count;
        }

        return count * (count + 1) / 2;
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