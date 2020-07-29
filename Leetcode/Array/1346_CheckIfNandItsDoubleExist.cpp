#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int a : arr) {
            if (((a & 1) == 0 && s.count(a / 2)) || s.count(a * 2)) {
                return true;
            }

            s.emplace(a);
        }

        return false;
    }
};

void testCheckIfExist() {
    Solution solution;

    vector<int> arr1 {10, 2, 5, 3};
    cout << (solution.checkIfExist(arr1) ? "True" : "False") << endl;

    vector<int> arr2 {7, 1, 14, 11};
    cout << (solution.checkIfExist(arr2) ? "True" : "False") << endl;

    vector<int> arr3 {3, 1, 7, 11};
    cout << (solution.checkIfExist(arr3) ? "True" : "False") << endl;
}

int main() {
    testCheckIfExist();

    return 0;
}