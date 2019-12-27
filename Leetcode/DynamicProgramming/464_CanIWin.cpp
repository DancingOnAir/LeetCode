//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_set>
//#include <unordered_map>
//using namespace std;
//
//bool canWin(int maxInt, int tot, unordered_map<int, bool>& memo, int usedBits)
//{
//    if (tot <= 0)
//        return false;
//
//    if (memo.find(usedBits) != memo.end())
//        return memo[usedBits];
//
//    for (int i = 1; i <= maxInt; ++i)
//    {
//        int bit = 1 << i;
//        if (usedBits & bit)
//            continue;
//
//        if (!canWin(maxInt, tot - i, memo, usedBits | bit))
//        {
//            return memo[usedBits] = true;
//        }
//    }
//
//    return memo[usedBits] = false;
//}
//
//bool canIWin(int maxChoosableInteger, int desiredTotal)
//{
//    if (desiredTotal < 2)
//        return true;
//
//    if ((maxChoosableInteger + 1) * maxChoosableInteger >> 1 < desiredTotal)
//        return false;
//
//    unordered_map<int, bool> memo;
//    return canWin(maxChoosableInteger, desiredTotal, memo, 0);
//}
//
//void testCanIWin()
//{
//    int maxChoosableInteger = 10;
//    int desiredTotal = 11;
//
//    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testCanIWin();
//
//    getchar();
//    return 0;
//}