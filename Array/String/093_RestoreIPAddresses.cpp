#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

void helper(string& s, vector<string>& res, int pos, string ipAddr, int counter)
{
    if (counter == 4 && pos == s.size())
    {
        res.emplace_back(ipAddr);
        return;
    }

    for (int i = 1; i < 4; ++i)
    {
        if (pos + i > s.size())
            break;

        string temp = s.substr(pos, i);
        if (stoi(temp) > 256 || (temp.size() > 1 && temp[0] == '0'))
            break;
        helper(s, res, pos + i, counter == 0 ? temp : ipAddr + "." + temp, counter + 1);
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    int n = s.size();
    if (n < 4 || n > 12)
        return res;

    helper(s, res, 0, "", 0);
    return res;
}

void testRestoreIpAddresses()
{
    string input1{ "25525511135" };
    auto res1 = restoreIpAddresses(input1);
    
    for (auto& s : res1)
        cout << s << ", ";
    cout << endl;
}

int main()
{
    testRestoreIpAddresses();

    getchar();
    return 0;
}