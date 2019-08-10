#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

string simplifyPath(string path)
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
    cout << res3 << endl;
}

int main()
{
    testSimplifyPath();

    getchar();
    return 0;
}