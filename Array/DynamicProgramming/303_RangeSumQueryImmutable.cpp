#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums)
    {
        int n = nums.size();
        if (0 == n)
            return;

        accu.emplace_back(0);
        for (int num : nums)
        {
            accu.emplace_back(accu.back() + num);
        }
    }

    int sumRange(int i, int j)
    {
        if (i > j)
            return 0;

        return accu[j + 1] - accu[i];
    }

private:
    vector<int> accu;
};

void testNumArray()
{
    vector<int> nums{ -2, 0, 3, -5, 2, -1 };

    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
}

int main()
{
    testNumArray();

    getchar();
    return 0;
}