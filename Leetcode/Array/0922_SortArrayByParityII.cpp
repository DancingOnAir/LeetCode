#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.empty())
            return vector<int>();
        
        int n = A.size();
        int even = 0, odd = 1;
        while (even < n && odd < n) {
            while (even < n && !(A[even] & 1)) {
                even += 2;
            }

            while (odd < n && A[odd] & 1) {
                odd += 2;
            }

            if (even >= n || odd >= n)
                break;

            swap(A[even], A[odd]);
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