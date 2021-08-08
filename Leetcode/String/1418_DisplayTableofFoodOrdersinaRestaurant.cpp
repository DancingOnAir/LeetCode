#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<unordered_map<string, int>> tables(501);
        set<string> foods;

        for (auto& order : orders) {
            foods.insert(order[2]);
            ++tables[stoi(order[1])][order[2]];
        }

        vector<vector<string>> res;
        for (int i = 0; i < 501; ++i) {
            if (i > 0 && tables[i].empty())
                continue;
            res.push_back(vector<string>());
            res.back().push_back(i == 0? "Table" : to_string(i));
            for (auto& f : foods) {
                res.back().push_back(i == 0? f : to_string(tables[i][f]));
            }
        }

        return res;
    }
};

void testDisplayTable() {
    Solution solution;

    vector<vector<string>> orders1 = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    vector<vector<string>> res1 = {{"Table","Beef Burrito","Ceviche","Fried Chicken","Water"},{"3","0","2","1","0"},{"5","0","1","0","1"},{"10","1","0","0","0"}};
    assert(solution.displayTable(orders1) == res1);

    vector<vector<string>> orders2 = {{"James","12","Fried Chicken"},{"Ratesh","12","Fried Chicken"},{"Amadeus","12","Fried Chicken"},{"Adam","1","Canadian Waffles"},{"Brianna","1","Canadian Waffles"}};
    vector<vector<string>> res2 = {{"Table","Canadian Waffles","Fried Chicken"},{"1","2","0"},{"12","0","3"}};
    assert(solution.displayTable(orders2) == res2);

    vector<vector<string>> orders3 = {{"Laura","2","Bean Burrito"},{"Jhon","2","Beef Burrito"},{"Melissa","2","Soda"}};
    vector<vector<string>> res3 = {{"Table","Bean Burrito","Beef Burrito","Soda"},{"2","1","1","1"}};
    assert(solution.displayTable(orders3) == res3);
}

int main() {
    testDisplayTable();

    return 0;
}