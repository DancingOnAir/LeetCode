#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {

        int sum = 0;
        for (int a : A) {
            if ((a & 1) == 0) {
                sum += a;
            }
        }
        
        vector<int> res;
        for (auto& q : queries) {
            if ((A[q[1]] & 1) == (q[0] & 1)) {
                if (q[0] & 1) {
                    sum += A[q[1]];
                }
                sum += q[0];
            }
            else {
                if ((A[q[1]] & 1) == 0) {
                    sum -= A[q[1]];
                }
            }
            
            res.emplace_back(sum);
            A[q[1]] += q[0];
        }

        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testSumEvenAfterQueries() {
    Solution solution;
    vector<int> A1 = {1,2,3,4};
    vector<vector<int>> queries1 = {{ 1, 0 }, { -3, 1 }, { -4, 0 }, { 2, 3 }};
    auto res1 = solution.sumEvenAfterQueries(A1, queries1);
    printRes(res1);
}

int main() {
    testSumEvenAfterQueries();

    return 0;
}