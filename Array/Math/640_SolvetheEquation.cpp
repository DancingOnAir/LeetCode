#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string solveEquation(string equation)
{
    size_t n = equation.size();
    int sign = 1;
    int coefficient = 0, total = 0, res = 0, j = 0;

    for (int i = 0; i < n; ++i)
    {
        //if (equation[i] == '=')
        //    sign = -1;
        //else 
            
        if (equation[i] == '+' || equation[i] == '-')
        {
            if (i > j)
                total += sign * stoi(equation.substr(j, i - j));
            
            j = i;
        }
        else if (equation[i] == 'x')
        {
            if (j == i || equation[i - 1] == '+')
                coefficient += sign;
            else if (equation[i - 1] == '-')
                coefficient -= sign;
            else
                coefficient += sign * stoi(equation.substr(j, i - j));
            
            j = i + 1;
        }
        else if (equation[i] == '=')
        {
            if (i > j)
                total += sign * stoi(equation.substr(j, i - j));

            sign = -1;
            j = i + 1;
        }

    }

    if (j < n)
        total += sign * stoi(equation.substr(j));

    if (total && coefficient == 0)
        return "No solution";
    else if (total == 0 && coefficient == 0)
        return "Infinite solutions";
    else
        return "x=" + to_string(- total / coefficient);
}

void testSolveEquation()
{
    string equation1 = "x+5-3+x=6+x-2";
    cout << solveEquation(equation1) << endl;

    string equation2 = "2x=x";
    cout << solveEquation(equation2) << endl;
}

int main()
{
    testSolveEquation();

    getchar();
    return 0;
}