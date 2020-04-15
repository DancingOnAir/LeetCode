#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        return vector<string> {};
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