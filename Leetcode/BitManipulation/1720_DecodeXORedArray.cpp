#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res {first};
        for (auto x : encoded) {
            res.push_back(x ^ res.back());
        }
        return res;
    }
};


void testDecode() {
    Solution solution;
    vector<int> encoded1 {1, 2, 3};
    auto res1 = solution.decode(encoded1, 1);
    for (auto& x : res1) {
        cout << x << ", ";
    }
    cout << endl;

    vector<int> encoded2 {6, 2, 7, 3};
    auto res2 = solution.decode(encoded2, 4);
    for (auto& x : res2) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
    testDecode();
    return 0;
}