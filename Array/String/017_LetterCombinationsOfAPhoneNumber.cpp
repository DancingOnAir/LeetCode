#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

//vector<string> letterCombinations(string digits)
//{
//	if (digits.empty()) 
//		return vector<string>();
//
//	vector<string> vec = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//	vector<string> result(1, "");
//
//	for (auto d : digits)
//	{
//		int iVal = d - '0';
//		if (iVal >= 0 && iVal <= 9)
//		{
//			string candidate = vec[iVal];
//			if (candidate.empty())
//				continue;
//
//			vector<string> temp;
//			for (decltype(candidate.size()) j = 0; j < candidate.size(); ++j)
//				for (decltype(result.size()) k = 0; k < result.size(); ++k)
//					temp.push_back(result[k] + candidate[j]);
//			
//			result.swap(temp);
//		}
//		else
//			break;
//	}
//
//	return result;
//}

void backtrack(vector<string>& alphabets, vector<int>& nums, vector<string>& result, string& current, int k)
{
    if (k == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < alphabets[nums[k]].size(); ++i)
    {
        current.push_back(alphabets[nums[k]][i]);
        backtrack(alphabets, nums, result, current, k + 1);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits) 
{
    vector<string> result;
    if (digits.empty())
        return result;

    string current;
    //0 - 9
    vector<string> alphabets = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<int> nums;
    for (auto val : digits)
    {
        nums.push_back(val - '0');
    }

    backtrack(alphabets, nums, result, current, 0);

    return result;
}

int main(void)
{
    string digits = "23";

    vector<string> result = letterCombinations(digits);

    for (auto val : result)
	    cout << val << ", ";

    cout << endl;

    system("pause");
    return 0;
}