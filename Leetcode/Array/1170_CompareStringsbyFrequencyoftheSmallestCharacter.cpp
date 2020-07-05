#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int calculateFrequency(string& word) {
        if (word.size() < 2)
            return word.size();

        sort(word.begin(), word.end());

        auto iter = upper_bound(word.begin(), word.end(), word[0]);
        return iter - word.begin();
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqs;
        for (auto& word : words) {
            freqs.emplace_back(calculateFrequency(word));
        }

        sort(freqs.begin(), freqs.end());

        vector<int> res;
        for (auto& query : queries) {
            int freq = calculateFrequency(query);
            int num = freqs.end() - upper_bound(freqs.begin(), freqs.end(), freq);
            res.emplace_back(num);
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

void testNumSmallerByFrequency() {
    Solution solution;

    vector<string> queries1 {"cbd"}, words1 = {"zaaaz"};
    auto res1 = solution.numSmallerByFrequency(queries1, words1);
    printNums(res1);

    vector<string> queries2 {"bbb", "cc"}, words2 = {"a", "aa", "aaa", "aaaa"};
    auto res2 = solution.numSmallerByFrequency(queries2, words2);
    printNums(res2);
}

int main() {
    testNumSmallerByFrequency();

    return 0;
}