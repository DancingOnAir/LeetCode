#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void backtrack(std::vector<std::vector<int>>& result, vector<int>& temp, std::vector<int>& candidates, int target, int depth)
{
    int sum = 0;
    for (int x : temp)
    {
        sum += x;
    }

    if (sum > target)
        return;

    if (sum == target)
    {
        vector<int> t(temp);
        std::sort(t.begin(), t.end());
        auto iter = std::find(result.begin(), result.end(), t);

        if (iter == result.end())
            result.push_back(temp);
        return;
    }

    for (int i = 0; i < candidates.size(); ++i)
    {
        temp.push_back(candidates[i]);
        backtrack(result, temp, candidates, target, i + 1);
        temp.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
{
    std::vector<std::vector<int>> result;
    vector<int> temp;
    backtrack(result, temp, candidates, target, 0);

    return result;
}

int main()
{
    std::vector<int> candidates = { 1, 2 };
    int target = 4;
    std::vector<std::vector<int>> result = combinationSum(candidates, target);

    for (auto row : result)
    {
        for (auto col : row)
            cout << col << ", ";
        cout << endl;
    }

    system("pause");
    return 0;
}