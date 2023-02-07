#include <iostream>

using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        // __builtin_popcount 计算二进制里的1的数量
        // __builtin_clz (clz表示count leading zero) 计算二进制前的0的数量，注意参数必须大于0，等于0会出错。
        return num? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};

void testNumberOfSteps() {
    Solution solution;
    cout << solution.numberOfSteps(14) << endl;
    cout << solution.numberOfSteps(8) << endl;
    cout << solution.numberOfSteps(123) << endl;
}

int main() {
    testNumberOfSteps();
    return 0;
}