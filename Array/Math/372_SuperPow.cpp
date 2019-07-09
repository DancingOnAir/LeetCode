#include <iostream>
#include <vector>

using namespace std;

int superPow2(int a, vector<int>& b)
{
    if (b.empty())
        return 0;
    
    int idx = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        idx = idx * 10 + b[i];
    }

    

    int num = 1, temp = 0;
    vector<int> records;
    while (idx > 0)
    {
        num *= a;
        num = num % 1337;
        if (find(records.begin(), records.end(), num) != records.end())
            break;
        else
            records.emplace_back(num);

        --idx;
    }

    if (idx == 0)
        return records.back();

    int r = idx % records.size();
    return records[r];
}

int powmod(int a, int k)
{
    a %= 1337;
    int result = 1;

    for (int i = 0; i < k; ++i)
        result = (result * a) % 1337;

    return result;
}

int superPow(int a, vector<int>& b)
{
    if (b.empty())
        return 1;

    int lastDigit = b.back();
    b.pop_back();

    return powmod(superPow(a, b), 10) * powmod(a, lastDigit) % 1337;
}

void testSuperPow()
{
    vector<int> b1 = { 3 };
    cout << superPow(2, b1) << endl;

    vector<int> b2 = { 1, 0 };
    cout << superPow(2, b2) << endl;
}

int main()
{
    testSuperPow();
    getchar();
    return 0;
}