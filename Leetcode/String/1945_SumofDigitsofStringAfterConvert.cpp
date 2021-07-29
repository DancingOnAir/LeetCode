#include <string>
#include <sstream>

using namespace std;
class Solution {
public:
    int getLucky(string s, int k) {
        string convert;
        for (char c : s) {
            convert += to_string(c - 96);
        }
        
        int total = 0;
        stringstream ss;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < convert.size(); ++j) {
                total += (convert[j] - '0');
            }
            
            convert = to_string(total);
            total = 0;
        }

        return stoi(convert);
    }
};

void testGetLucky() {
    Solution solution;
    assert(solution.getLucky("iiii", 1) == 36);
    assert(solution.getLucky("leetcode", 2) == 6);
    assert(solution.getLucky("zbax", 2) == 8);
}

int main() {
    testGetLucky();

    return 0;
}