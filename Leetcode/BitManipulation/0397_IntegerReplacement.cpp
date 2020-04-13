#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> m;
public:
    int integerReplacement(int n) {
        if (n == 1)
            return 0;

        if (!m.count(n)) {
            if (n & 1) {
                m[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
            } else {
                m[n] = 1 + integerReplacement(n / 2);
            }
        }
            
        return m[n];
    }
};

void testIntegerReplacement() {
    Solution solution;

    cout << solution.integerReplacement(8) << endl;
    cout << solution.integerReplacement(7) << endl;
}

int main() {
    testIntegerReplacement();

    return 0;
}