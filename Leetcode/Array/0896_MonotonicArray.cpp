#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool asc = true;
        bool desc = true;

        for (int i = 1; i < A.size(); ++i) {
            if (A[i] < A[i - 1])
                asc = false;

            if (A[i] > A[i -1])
                desc = false;
        }

        return asc || desc;
    }

    bool isMonotonic1(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return true;
        
        int flag = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] == A[i]) {
                continue;
            } else if (A[i - 1] < A[i]) {
                if (flag == 2) {
                    return false;
                } else {
                    flag = 1;
                }
                
            } else {
                if (flag == 1) {
                    return false;
                } else {
                    flag = 2;
                }
            }
        }

        return true;
    }
};

void testIsMonotonic() {
    Solution solution;

    vector<int> A1 {1, 2, 2, 3};
    cout << (solution.isMonotonic(A1) ? "True" : "False") << endl;
    vector<int> A2 {6, 5, 4, 4};
    cout << (solution.isMonotonic(A2) ? "True" : "False") << endl;
    vector<int> A3 {1, 3, 2};
    cout << (solution.isMonotonic(A3) ? "True" : "False") << endl;
    vector<int> A4 {1, 2, 4, 5};
    cout << (solution.isMonotonic(A4) ? "True" : "False") << endl;
    vector<int> A5 {1, 1, 1};
    cout << (solution.isMonotonic(A5) ? "True" : "False") << endl;
}

int main() {
    testIsMonotonic();

    return 0;
}