#include <string>

using namespace std;
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int ts = 60 * stoi(startTime.substr(0, 2)) + stoi(startTime.substr(3));
        int tf = 60 * stoi(finishTime.substr(0, 2)) + stoi(finishTime.substr(3));

        if (tf - ts >= 0 && tf - ts < 15)
            return 0;

        return tf / 15 -  (ts + 14) / 15 + (tf < ts) * 96;
    }
};

void testNumberOfRounds() {
    Solution solution;
    assert(solution.numberOfRounds("12:01", "12:44") == 1);
    assert(solution.numberOfRounds("20:00", "06:00") == 40);
    assert(solution.numberOfRounds("00:00", "23:59") == 95);
}

int main() {
    testNumberOfRounds();

    return 0;
}