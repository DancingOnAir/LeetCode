#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumofFirstOneBits(int num) {
        int res = 0;
        int flag = 0x1 << 7;

        while ((num & flag)) {
            ++res;
            flag >>= 1;
        }

        return res;
    }

    bool validUtf8(vector<int>& data) {
        if (data.empty())
            return true;

        // sort(data.begin(), data.end(), greater<int>());
        int n = data.size();
        if (n > 4)
            return false;

        int i = 0;
        for (i = 0; i < n;) {
            int temp = getNumofFirstOneBits(data[i]);
            if (temp > 7 || i + temp > n)
                return false;

            if (temp == 1) {
                return false;
            }

            if (temp == 0) {
                ++i;
                continue;
            }

            for (int j = 1; j < temp; ++j) {
                if (getNumofFirstOneBits(data[i + j]) != 1)
                    return false;
            }

            i += temp;
        }

        return i == n;
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