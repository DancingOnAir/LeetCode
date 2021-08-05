#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){
            string a = to_string(x);
            string b = to_string(y);

            return (a+b) > (b+a);
        });
        
        string res;
        for (int num : nums) {
            res += to_string(num);
        }

        return res[0] == '0'? "0" : res;
    }
};

void testLargestNumber() {
    Solution solution;

    vector<int> nums1{10, 2};
    assert(solution.largestNumber(nums1) == "210");

    vector<int> nums2{3, 30, 34, 5, 9};
    assert(solution.largestNumber(nums2) == "9534330");

    vector<int> nums3{1};
    assert(solution.largestNumber(nums3) == "1");

    vector<int> nums4{10};
    assert(solution.largestNumber(nums4) == "10");

    vector<int> nums5{0, 0};
    assert(solution.largestNumber(nums5) == "0");

    vector<int> nums6{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    assert(solution.largestNumber(nums6) == "9876543210");
}

void testLambdaCompare() {
    vector<int> nums {3, 5, 2, 1, 4, 9, 6, 8, 7, 0};
    // sort(nums.begin(), nums.end(), [](int x, int y) { 
    //     if (x < y)
    //         return 1;
    //     else if (x == y)
    //         return 0;
    //     else {
    //         return -1;
    //     } });

    sort(nums.begin(), nums.end(), [](int x, int y) { 
        if (x < y)
            return 1;
        return 0;
        });

    for (int x : nums)
        cout << x << ", ";
    cout << endl;
}

int main() {
    testLargestNumber();
    // testLambdaCompare();

    return 0;
}