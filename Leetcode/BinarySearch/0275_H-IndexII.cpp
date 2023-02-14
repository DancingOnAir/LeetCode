#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (!n)
            return 0;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] + mid >= n) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};

void testHIndex() {
    Solution solution;
    vector<int> citations1 {0,1,3,5,6};
    cout << solution.hIndex(citations1) << endl;

    vector<int> citations2 {1,2,100};
    cout << solution.hIndex(citations2) << endl;
}

int main() {
    testHIndex();
    return 0;
}