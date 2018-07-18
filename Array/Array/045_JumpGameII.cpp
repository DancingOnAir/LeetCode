#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <algorithm>

using namespace std;
void display(const vector<int> &vec)
{
    for (const int v : vec)
    {
        cout << v << endl;
    }
}

int jump(vector<int>& nums) 
{
    if (!nums.size() || nums.size() == 1)
        return 0;

    vector<int> vec;
    vec.push_back(nums[0]);
    auto iter = nums.begin();
    
    while (nums.end() - 1 - iter >  vec[vec.size() - 1])
    {
        int max = 0;
        int temp;
        auto start = iter;
        for (auto i = start + 1; i != start + vec[vec.size() - 1] + 1; ++i)
        {
            int len = std::distance(start, i);
            int val = *i;

            if (max < len + val)
            {
                max = len + val;
                iter = i;
                temp = val;
            }
        }

        vec.push_back(temp);
    }

    return vec.size();
}

int main()
{
    vector<int> input1 = {2, 3, 1, 1, 4};
    vector<int> input2 = { 1, 2, 1, 1, 1 };
    vector<int> input3 = { 1, 3, 2 };
    vector<int> input4 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0 };
    display(input4);
    cout << jump(input4) << endl;

    system("pause");
    return 0;
}