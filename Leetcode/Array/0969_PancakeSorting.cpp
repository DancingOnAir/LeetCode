#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        if (is_sorted(A.begin(), A.end())) {
            return res;
        }
        
        int i = 0, n = A.size();
        while(i <= n) {
            auto maxPos = distance(A.begin(), max_element(A.begin(), A.begin() + n - i));
            reverse(A.begin(), A.begin() + maxPos + 1);
            reverse(A.begin(), A.begin() + n - i);
            res.push_back(maxPos + 1);
            res.push_back(n - i);
            if (is_sorted(A.begin(), A.end())) {
                return res;
            }
            i++;
        }
        return res;
    }

    vector<int> pancakeSort1(vector<int>& A) {
        vector<int> res;
        if (is_sorted(A.begin(), A.end()))
            return res;
        
        for (int i = A.size(); i > 1; --i) {
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