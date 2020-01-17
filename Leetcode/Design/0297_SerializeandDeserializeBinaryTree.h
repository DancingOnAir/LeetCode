#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
 
class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string res = "[";
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if (!cur)
            {
                if (q.empty())
                    break;
                else
                {
                    res += "null,";
                    continue;
                }
            }

            res += to_string(cur->val) + ",";
            q.emplace(cur->left);
            q.emplace(cur->right);
        }

        for (int i = res.size() - 1; i > 0; --i)
        {
            if (res[i] == ',' || res[i] == 'n' || res[i] == 'u' || res[i] == 'l')
                res.pop_back();
            else
                break;
        }

        res += ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int n = data.size();
        if (n < 3)
            return nullptr;

        vector<string> nums;
        int i = 1;
        while (i < n - 1)
        {
            int len = 0;
            while (data[i + len] != ',' && i + len < n - 1)
            {
                ++len;
            }

            nums.emplace_back(data.substr(i, len));
            i += len + 1;
        }

        int startIndex = 1;
        int nextLevelIndex = 2;
        int restIndex = nums.size() - 1;

        TreeNode* root = new TreeNode(stoi(nums[0]));
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode* pCur = nullptr;

        while (restIndex > 0)
        {
            for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
            {
                pCur = q.front();
                q.pop();

                if (nums[i] != "null")
                {
                    pCur->left = new TreeNode(stoi(nums[i]));
                    q.emplace(pCur->left);
                }

                if (i + 1 > nums.size())
                    return root;

                if (nums[i + 1] != "null")
                {
                    pCur->right = new TreeNode(stoi(nums[i + 1]));
                    q.emplace(pCur->right);
                }

            }

            startIndex += nextLevelIndex;
            restIndex -= nextLevelIndex;
            nextLevelIndex = q.size() * 2;
        }

        return root;
    }

};
