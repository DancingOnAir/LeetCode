//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string addStrings2(string num1, string num2)
//{
//    int d1 = 0, d2 = 0, additional = 0;
//    string res;
//    while (!num1.empty() || !num2.empty() || additional)
//    {
//        if (num1.empty())
//            d1 = 0;
//        else
//        {
//            
//            d1 = num1.back() - '0';
//            num1.pop_back();
//        }
//
//        if (num2.empty())
//            d2 = 0;
//        else
//        {
//            d2 = num2.back() - '0';
//            num2.pop_back();
//        }
//
//        int digit = (d1 + d2 + additional) % 10;
//        additional = (d1 + d2 + additional) / 10;
//        res = to_string(digit) + res;
//    }
//
//    return res;
//}
//
//string addStrings(string num1, string num2)
//{
//    int s1 = num1.size() - 1;
//    int s2 = num2.size() - 1;
//    int carry = 0;
//
//    string res("");
//    while (s1 >= 0 || s2 >= 0 || carry)
//    {
//        int sum = 0;
//        if (s1 >= 0)
//            sum += (num1[s1] - '0'); --s1;
//        if (s2 >= 0)
//            sum += (num2[s2] - '0'); --s2;
//
//        sum += carry;
//        carry = sum / 10;
//        sum %= 10;
//        res += to_string(sum);
//    }
//
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//void testAddStrings()
//{
//    cout << addStrings("12", "988") << endl;
//}
//
//int main()
//{
//    testAddStrings();
//
//    getchar();
//    return 0;
//}