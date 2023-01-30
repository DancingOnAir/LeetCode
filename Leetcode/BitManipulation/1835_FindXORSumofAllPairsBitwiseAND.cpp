#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    // https://blog.csdn.net/qq_45475271/article/details/107675845
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int s1 = 0;
        for (int x : arr1) {
            s1 ^= x;
        }

        int s2 = 0;
        for (int x : arr2) {
            s2 ^= x;
        }

        return s1 & s2;
    }
};

void testGetXORSum() {
    Solution solution;
    vector<int> arr1 {1,2,3};
    vector<int> arr2 {6, 5};
    cout << solution.getXORSum(arr1, arr2) << endl;
}

int main() {
    testGetXORSum();
    return 0;
}