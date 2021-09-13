#include <string>


using namespace std;
class Solution {
private:
    bool isLeapYear(int y) {
        if (0 == y % 400)
            return true;
        else if (0 == y % 100)
            return false;
        else if (0 == y % 4)
            return true;
        return false;
    }

    int dayInMonth(int y, int m) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            return 31;
        else if (m == 2)
            return isLeapYear(y)? 29: 28;
        return 30;
    }

    int calculateDays(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        int res = 0;
        for (int i = 1971; i < y; ++i) {
            res += isLeapYear(i) ? 366 : 365;
        }

        for (int i = 1; i < m; ++i) {
            res += dayInMonth(y, i);
        }

        return res + d;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(calculateDays(date1) - calculateDays(date2));
    }
};

void testDaysBetweenDates() {
    Solution solution;

    assert(solution.daysBetweenDates("2019-06-29", "2019-06-30") == 1);
    assert(solution.daysBetweenDates("2020-01-15", "2019-12-31") == 15);
}

int main() {
    testDaysBetweenDates();

    return 0;
}