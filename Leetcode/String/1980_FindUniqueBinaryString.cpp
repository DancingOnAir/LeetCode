#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i][i] == '0')
                res += '1';
            else
                res += '0';
        }

        return res;
    }
};

void testFindDifferentBinaryString() {
    Solution solution;

    vector<string> nums1{"01", "10"};
    assert(solution.findDifferentBinaryString(nums1) == "11");

    vector<string> nums2{"00","01"};
    assert(solution.findDifferentBinaryString(nums2) == "10");

    vector<string> nums3{"111","011","001"};
    assert(solution.findDifferentBinaryString(nums3) == "101");
}

int main() {
    testFindDifferentBinaryString();

    return 0;
}