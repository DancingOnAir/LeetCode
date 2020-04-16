#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (bitset<32>(i).count() + bitset<32>(j).count() == num) {
                    res.emplace_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
                }
            }
        }

        return res;
    }
};
 
void display(const vector<string>& v) {
    for (auto& str : v) {
        cout << str << ", ";
    }

    cout << endl;
}

void testReadBinaryWatch() {
    Solution solution;

    int num1 = 1;
    vector<string> res1 = {"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"};
    display(res1);
    display(solution.readBinaryWatch(num1));
}

int main() {
    testReadBinaryWatch();

    return 0;
}