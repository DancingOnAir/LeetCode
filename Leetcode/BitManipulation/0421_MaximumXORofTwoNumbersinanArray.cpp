#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    int num;
    vector<TrieNode*> children;
    TrieNode (): num(0), children(vector<TrieNode*>(2, nullptr)) {

    }
};

class Trie {
private:
    TrieNode* root_;

public:
    Trie() {
        root_ = new TrieNode();
    }

    void insert(int num) {
        auto p = root_;

        for (int i = 31; i >= 0; --i) {
            bool digit = num & (1 << i);
            if (p->children[digit] == nullptr) {
                p->children[digit] = new TrieNode();
            }

            p = p->children[digit];
        }

        p->num = num;
    }

    int search (int num) {
        auto p = root_;
        for (int i = 31; i >= 0; --i) {
            bool digit = num & (1 << i);
            if (p->children[1 - digit] != nullptr) {
                p = p->children[1 - digit];
            } else if (p->children[digit] != nullptr) {
                p = p->children[digit];
            }
        }

        return (p->num) ^ num;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        auto trie = new Trie();
        trie->insert(nums[0]);

        int res = 0;
        for (int i = 1; i < n; ++i) {
            int val = trie->search(nums[i]);
            res = max(res, val);

            trie->insert(nums[i]);
        }

        return res;
    }

    // brute force method
    int findMaximumXOR1(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(res, (nums[i] ^ nums[j]));
            }
        }

        return res;
    }
};

void testFindMaximumXOR() {
    Solution solution;
    vector<int> nums {3, 10, 5, 25, 2, 8};
    cout << solution.findMaximumXOR(nums) << endl;
}

int main() {
    testFindMaximumXOR();

    return 0;
}