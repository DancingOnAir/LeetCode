#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());

        do {
            if ((arr[0] < 2 || (arr[0] == 2 && arr[1] < 4)) && arr[2] < 6) {
                return to_string(arr[0]) + to_string(arr[1]) + ":" + to_string(arr[2]) + to_string(arr[3]);
            }
        }
        while (prev_permutation(arr.begin(), arr.end()));

        return "";
    }
};

void testLargestTimeFromDigits() {
    Solution solution;

    vector<int> arr1 {1,2,3,4};
    assert(solution.largestTimeFromDigits(arr1) == "23:41");

    vector<int> arr2 {5,5,5,5};
    assert(solution.largestTimeFromDigits(arr2) == "");

    vector<int> arr3 {0,0,0,0};
    assert(solution.largestTimeFromDigits(arr3) == "00:00");

    vector<int> arr4 {0,0,1,0};
    assert(solution.largestTimeFromDigits(arr4) == "10:00");
}

int main() {
    testLargestTimeFromDigits();

    return 0;
}