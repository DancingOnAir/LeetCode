#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int getNumOfLeapYear(int year) {
        return (year - 1968) / 4;
    }

    // calculate by the starting day 1970-1-1 which was Thursday
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> dayOfWeek {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        vector<int> dayOfMonth {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> presum{0};
        for (int d : dayOfMonth) {
            presum.emplace_back(presum.back() + d);
        }

        int leapYearDays = 0;
        if (month < 3) {
            leapYearDays = getNumOfLeapYear(year - 1);
        }
        else {
            leapYearDays = getNumOfLeapYear(year);
        }

        int days = (year - 1970) * 365 + presum[month - 1] + day - 1 + leapYearDays;

        return dayOfWeek[(days % 7 + 3) % 7];
    }
};

void testDayOfTheWeek() {
    Solution solution;

    int day1 = 31, month1 = 8, year1 = 2019;
    cout << solution.dayOfTheWeek(day1, month1, year1) << endl;

    int day2 = 18, month2 = 7, year2 = 1999;
    cout << solution.dayOfTheWeek(day2, month2, year2) << endl;

    int day3 = 15, month3 = 8, year3 = 1993;
    cout << solution.dayOfTheWeek(day3, month3, year3) << endl;

    int day4 = 29, month4 = 2, year4 = 2016;
    cout << solution.dayOfTheWeek(day4, month4, year4) << endl;
}

int main() {
    testDayOfTheWeek();

    return 0;
}