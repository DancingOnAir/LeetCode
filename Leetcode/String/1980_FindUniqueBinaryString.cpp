#include <string>
#include <vector>
#include <unordered_set>
#include <bitset>

using namespace std;
class Solution {
public:
    // sweep
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> memo;
        for (auto& s : nums) {
            memo.insert(stoi(s, nullptr, 2));
        }

        for (int x = 0;; ++x) {
            if (!memo.count(x)) {
                return bitset<16>(x).to_string().substr(16 - nums.size());
            }
        }

        return "";
    }

    // OMG
    string findDifferentBinaryString1(vector<string>& nums) {
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