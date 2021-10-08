#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        unordered_map<string, int> freq;
        for (string& num : nums) {
            ++freq[num];
        }

        for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
            if (target.substr(0, iter->first.size()) == iter->first) {
                string suffix = target.substr(iter->first.size());
                res += iter->second * freq[suffix];

                if (suffix == iter->first) {
                    res -= freq[suffix];
                }
            }
        }

        return res;
    }
};

void testNumOfPairs() {
    Solution solution;

    vector<string> nums1{"777","7","77","77"};
    assert(solution.numOfPairs(nums1, "7777") == 4);
    vector<string> nums2{"123","4","12","34"};
    assert(solution.numOfPairs(nums2, "1234") == 2);
    vector<string> nums3{"1","1","1"};
    assert(solution.numOfPairs(nums3, "11") == 6);
}

int main() {
    testNumOfPairs();

    return 0;
}