#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:

    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start == destination)
            return 0;
        
        if (start > destination)
            swap(start, destination);
        
        int clockwiseSum = 0, countclockwiseSum = 0;
        for (int i  = 0; i < distance.size(); ++i) {
            if (i < start || i >= destination) {
                countclockwiseSum += distance[i];
            }
            else {
                clockwiseSum += distance[i];
            }
        }

        return min(clockwiseSum, countclockwiseSum);
    }

    int distanceBetweenBusStops1(vector<int>& distance, int start, int destination) {
        if (start == destination)
            return 0;
        
        int sum = accumulate(distance.begin(), distance.end(), 0);
        int clockwise = 0;
        for (int i = min(start, destination); i < max(start, destination); ++i) {
            clockwise += distance[i];
        }

        return min(clockwise, sum - clockwise);
    }

    int distanceBetweenBusStops2(vector<int>& distance, int start, int destination) {
        if (start == destination)
            return 0;

        vector<int> clockwisePresum{0};
        for (int i = 0; i < distance.size(); ++i) {
            clockwisePresum.emplace_back(clockwisePresum.back() + distance[i]);
        }

        int clockwiseDis = abs(clockwisePresum[destination] - clockwisePresum[start]);
        return min(clockwiseDis, clockwisePresum.back() - clockwiseDis);
    }
};

void testDistanceBetweenBusStops() {
    Solution solution;

    vector<int> distance1 = {1, 2, 3, 4};
    int start1 = 0, destination1 = 1;
    cout << solution.distanceBetweenBusStops(distance1, start1, destination1) << endl;

    vector<int> distance2 = {1, 2, 3, 4};
    int start2 = 0, destination2 = 2;
    cout << solution.distanceBetweenBusStops(distance2, start2, destination2) << endl;

    vector<int> distance3 = {1, 2, 3, 4};
    int start3 = 0, destination3 = 3;
    cout << solution.distanceBetweenBusStops(distance3, start3, destination3) << endl;
}

int main() {
    testDistanceBetweenBusStops();

    return 0;
}