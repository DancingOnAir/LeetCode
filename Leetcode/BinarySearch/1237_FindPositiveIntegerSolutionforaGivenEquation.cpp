#include <iostream>
#include <vector>

using namespace std;
// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y) {
        return x + y;
    };
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int left = 1, right = 1000;
        for (int x = 1; x <= 1000; ++x) {
            if (customfunction.f(x, left) > z or customfunction.f(x, right) < z) {
                continue;
            }

            int yl = left, yr = right;
            while (yl <= yr) {
                int ym = yl + (yr - yl) / 2;
                int cur = customfunction.f(x, ym);
                if (cur == z) {
                    res.push_back({x, ym});
                    break;
                }
                else if (cur < z) {
                    yl = ym + 1;
                }
                else {
                    yr = ym - 1;
                }
            }

            if (customfunction.f(x, yl) >= z) {
                right = yl;
            }
        }

        return res;
    }
};

void testFindSolution() {
    Solution solution;
    CustomFunction customFunction;
    auto res = solution.findSolution(customFunction, 5);
    for (auto& x : res) {
        for (int y : x) {
            cout << y << ", ";
        }
        cout << endl;
    }
}

int main() {
    testFindSolution();
    return 0;
}