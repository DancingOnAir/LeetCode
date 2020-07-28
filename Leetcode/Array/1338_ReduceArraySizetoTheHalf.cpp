#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 1;

        unordered_map<int, int> m;
        for (int a : arr) {
            m[a]++;
        }

        priority_queue<int> pq;
        for (auto& iter : m) {
            pq.emplace(iter.second);
        }

        int res = 0, sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
            ++res;
            if (sum * 2 >= n)
                break;
        }
        return res;
    }
};

void testMinSetSize() {
    Solution solution;

    vector<int> arr1 {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    cout << solution.minSetSize(arr1) << endl;

    vector<int> arr2 {7, 7, 7, 7, 7, 7};
    cout << solution.minSetSize(arr2) << endl;

    vector<int> arr3 {1, 9};
    cout << solution.minSetSize(arr3) << endl;

    vector<int> arr4 {1000, 1000, 3, 7};
    cout << solution.minSetSize(arr4) << endl;

    vector<int> arr5 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solution.minSetSize(arr5) << endl;
}

int main() {
    testMinSetSize();

    return 0;
}