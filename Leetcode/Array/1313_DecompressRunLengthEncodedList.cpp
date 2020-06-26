#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i= 0; i < nums.size() - 1; i += 2){
            int freq = nums[i];
            for(; freq > 0; --freq) res.emplace_back(nums[i + 1]);
        }
        return res;
    }

    vector<int> decompressRLElist1(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            vector<int> temp(nums[i], nums[i + 1]);
            res.insert(res.end(), temp.begin(), temp.end());
        }

        return res;
    }
};

void printNums(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testDecompressRLElist() {
    Solution solution;

    vector<int> nums1 {1, 2, 3, 4};
    auto res1 = solution.decompressRLElist(nums1);
    printNums(res1);

    vector<int> nums2 {1, 1, 2, 3};
    auto res2 = solution.decompressRLElist(nums2);
    printNums(res2);
}

int main() {
    testDecompressRLElist();

    return 0;
}