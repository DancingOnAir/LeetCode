#include <string>
#include <unordered_map>

using namespace std;
class UndergroundSystem {
private:
    // id => {entryStation, entryTime}
    unordered_map<int, pair<string, int>> checkInMap;
    // travelName => {overallTime, numberOfTravels}
    // travelName = startStation + ">" + endStation, add the char ">" for distinguishing such "a", "ab" and "aa", "b".
    unordered_map<string, pair<int, int>> avgTimeMap;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        const auto& [startStation, timeIn] = checkInMap[id];
        auto& [totalDuration, tripCnt] = avgTimeMap[startStation + ">" + stationName];
        totalDuration += t - timeIn;
        ++tripCnt;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)avgTimeMap[startStation + ">" + endStation].first / avgTimeMap[startStation + ">" + endStation].second;
    }
};

void testUndergroundSystem() {
    UndergroundSystem undergroundSystem;

    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);

    undergroundSystem.checkOut(45,"Waterloo",15);
    undergroundSystem.checkOut(27,"Waterloo",20);
    undergroundSystem.checkOut(32,"Cambridge",22);

    assert(abs(undergroundSystem.getAverageTime("Paradise","Cambridge") - 14.0) < 1e-3);
    assert(abs(undergroundSystem.getAverageTime("Leyton","Waterloo") - 11.0) < 1e-3);

    undergroundSystem.checkIn(10,"Leyton",24);
    assert(abs(undergroundSystem.getAverageTime("Leyton","Waterloo") - 11.0) < 1e-3);
    undergroundSystem.checkOut(10,"Waterloo",38);
    assert(abs(undergroundSystem.getAverageTime("Leyton","Waterloo") - 12.0) < 1e-3);
}

int main() {
    testUndergroundSystem();

    return 0;
}

