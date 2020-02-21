#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
    {
        if (customers.empty())
            return 0;

        vector<int> m(X);
        int left = 0, right = 0, sum = 0, count = 0, maxDissatisfiedCustomers = 0;

        while (right < customers.size())
        {
            if (grumpy[right])
                count += customers[right];
            else
                sum += customers[right];
            ++right;

            while (right - left == X)
            {
                maxDissatisfiedCustomers = max(maxDissatisfiedCustomers, count);
                if (grumpy[left])
                    count -= customers[left];
                ++left;
            }
        }

        return sum + maxDissatisfiedCustomers;
    }
};
