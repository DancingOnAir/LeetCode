#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // sort(arr.begin(), arr.end());
        sort(arr.begin(), arr.end(), [](int& a, int& b) { 
            if (__builtin_popcount(a) != __builtin_popcount(b))
                return __builtin_popcount(a) < __builtin_popcount(b); 
            else
                return a < b;
            });
        return arr;
    }
};


void testSortByBits() {
    Solution solution;

    vector<int> arr1 {0,1,2,3,4,5,6,7,8};
    auto res1 = solution.sortByBits(arr1);
    for (auto& s : res1) {
        cout << s << ", ";
    }
    cout << endl;

    vector<int> arr2 {1024,512,256,128,64,32,16,8,4,2,1};
    auto res2 = solution.sortByBits(arr2);
    for (auto& s : res2) {
        cout << s << ", ";
    }
    cout << endl;
}

int main() {
    testSortByBits();
    return 0;
}
