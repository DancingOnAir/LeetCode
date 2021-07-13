#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0, right = 0;
        int leftCost = 0, rightCost = 0;
        vector<int> res(boxes.size());
        for (int i = 1; i < boxes.size(); ++i) {
            if (boxes[i - 1] == '1')
                left += 1;
            leftCost += left;
            res[i] = leftCost;
        }

        for (int i = boxes.size() - 2; i >= 0; --i) {
            if (boxes[i + 1] == '1')
                right += 1;
            rightCost += right;
            res[i] += rightCost;
        }

        return res;
    }
};

void testMinOperations() {
    Solution solution;

    vector<int> res1{1, 1, 3};
    assert(solution.minOperations("110") == res1);
    vector<int> res2{11, 8, 5, 4, 3, 4};
    assert(solution.minOperations("001011") == res2);
}

int main() {
    testMinOperations();

    return 0;
}