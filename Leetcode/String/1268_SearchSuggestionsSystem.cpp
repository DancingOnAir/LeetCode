#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
struct Trie {
    unordered_map<char, Trie*> children;
    vector<string> suggestions;
};

class Solution {
public:
    void _insert(Trie* root, string& product) {
        auto trie = root;
        for (auto c : product) {
            if (!trie->children.count(c))
                trie->children[c] = new Trie();
            trie = trie->children[c];
            trie->suggestions.push_back(product);
            sort(trie->suggestions.begin(), trie->suggestions.end());

            if (trie->suggestions.size() > 3) {
                trie->suggestions.pop_back();
            };
        }
    }

    vector<vector<string>> _search(Trie* root, string& searchWord) {
        vector<vector<string>> res;
        for (char c : searchWord) {
            if (root) {
                root = root->children[c];
            }

            if (!root)
                res.push_back({});
            else
                res.push_back(root->suggestions);
        }

        return res;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto root = new Trie();
        for (auto& p : products) {
            _insert(root, p);
        }
        return _search(root, searchWord);
    }
};

void testSuggestedProducts() {
    Solution solution;

    vector<string> products1{"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord1 = "mouse";
    vector<vector<string>> res1 = {{"mobile","moneypot","monitor"}, {"mobile","moneypot","monitor"}, {"mouse","mousepad"}, {"mouse","mousepad"}, {"mouse","mousepad"}};
    assert(solution.suggestedProducts(products1, searchWord1) == res1);

    vector<string> products2{"havana"};
    string searchWord2 = "havana";
    vector<vector<string>> res2 = {{"havana"},{"havana"},{"havana"},{"havana"},{"havana"},{"havana"}};
    assert(solution.suggestedProducts(products2, searchWord2) == res2);

    vector<string> products3{"bags","baggage","banner","box","cloths"};
    string searchWord3 = "bags";
    vector<vector<string>> res3 = {{"baggage","bags","banner"},{"baggage","bags","banner"},{"baggage","bags"},{"bags"}};
    assert(solution.suggestedProducts(products3, searchWord3) == res3);

    vector<string> products4{"havana"};
    string searchWord4 = "tatiana";
    vector<vector<string>> res4 = {{},{},{},{},{},{},{}};
    assert(solution.suggestedProducts(products4, searchWord4) == res4);
}

int main() {
    testSuggestedProducts();

    return 0;
}