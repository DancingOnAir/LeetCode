#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) 
{
    if (k < 0)
        return;

    int pos = k % nums.size();

    std::vector<int> result;

    result.insert(result.begin(), nums.begin() + nums.size() - pos, nums.end());
    result.insert(result.begin() + pos, nums.begin(), nums.begin() + nums.size() - pos);

    nums = result;
}

int main()
{
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(input, k);

    for (int x : input)
        std::cout << x << ", ";

    std::cout << std::endl;

    system("pause");
    return 0;
}