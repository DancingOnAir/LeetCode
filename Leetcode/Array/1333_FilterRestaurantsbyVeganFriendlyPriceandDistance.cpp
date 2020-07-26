#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;

        for (auto& r : restaurants) {
            if (veganFriendly && !r[2]) {
                continue;
            }

            if (r[3] <= maxPrice && r[4] <= maxDistance) {
                filtered.emplace_back(r);
            }
        }
        sort(filtered.begin(), filtered.end(), [](const vector<int>& lhs, const vector<int>& rhs) { 
            return (lhs[1] == rhs[1]) ? lhs[0] > rhs[0] : lhs[1] > rhs[1]; });

        vector<int> res;
        for (auto& f : filtered) {
            res.emplace_back(f[0]);
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

void testFilterRestaurants() {
    Solution solutoin;

    vector<vector<int>> restaurants1 = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    int veganFriendly1 = 1, maxPrice1 = 50, maxDistance1 = 10;
    auto res1 = solutoin.filterRestaurants(restaurants1, veganFriendly1, maxPrice1, maxDistance1);
    printNums(res1);

    vector<vector<int>> restaurants2 = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    int veganFriendly2 = 0, maxPrice2 = 50, maxDistance2 = 10;
    auto res2 = solutoin.filterRestaurants(restaurants2, veganFriendly2, maxPrice2, maxDistance2);
    printNums(res2);

    vector<vector<int>> restaurants3 = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    int veganFriendly3 = 0, maxPrice3 = 30, maxDistance3 = 3;
    auto res3 = solutoin.filterRestaurants(restaurants3, veganFriendly3, maxPrice3, maxDistance3);
    printNums(res3);
}

int main() {
    testFilterRestaurants();

    return 0;
}