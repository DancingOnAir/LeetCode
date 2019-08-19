#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//int calculate2(string s) 
//{
//    istringstream iss(s);
//
//    vector<int> nums;
//    vector<char> signs;
//
//    while (iss)
//    {
//        int num = 0;
//        char sign = ' ';
//
//        iss >> num >> sign;
//
//        if (!signs.empty() && (signs.back() == '*' || signs.back() == '/'))
//        {
//            int pre = nums.back();
//            if (signs.back() == '*')
//            {
//                num = pre * num;
//            }
//            else if (signs.back() == '/')
//            {
//                num = pre / num;
//            }
//
//            nums.pop_back();
//            signs.pop_back();
//        }
//
//        nums.emplace_back(num);
//        signs.emplace_back(sign);
//    }
//
//    signs.pop_back();
//
//    int res = nums[0];
//    for (int i = 0; i < signs.size(); ++i)
//    {
//        if (signs[i] == '+')
//            res += nums[i + 1];
//        else
//            res -= nums[i + 1];
//    }
//
//    return res;
//}

int calculate(string s)
{
    istringstream iss("+" + s + "+");

    long long total = 0, term = 0, num = 0;
    char op;

    while (iss >> op)
    {
        if (op == '+' || op == '-')
        {
            total += term;
            iss >> term;
            term *= 44 - op;
        }
        else
        {
            iss >> num;
            if (op == '*')
                term *= num;
            else
                term /= num;
        }
    }

    return total;
}

void testCalculate()
{
    string s1 = "3+2*2";
    cout << calculate(s1) << endl;

    string s2 = " 3/2 ";
    cout << calculate(s2) << endl;

    string s3 = " 3+5 / 2 ";
    cout << calculate(s3) << endl;
}

int main()
{
    testCalculate();

    getchar();
    return 0;
}