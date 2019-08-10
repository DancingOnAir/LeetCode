#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <sstream>
using namespace std;

string simplifyPath2(string path)
{
    if (path.empty())
        return "";

    vector<string> folders;
    int pos = 0, len = 0;
    int n = path.size();

    while (pos < n)
    {
        if (path[pos] == '/')
        {
            ++pos;
        }
        else
        {
            while (pos + len < n && path[pos + len] != '/')
            {
                ++len;
            }
            folders.emplace_back(path.substr(pos, len));
            pos += len;
            len = 0;
        }
    }

    string res("");
    int numOfUplevel = 0;
    for (auto iter = folders.rbegin(); iter != folders.rend(); ++iter)
    {
        if (*iter == ".")
            continue;

        else if (*iter == "..")
        {
            ++numOfUplevel;
        }
        else
        {
            if (numOfUplevel)
                --numOfUplevel;
            else
                res = '/' + *iter + res;
        }
    }

    if (res.empty())
        res += '/';

    return res;
}

string simplifyPath(string path)
{
    string res, temp;
    if (path.empty())
        return res;

    istringstream iss(path);
    vector<string> stk;
    while (getline(iss, temp, '/'))
    {
        if (temp == "" || temp == ".")
            continue;
        if (temp == ".." && !stk.empty())
            stk.pop_back();
        else if (temp != "..")
            stk.emplace_back(temp);
    }

    for (auto s : stk)
        res += "/" + s;
    return res.empty() ? "/" : res;
}

void testSimplifyPath()
{
    string path1 = "/home/";
    string res1 = simplifyPath(path1);
    assert(res1 == "/home");

    string path2 = "/../";
    auto res2 = simplifyPath(path2);
    assert("/" == res2);

    string path3 = "/a/./b/../../c/";
    auto res3 = simplifyPath(path3);
    assert("/c" == res3);

    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
}

int main()
{
    testSimplifyPath();

    getchar();
    return 0;
}