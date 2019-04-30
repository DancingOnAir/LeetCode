#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> win, lose;

bool canWin(int maxChoosableInteger, int desiredTotal, int usedBits)
{
    if (desiredTotal <= 0)
        return false;

    if (win.find(usedBits) != win.end())
        return true;

    if (lose.find(usedBits) != lose.end())
        return false;

    for (int i = 1; i <= maxChoosableInteger; ++i)
    {
        int bit = 1 << i;
        if (usedBits & bit)
            continue;

        if (!canWin(maxChoosableInteger, desiredTotal - i, usedBits | bit))
        {
            win.insert(usedBits);
            return true;
        }
    }

    lose.insert(usedBits);
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal)
{

    int sum = (maxChoosableInteger + 1) * maxChoosableInteger >> 1;
    
    if (maxChoosableInteger >= desiredTotal)
        return true;

    if (sum < desiredTotal)
        return false;

    if (sum == desiredTotal && maxChoosableInteger & 1)
        return true;

    return canWin(maxChoosableInteger, desiredTotal, 0);
}

void testCanIWin()
{
    int maxChoosableInteger = 10;
    int desiredTotal = 11;

    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "True" : "False") << endl;
}

int main()
{
    testCanIWin();

    getchar();
    return 0;
}