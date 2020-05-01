#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        if (A.size() != B.size())
            return vector<int>();

        sort(A.begin(), A.end());

        vector<int> res;
        for (int i = 0; i < B.size(); ++i) {
            auto iter = upper_bound(A.begin(), A.end(), B[i]);
            if (iter == A.end()) {
                res.emplace_back(*A.begin());
                A.erase(A.begin());
            } else {
                res.emplace_back(*iter);
                A.erase(iter);
            }
        }

        return res;
    }
};

void printArray(const vector<int>& nums) {
    for (int num : nums)
        cout << num << ", ";
    cout << endl;
}

void testAdvantageCount() {
    Solution solution;

    vector<int> A1 = {2,7,11,15};
    vector<int> B1 = {1,10,4,11};
    auto res1 = solution.advantageCount(A1, B1);
    printArray(res1);

    vector<int> A2 = {12,24,8,32};
    vector<int> B2 = {13,25,32,11};
    auto res2 = solution.advantageCount(A2, B2);
    printArray(res2);
}

int main() {
    testAdvantageCount();

    return 0;
}