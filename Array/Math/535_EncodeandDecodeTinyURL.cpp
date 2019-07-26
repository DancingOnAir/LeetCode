#include <iostream>
#include <string>

using namespace std;

// Encodes a URL to a shortened URL.
string encode(string longUrl)
{
    int n = longUrl.size();
    int numOfSlash = 0, pos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (longUrl[i] == '/')
        {
            ++numOfSlash;
            if (3 == numOfSlash)
            {
                pos = i;
                break;
            }
        }
    }

    string headerUrl = longUrl.substr(0, pos + 1);
    string tailUrl = longUrl.substr(pos + 1);
    cout << headerUrl << endl;
    cout << tailUrl << endl;
    string res;
    return res;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl)
{
    return "";
}

void testEncodeDecode()
{
    string longUrl1 = "https://leetcode.com/problems/design-tinyurl";
    string encode1 = encode(longUrl1);
    string decode1 = decode(encode1);

    cout << longUrl1 << endl;
    cout << encode1 << endl;
    cout << decode1 << endl;
}

int main()
{
    testEncodeDecode();

    getchar();
    return 0;
}