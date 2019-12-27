//#include <iostream>
//#include <string>
//#include <assert.h>
//#include <vector>
//#include <bitset>
//using namespace std;
//
//bool isNumber2(string s)
//{
//    int n = s.size();
//    if (0 == n)
//        return false;
//
//    int i = 0;
//    int countNum = 0, countPoint = 0;
//    while (s[i] == ' ')
//        ++i;
//
//    if (s[i] == '+' || s[i] == '-')
//        ++i;
//
//    while (isdigit(s[i]) || s[i] == '.')
//        s[i++] == '.' ? countPoint++ : countNum++;
//
//    if (countPoint > 1 || countNum < 1)
//        return false;
//
//    if (s[i] == 'e')
//    {
//        ++i;
//        countNum = 0;
//        countPoint = 0;
//        if (s[i] == '+' || s[i] == '-')
//            ++i;
//
//        while (isdigit(s[i]) || s[i] == '.')
//            s[i++] == '.' ? countPoint++ : countNum++;
//
//        if (countPoint > 0 || countNum < 1)
//            return false;
//    }
//
//    while (s[i] == ' ')
//        ++i;
//
//    return n == i;
//}
//
////Use Deterministic Finite Automata method can make code elegant
////Define input types :
////(1) T0 : Digit : 0 - 9
////(2) T1 : Sign : '+', '-'
////(3) T2 : 'e'
////(4) T3 : '.'
////(5) T4 : Blank
////(6) T5 : Others
////Define states :
////(1) Q0 : initial states; can accept digit(go to Q2), sign(go to Q1), '.' (has not found any digit, so go to Q3), blank(stay at Q0), other input lead to rejection
////(2) Q1: find sign at the beginning; can accept digit(go to Q2), '.' (has not found any digit, so go to Q3), other input lead to rejection
////(3) Q2: find digit, but has not found '.'; can accept digit(stay at Q2), 'e' (go to Q5), '.' (now find digit, can go to Q4), blank(go to Q8), other input lead to rejection
////(4) Q3: find '.', but has not found any digit; can only accept digit(find digit, now can go to Q4), other input lead to rejection
////(5) Q4: find '.', and has already find some digits; can accept digit(stay at Q4), 'e' (go to Q5), blank(go to Q8), other input lead to rejection
////(6) Q5: find 'e'; can accept digit(digit before 'e' and after 'e' can lead to different states, so go to Q7), sign(sign before 'e' and after 'e' can lead to different states, so go to Q6), other input lead to rejection
////(7) Q6: find sign after e; can only accept digit(go to Q7), other input lead to rejection
////(8) Q7: find digit after e; can accept digit(stay at Q7), and blank(go to Q8)
////(9) Q8: find blank; can only accept blank(Q8), other input lead to rejection
//int inputType(char c)
//{
//    if (isdigit(c))
//        return 0;
//    if (c == '+' || c == '-')
//        return 1;
//    if (c == 'e')
//        return 2;
//    if (c == '.')
//        return 3;
//    if (c == ' ')
//        return 4;
//    else
//        return 5;
//}
//
//bool isNumber(string s)
//{
//    int state = 0;
//    vector<vector<int>> transferTable = {
//        {2, 1, -1, 3, 0 , -1},
//        {2, -1, -1, 3, -1, -1},
//        {2, -1, 5, 4, 8, -1},
//        {4, -1, -1, -1, -1, -1},
//        {4, -1, 5, -1, 8, -1},
//        {7, 6, -1, -1, -1, -1},
//        {7, -1, -1, -1, -1, -1},
//        {7, -1, -1, -1, 8, -1},
//        {-1, -1, -1, -1, 8, -1}
//    };
//
//    bitset<9> validStates("110010100");
//    for (char c : s)
//    {
//        int type = inputType(c);
//        state = transferTable[state][type];
//        if (state == -1)
//            return false;
//    }
//    return validStates[state];
//}
//
//void testIsNumber()
//{
//    //assert(isNumber(".1") == true);
//    //assert(isNumber("0") == true);
//    //assert(isNumber("0.1") == true);
//    //assert(isNumber("abc") == false);
//    //assert(isNumber("1 a") == false);
//    //assert(isNumber("2e10") == true);
//    assert(isNumber(" -90e3   ") == true);
//    assert(isNumber(" 1e") == false);
//    assert(isNumber("e3") == false);
//    assert(isNumber(" 6e-1") == true);
//    assert(isNumber(" 99e2.5") == false);
//    assert(isNumber("53.5e93") == true);
//    assert(isNumber(" --6") == false);
//    assert(isNumber("-+3") == false);
//    assert(isNumber("95a54e53") == false);
//
//    return;
//}
//
//int main()
//{
//    testIsNumber();
//
//    getchar();
//    return 0;
//}