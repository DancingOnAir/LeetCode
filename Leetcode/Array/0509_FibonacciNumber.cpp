#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N < 2)
            return N;
        
        int a = 0, b = 1, res = 0;
        for (int i = 2; i <= N; ++i) {
            res = a + b;
            a = b;
            b = res;
        }

        return res;
    }

    int fib1(int N) {
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