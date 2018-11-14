#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    vector<int> result;
    if (digits.empty())
        return result;

    reverse(digits.begin(), digits.end());
    int carry = 0;
    for (size_t i = 0; i < digits.size(); ++i)
    {
        if (0 == i)
            digits[i] += 1;

        digits[i] += carry;
        if (digits[i] > 9)
        {
            digits[i] %= 10;
            carry = 1;
        }
        else
            carry = 0;
    }

    if (1 == carry)
        digits.emplace_back(1);
    reverse(digits.begin(), digits.end());

    return digits;
}

void testPlusOne()
{
    vector<int> digits = { 9, 9, 9, 9 };
    auto result = plusOne(digits);

    for (auto& d : result)
        cout << d << ", ";
    cout << endl;
}

int main()
{
    testPlusOne();
    std::getchar();
}