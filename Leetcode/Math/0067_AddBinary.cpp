//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string addBinary(string a, string b)
//{
//    if (a.empty() || b.empty())
//        return "";
//
//    int l1 = a.size();
//    int l2 = b.size();
//
//    if (l1 < l2)
//        return addBinary(b, a);
//
//    string res("");
//    int carry = 0;
//    for (int i = l2 - 1; i >= 0; --i)
//    {
//        int temp = (a[l1 - l2 + i] - '0') + (b[i] - '0') + carry;
//        res = to_string(temp % 2) + res;
//        carry = temp / 2;
//    }
//
//    for (int i = l1 - l2 - 1; i >= 0; --i)
//    {
//        int temp = (a[i] - '0') + carry;
//        res = to_string(temp % 2) + res;
//        carry = temp / 2;
//    }
//
//    if (carry == 1)
//        res = to_string(carry) + res;
//
//    return res;
//}
//
//string addBinary2(string a, string b)
//{
//    string res("");
//    int l1 = a.size() - 1;
//    int l2 = b.size() - 1;
//
//    int carry = 0;
//    while (l1 >= 0 || l2 >= 0 || carry > 0)
//    {
//        carry += l1 >= 0 ? a[l1--] - '0' : 0;
//        carry += l2 >= 0 ? b[l2--] - '0' : 0;
//        res = char(carry % 2 + '0') + res;
//        carry /= 2;
//    }
//
//    return res;
//}
//
//void testAddBinary()
//{
//    //cout << addBinary2("100", "110010") << endl;
//    cout << addBinary2("11", "1") << endl;
//    cout << addBinary2("1010", "1011") << endl;
//}
//
//int main()
//{
//    testAddBinary();
//    getchar();
//    return 0;
//}