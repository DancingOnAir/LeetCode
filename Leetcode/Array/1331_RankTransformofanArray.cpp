#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty())
            return vector<int>();
            
        int maxVal = *max_element(arr.begin(), arr.end());
        int minVal = *min_element(arr.begin(), arr.end());

        vector<int> count(maxVal - minVal + 1);
        for (int a : arr) {
            count[a - minVal] = 1;
        }

        vector<int> presum(count.size() + 1);
        for (int i = 1; i < presum.size(); ++i) {
            presum[i] = presum[i - 1] + count[i - 1];
        }

        vector<int> res(arr.size());
        for (int i = 0; i < res.size(); ++i) {
            res[i] = presum[arr[i] - minVal + 1];
        }

        return res;
    }

    vector<int> arrayRankTransform1(vector<int>& arr) {
        vector<int> res(arr);
        sort(res.begin(), res.end());

        int rank = 1;
        map<int, int> m;
        for (int a : res) {
            if (!m.count(a))
                m[a] = rank++;
        }

        for (int i = 0; i < arr.size(); ++i) {
            res[i] = m[arr[i]];
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

void testArrayRankTransform() {
    Solution solution;

    vector<int> arr1 {40, 10, 20, 30};
    auto res1 = solution.arrayRankTransform(arr1);
    printNums(res1);

    vector<int> arr2 {100, 100, 100};
    auto res2 = solution.arrayRankTransform(arr2);
    printNums(res2);

    vector<int> arr3 {37, 12, 28, 9, 100, 56, 80, 5, 12};
    auto res3 = solution.arrayRankTransform(arr3);
    printNums(res3);
}

int main() {
    testArrayRankTransform();

    return 0;
}