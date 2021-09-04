#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](string& a, string& b) { 
            if (a.size() == b.size()) 
                return a < b;
            else 
                return a.size() < b.size();
            });
        return nums[nums.size() - k];
    }
};

void testKthLargestNumber() {
    Solution solution;

    vector<string> nums1{"3","6","7","10"};
    assert(solution.kthLargestNumber(nums1, 4) == "3");

    vector<string> nums2{"2","21","12","1"};
    assert(solution.kthLargestNumber(nums2, 3) == "2");

    vector<string> nums3{"0","0"};
    assert(solution.kthLargestNumber(nums3, 2) == "0");
}

int main() {
    testKthLargestNumber();

    return 0;
}