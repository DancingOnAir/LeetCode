#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        const unsigned n = A.size();
        unsigned odd = 1u;
        unsigned even = 0u;

        while (even < n) {
            while (even < n && (A[even] & 1u) == 0u)
                even += 2u;

            while (odd < n && (A[odd] & 1u)) {
                odd += 2u;
            }

            if (even < n) 
                swap(A[even], A[odd]);

            even += 2u;
            odd += 2u;
        }

        return A;
    }
};

void printResult(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }
    cout << endl;
}

void testSortArrayByParityII() {
    Solution solution;
    
    vector<int> A1 {4, 2, 5, 7};
    auto res1 = solution.sortArrayByParityII(A1);
    printResult(res1);

    vector<int> A2 {2, 3, 1, 1, 4, 0, 0, 4, 3, 3};
    auto res2 = solution.sortArrayByParityII(A2);
    printResult(res2);
}

int main() {
    testSortArrayByParityII();

    return 0;
}