#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class SummaryRanges {
private:
    vector<vector<int>> intervals;
public:
    SummaryRanges() {
        intervals = {{-10, -10}, {10010, 10010}};
    }
    
    void addNum(int value) {
        int left = 0, right = intervals.size() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] == value) {
                return;
            }
            else if (intervals[mid][0] < value) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        vector<int> cur = {value, value};
        auto pre = intervals[left - 1];
        auto nxt = intervals[left];
        if ((pre[0] <= value && pre[1] >= value) || (nxt[0] <= value && nxt[1] >= value)) {
            return;
        }
        else if (pre[1] + 1 == value && nxt[0] - 1 == value) {
            intervals[left - 1][1] = intervals[left][1];
            intervals.erase(intervals.begin() + left);
        }
        else if (pre[1] + 1 == value) {
            intervals[left - 1][1] = value;
        }
        else if (nxt[0] - 1 == value) {
            intervals[left][0] = value;
        }
        else {
            intervals.insert(intervals.begin() + left, cur);
        }
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(intervals.begin() + 1, intervals.end() - 1);
    }
};

void printIntervals(vector<vector<int>> intervals) {
    for (auto& r : intervals) {
        cout << "[";
        for (auto& c : r) {
            cout <<  c << ", ";
        }
        cout << "], ";
    }
}

void testSummaryRanges() {
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);
    printIntervals(summaryRanges.getIntervals());
    summaryRanges.addNum(3);
    printIntervals(summaryRanges.getIntervals());
    summaryRanges.addNum(7);
    printIntervals(summaryRanges.getIntervals());
    summaryRanges.addNum(2);
    printIntervals(summaryRanges.getIntervals());
    summaryRanges.addNum(6);
    printIntervals(summaryRanges.getIntervals());
}

int main() {
    testSummaryRanges();
    return 0;
}