#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;



class Solution {
public:

    int gcd(int lhs, int rhs) {
        return (rhs == 0) ? lhs : gcd(rhs, lhs % rhs);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        if (n < 2)
            return false;
        
        unordered_map<int, int> m;
        for (int i : deck) {
            m[i]++;
        }

        int res = 0;
        for (auto& i : m) {
            res = gcd(i.second, res);
        }

        return res > 1;
    }
};

void testHasGroupsSizeX() {
    Solution solution;

    vector<int> deck1 {1, 2, 3, 4, 4, 3, 2, 1};
    cout << (solution.hasGroupsSizeX(deck1)? "True" : "False") << endl;

    vector<int> deck2 {1, 1, 1, 2, 2, 2, 3, 3};
    cout << (solution.hasGroupsSizeX(deck2)? "True" : "False") << endl;

    vector<int> deck3 {1};
    cout << (solution.hasGroupsSizeX(deck3)? "True" : "False") << endl;

    vector<int> deck4 {1, 1};
    cout << (solution.hasGroupsSizeX(deck4)? "True" : "False") << endl;

    vector<int> deck5 {1, 1, 2, 2, 2, 2};
    cout << (solution.hasGroupsSizeX(deck5)? "True" : "False") << endl;
}

int main() {
    testHasGroupsSizeX();

    return 0;
}