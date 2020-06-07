#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> count(60);
        for (const auto& x : time) {
            int temp = x % 60;
            res += temp ? count[60 -temp] : count[temp];
            ++count[temp];
        }

        return res;
    }

    int numPairsDivisibleBy601(vector<int>& time) {
        int n = time.size();
        if (n < 2)
            return 0;
        
        int res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count((60 - time[i] % 60) % 60)) {
                res += m[(60 - time[i] % 60) % 60];
            }

            m[time[i] % 60]++;
        }

        return res;
    }
};

void testNumPairsDivisibleBy60() {
    Solution solution;
    vector<int> time1 {30, 20, 150, 100, 40};
    cout << solution.numPairsDivisibleBy60(time1) << endl;

    vector<int> time2 {60, 60, 60};
    cout << solution.numPairsDivisibleBy60(time2) << endl;
}

int main() {
    testNumPairsDivisibleBy60();

    return 0;
}