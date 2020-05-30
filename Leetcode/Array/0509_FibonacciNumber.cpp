#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N < 2) {
            return N;
        }
        
        return fib(N - 1) + fib(N - 2);
    }
};

void testFib() {
    Solution solution;

    cout << solution.fib(2) << endl;
    cout << solution.fib(3) << endl;
    cout << solution.fib(4) << endl;
}

int main() {
    testFib();

    return 0;
}