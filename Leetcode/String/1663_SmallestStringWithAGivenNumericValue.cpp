#include <string>

using namespace std;
class Solution {
public:
    // greedy
    string getSmallestString(int n, int k) {
        string res(n , 'a');
        int i = n - 1;

        k -= n;
        while (i >= 0 && k > 0) {
            res[i] += min(k , 25);
            k -= min(k, 25);
            --i;
        }

        return res;
    }

    // math
    string getSmallestString1(int n, int k) {
        int numOfZ = (k - n) / 25;
        return numOfZ >= n? string(numOfZ, 'z'): string((n - numOfZ - 1), 'a') + string(1, 'a' + (k - n) % 25) + string(numOfZ, 'z');
    }
};

void testGetSmallestString() {
    Solution solution;

    assert(solution.getSmallestString(3, 27) == "aay");
    assert(solution.getSmallestString(5, 73) == "aaszz");
}

int main() {
    testGetSmallestString();

    return 0;
}