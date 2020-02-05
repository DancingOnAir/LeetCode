#pragma once
#include <string>
using namespace std;


class Solution
{
public:
    bool isPalindrome(string& str)
    {
        if (str.empty())
            return false;

        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
                return false;

            ++i;
            --j;
        }

        return true;
    }

    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        if (n < 2)
            return "";

        for (int i = 0; i < n; ++i)
        {
            char temp = palindrome[i];
            if (temp > 'a')
            {
                palindrome[i] = 'a';
                
                if (!isPalindrome(palindrome))
                    return palindrome;

                palindrome[i] = temp;
            }

            if (i == n - 1)
                palindrome[i] = 'b';
        }

        return palindrome;
    }
};