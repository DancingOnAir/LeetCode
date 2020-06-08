#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool helper(int capacity, vector<int>& weights, int D) {
        int temp = 0;
        for (int w : weights) {
            if (temp + w > capacity) {
                temp = 0;
                --D;
            }

            temp += w;
        }

        return D > 0;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        if (n < 2) {
            return weights[0];
        }

        int maxWeight = INT_MIN;
        int sum = 0;
        for (int w : weights) {
            maxWeight = max(maxWeight, w);
            sum += w;
        }

        int left = maxWeight, right = sum;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (helper(mid, weights, D)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

void testShipWithinDays() {
    Solution solution;

    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int D1 = 5;
    cout << solution.shipWithinDays(weights1, D1) << endl;

    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int D2 = 3;
    cout << solution.shipWithinDays(weights2, D2) << endl;

    vector<int> weights3 = {1, 2, 3, 1, 1};
    int D3 = 4;
    cout << solution.shipWithinDays(weights3, D3) << endl;
}

int main() {
    testShipWithinDays();

    return 0;
}