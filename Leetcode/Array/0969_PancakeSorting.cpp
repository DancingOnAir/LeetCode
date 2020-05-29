#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();

        vector<int> res;
        for (int i = n; i > 1; --i) {
            auto iter = max_element(A.begin(), A.begin() + i);
            if (iter != A.begin() + i - 1) {
                if (iter == A.begin()) {
                    reverse(A.begin(), A.begin() + i);
                    res.emplace_back(i);
                }
                else {
                    reverse(A.begin(), next(iter));
                    res.emplace_back(iter - A.begin() + 1);

                    reverse(A.begin(), A.begin() + i);
                    res.emplace_back(i);
                }
            } 
        }

        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << ", ";
    }

    cout << endl;
}

void testPancakeSort() {
    Solution solution;

    vector<int> A1 {3, 2, 4, 1};
    auto res1 = solution.pancakeSort(A1);
    printRes(res1);

    vector<int> A2 {3, 1, 2};
    auto res2 = solution.pancakeSort(A2);
    printRes(res2);
}

int main() {
    testPancakeSort();
    return 0;
}