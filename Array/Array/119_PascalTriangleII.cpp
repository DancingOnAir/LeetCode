#include <iostream>
#include <vector>

using namespace std;

vector<int> getNext(vector<int>& nums)
{
    vector<int> next;
    next.emplace_back(1);
    for (int i = 1; i <nums.size(); ++i)
    {
        next.emplace_back(nums[i] + nums[i - 1]);
    }
    next.emplace_back(1);

    return next;
}

vector<int> getRow(int rowIndex)
{
    vector<int> result;
    if (rowIndex < 0)
        return result;

    result.emplace_back(1);
    if (0 == rowIndex)
        return result;

    result.emplace_back(1);
    if (1 == rowIndex)
        return result;

    while (rowIndex - 2 >= 0)
    {
        result = getNext(result);
        --rowIndex;
    }

    return result;
}

void testGetRow()
{
    auto result = getRow(3);
    for (auto& x : result)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testGetRow();
    getchar();
}