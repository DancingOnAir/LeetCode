#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k-- > 0) {
            int cur = sqrt(pq.top());
            pq.pop();
            pq.push(cur);
        }

        long long res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};

void testPickGifts() {
    Solution solution;
    vector<int> gifts1 {25,64,9,4,100};
    cout << solution.pickGifts(gifts1, 4) << endl;
    vector<int> gifts2 {1,1,1,1};
    cout << solution.pickGifts(gifts2, 4) << endl;
}

int main() {
    testPickGifts();
    return 0;
}
