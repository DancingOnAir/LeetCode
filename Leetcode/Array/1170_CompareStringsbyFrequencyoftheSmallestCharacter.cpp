#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int calculateFrequency(string& word) {
        char min = 'z';
        int res = 0;

        for (char c : word) {
            if (c < min) {
                min = c;
                res = 1;
            }
            else if (c == min) {
                ++res;
            }
        }

        return res;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> counts(12);
        for (auto& w : words) {
            counts[calculateFrequency(w)]++;
        }

        for (int i = counts.size() - 2; i != 0; --i) {
            counts[i] += counts[i + 1];
        }

        vector<int> res;
        for (auto& q : queries) {
            res.emplace_back(counts[calculateFrequency(q) + 1]);
        }

        return res;
    }

    vector<int> numSmallerByFrequency1(vector<string>& queries, vector<string>& words) {
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