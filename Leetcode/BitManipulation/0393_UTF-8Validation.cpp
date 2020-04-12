#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumofFirstOnes(int num) {
        for (int i = 7; i >= 0; --i) {
            if ((num & (1 << i)) == 0)
                return 7 - i;
        }

        return 8;
    }

    bool validUtf8(vector<int>& data) {
        if (data.empty())
            return true;

        // 1000 0000
        int one = 1 << 7;
        // 1100 0000
        int two = 3 << 6;

        int k = 0;
        for (int num : data) {
            if (k == 0) {
                if ((num & two) == one) {
                    return false;
                }

                if (num & one) {
                    k = getNumofFirstOnes(num);
                    if (k > 4)
                        return false;

                    --k;
                }
            }else {
                if ((num & two) != one)
                    return false;
                --k;
            }
        }

        return k == 0;
    }
};

void testValidUtf8() {
    Solution solution;
    vector<int> data1 = {197, 130, 1};
    cout << (solution.validUtf8(data1) ? "True" : "False") << endl;

    vector<int> data2 = {235, 140, 4};
    cout << (solution.validUtf8(data2) ? "True" : "False") << endl;

    vector<int> data3 = {237};
    cout << (solution.validUtf8(data3) ? "True" : "False") << endl;

    vector<int> data4 = {230,136,145};
    cout << (solution.validUtf8(data4) ? "True" : "False") << endl;

    vector<int> data5 = {250,145,145,145,145};
    cout << (solution.validUtf8(data5) ? "True" : "False") << endl;

}

int main() {
    testValidUtf8();
    return 0;
}