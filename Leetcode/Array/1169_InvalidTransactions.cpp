#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if (transactions.empty())
            return vector<string>();

        int n = transactions.size();
        vector<int> invalid(n, false);
        vector<string> res;
        // name, time, city
        unordered_map<string, map<int, pair<string, int>>> m;
        for (int i = 0; i< n; ++i) {
            istringstream iss(transactions[i]);
            string name;
            string time;
            string amount;
            string city;

            getline(iss, name, ',');
            getline(iss, time, ',');
            getline(iss, amount, ',');
            getline(iss, city, ',');
            
            if (stoi(amount) > 1000) {
                res.emplace_back(transactions[i]);
                invalid[i] = true;
            }

            if (m.count(name)) {
                auto prevTime = m[name].lower_bound(stoi(time) - 60);
                auto nextTime = m[name].upper_bound(stoi(time) + 60);
                for (auto iter = prevTime; iter != nextTime; ++iter) {
                    if (iter->second.first != city) {
                        if (!invalid[iter->second.second]) {
                            res.emplace_back(transactions[iter->second.second]);
                            invalid[iter->second.second] = true;
                        }


                        if (!invalid[i]) {
                            res.emplace_back(transactions[i]);
                            invalid[i] = true;
                        }
                    }
                }
            }

            m[name][stoi(time)] = {city, i};
        }

        return res;
    }
};

void printTransactions(const vector<string>& transactions) {
    for (auto& trans : transactions) {
        cout << trans << ", ";
    }

    cout << endl;
}

void testInvalidTransactions() {
    Solution solution;

    vector<string> trans1 {"alice,20,800,mtv", "alice,50,100,beijing"};
    auto res1 = solution.invalidTransactions(trans1);
    printTransactions(res1);

    vector<string> trans2 {"alice,20,800,mtv", "alice,50,1200,mtv"};
    auto res2 = solution.invalidTransactions(trans2);
    printTransactions(res2);

    vector<string> trans3 {"alice,20,800,mtv", "bob,50,1200,mtv"};
    auto res3 = solution.invalidTransactions(trans3);
    printTransactions(res3);
}

int main() {
    testInvalidTransactions();

    return 0;
}