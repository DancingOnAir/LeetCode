#include <string>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/discuss/1269086/Very-Very-Easy-to-understand-C%2B%2B-No-Recursion-Ask-Doubts-in-Comments
    // https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/discuss/1268245/Six-Cases
    // pair<char, int> represents {expression, cost to change that expression}, eg. if expr = '1', the cost is 1 to change '1' to '0', so {'1', 1}
    int minOperationsToFlip(string expression) {
        stack<pair<char, int>> stk;
        pair<char, int> p;
        char char1, char2, cost1, cost2, op;

        for (auto i = 0; i < expression.size(); ++i) {
            if (expression[i] == '(' || expression[i] == '&' || expression[i] == '|') {
                stk.push({expression[i], 0});
            }
            else {
                if (expression[i] == ')') {
                    p = stk.top();
                    stk.pop();
                    // when we meets ')', the stack will store data like 'xxxx(x', so we should pop out last 2 elements.
                    stk.pop();
                }
                // expresssion[i] = '0' or '1'
                else {
                    p = {expression[i] , 1};
                }
                
                while (!stk.empty() && (stk.top().first == '&' or stk.top().first == '|')) {
                    op = stk.top().first;
                    stk.pop();

                    char2 = p.first;
                    cost2 = p.second;

                    char1 = stk.top().first;
                    cost1 = stk.top().second;
                    stk.pop();

                    if (op == '&' && char1 == '1' && char2 == '1') p = {'1', min(cost1, cost2)};
                    if (op == '&' && char1 == '1' && char2 == '0') p = {'0', 1};
                    if (op == '&' && char1 == '0' && char2 == '1') p = {'0', 1};
                    if (op == '&' && char1 == '0' && char2 == '0') p = {'0', 1 + min(cost1, cost2)};

                    if (op == '|' && char1 == '1' && char2 == '1') p = {'1', 1 + min(cost1, cost2)};
                    if (op == '|' && char1 == '1' && char2 == '0') p = {'1', 1};
                    if (op == '|' && char1 == '0' && char2 == '1') p = {'1', 1};
                    if (op == '|' && char1 == '0' && char2 == '0') p = {'0', min(cost1, cost2)};
                }
                stk.push(p);
            }
        }

        return stk.top().second;
    }
};

void testMinOperationsToFlip() {
    Solution solution;

    // assert(solution.minOperationsToFlip("1&(0|1)") == 1);
    assert(solution.minOperationsToFlip("(0&0)&(0&0&0)") == 3);
    assert(solution.minOperationsToFlip("(0|(1|0&1))") == 1);
}

int main() {
    testMinOperationsToFlip();

    return 0;
}