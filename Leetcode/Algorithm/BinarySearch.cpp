#include <vector>
#include <iostream>

using namespace std;

// array should be in order.
class BinarySearch {
public:
    int rank(int key, vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < nums[mid]) {
                hi = mid - 1;
            }
            else if (key > nums[mid]) {
                lo = mid + 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};

void printNums(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << ", ";
    }

    cout << endl;
}

void testBinarySearch() {
    BinarySearch binarySearch;

    vector<int> nums{1, 3, 5, 2, 8, 7, 6, 9, 4, 10};
    sort(nums.begin(), nums.end());
    printNums(nums);

    cout << binarySearch.rank(3, nums) << endl;
}

int main() {
    testBinarySearch();

    return 0;
}