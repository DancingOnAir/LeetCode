#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        if (n < 2)
            return 0;

        int res = 0;
        
        return res;
    }
};

void testMaxProduct()
{
    std::vector<std::string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    Solution solution;

    cout << solution.maxProduct(words) << endl;
}

int main()
{
    testMaxProduct();

    getchar();
    return 0;
}