#include <string>
#include <sstream>
#include <unordered_map>


using namespace std;
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},{"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},{"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        
        istringstream iss(date);
        string day;
        iss >> day;

        day.pop_back();
        day.pop_back();
        if (day.size() == 1) {
            day = "0" + day;
        }

        string month;
        iss >> month;
        month = months[month];

        string year;
        iss >> year;

        return year + "-" + month + "-" + day;
    }
};

void testReformatDate() {
    Solution solution;

    assert(solution.reformatDate("20th Oct 2052") == "2052-10-20");
    assert(solution.reformatDate("6th Jun 1933") == "1933-06-06");
    assert(solution.reformatDate("26th May 1960") == "1960-05-26");
}

int main() {
    testReformatDate();

    return 0;
}