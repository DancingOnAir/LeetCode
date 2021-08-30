#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8));

        if (m > 2 && (y % 400 == 0 or (y % 4 == 0 && y % 100 != 0)))
            ++d;
        while (--m > 0) {
            d += days[m - 1];
        }
        return d;
    }
};

void testDayOfYear() {
    Solution solution;
    assert(solution.dayOfYear("2019-01-09") == 9);
    assert(solution.dayOfYear("2019-02-10") == 41);
    assert(solution.dayOfYear("2003-03-01") == 60);
    assert(solution.dayOfYear("2004-03-01") == 61);
}

int main() {
    testDayOfYear();

    return 0;
}