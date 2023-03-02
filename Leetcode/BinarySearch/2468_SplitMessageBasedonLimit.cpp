#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/split-message-based-on-limit/solutions/2807533/python-find-the-number-of-substrings/
    vector<string> splitMessage(string message, int limit) {
        int cur = 0, k = 0;
        int n = message.size();
        while (3 + to_string(k).size() * 2 < limit && limit * k < n + cur + (3 + to_string(k).size()) * k) {
            ++k;
            cur += to_string(k).size();
        }

        vector<string> res;
        int i = 0;
        if (3 + to_string(k).size() * 2 < limit) {
            for (int j = 1; j <= k; ++j) {
                int d = limit - 3 - to_string(k).size() - to_string(j).size();
                res.push_back(message.substr(i, d) + "<" + to_string(j) + "/" + to_string(k) + ">");
                i += d;
            }
        }

        return res;
    }
};

void printVector(vector<string>& res) {
    if (res.empty())
        return;
    for (auto& s: res) {
        cout << s << ", ";
    }

    cout << endl;
}

void testSplitMessage() {
    Solution solution;
    vector<string> res1 = solution.splitMessage("this is really a very awesome message", 9);
    printVector(res1);
    vector<string> res2 = solution.splitMessage("short message", 15);
    printVector(res2);
}

int main() {
    testSplitMessage();
    return 0;
}