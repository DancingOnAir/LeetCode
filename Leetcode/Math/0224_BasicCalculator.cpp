#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
private:
    void calc(stack<int>& nums, stack<char>& ops) {
        if (nums.size() < 2) {
            ops.pop();
            return;
        }

        int num2 = nums.top();
        nums.pop();

        int num1 = nums.top();
        nums.pop();

        char op = ops.top();
        ops.pop();
        nums.emplace(num1 + num2 * (op == '+' ? 1 : -1));
    }

public:
    int calculate(string s) {
        stack<int> nums;
        nums.emplace(0);

        stack<char> ops;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                ops.emplace(c);
            }
            else if (c == ')') {
                while (!ops.empty()) {
                    char op = ops.top();
                    if (op != '(')
                        calc(nums, ops);
                    else {
                        ops.pop();
                        break;
                    }
                    
                }
            }
            else if (isdigit(c)) {
                int j = i;
                int num = 0;
                while (j < s.size() && isdigit(s[j])) {
                    num = num * 10 + (s[j++] - '0');
                }
                nums.emplace(num);
                i = j - 1;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' )) {
                    nums.emplace(0);
                }

                while (!ops.empty() && ops.top() != '(') {
                    calc(nums, ops);
                }

                ops.emplace(c);
            }
        }

        while (!ops.empty() && ops.top() != '(') {
            calc(nums, ops);
        }

        return nums.top();
    }

    int calculate1(string s) {
        stack<int> signs;
        int num = 0, res = 0, sign = 1;
        signs.emplace(sign);
        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '(')
                signs.emplace(sign);
            else if (c == ')')
                signs.pop();
            else if (c == '+' || c == '-')
            {
                res += sign * num;
                num = 0;
                sign = signs.top() * (c == '+' ? 1 : -1);
            }
        }

        return res + sign * num;
    }
};

void testCalculate()
{
    Solution solution;
    assert(solution.calculate("2-(5-6)") == 3);
    assert(solution.calculate("1-1") == 0);
    assert(solution.calculate("123 + 45") == 168);
    assert(solution.calculate("1 + 1") == 2);
    assert(solution.calculate("2-1 + 2") == 3);
    assert(solution.calculate("(1+(4+5+2)-3)+(6+8)") == 23);
}

int main()
{
    testCalculate();

    return 0;
}