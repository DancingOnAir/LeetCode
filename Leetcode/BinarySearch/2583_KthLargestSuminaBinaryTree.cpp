#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<TreeNode*> nodes = {root};
        // 默认是大堆
        priority_queue<long long, vector<long long>> pq;
        while (!nodes.empty()) {
            long long total = 0;
            vector<TreeNode*> temp;
            for (auto* p : nodes) {
                total += p->val;
                if (p->left) {
                    temp.push_back(p->left);
                }
                if (p->right) {
                    temp.push_back(p->right);
                }
            }

            nodes = temp;
            pq.push(total);
        }

        if (pq.size() < k) {
            return -1;
        }

        while (--k) {
            pq.pop();
        }

        return pq.top();
    }
};


void testKthLargestLevelSum() {
    Solution solution;
    auto node1 = TreeNode(3);
    auto node2 = TreeNode(2, &node1, nullptr);
    TreeNode root = TreeNode(1, &node2, nullptr);
    cout << solution.kthLargestLevelSum(&root, 1) << endl;
}

int main() {
    testKthLargestLevelSum();
    return 0;
}