#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const string validIPv6Chars = "0123456789abcdefABCDEF";

string validIPAddress(string IP)
{
    istringstream iss(IP);
    string temp;

    if (!isalnum(IP.back()))
        return "Neither";

    if (IP.find('.') != string::npos)
    {
        vector<int> res;
        while (getline(iss, temp, '.'))
        {
            if (temp.empty() || (temp[0] == '0' && temp.size() > 1) || temp.size() > 4)
                return "Neither";

            for (char c : temp)
                if (!isdigit(c))
                    return "Neither";

            int num = stoi(temp);
            if (num < 0 || num > 255)
                break;

            res.emplace_back(num);
        }
        
        if (res.size() == 4)
            return "IPv4";
    }
    else
    {
        vector<string> res;
        while (getline(iss, temp, ':'))
        {
            if (temp.empty() || temp.size() > 4)
                return "Neither";

            for (char c : temp)
                if (validIPv6Chars.find(c) == string::npos)
                    return "Neither";

            res.emplace_back(temp);
        }

        if (res.size() == 8)
            return "IPv6";
    }

    return "Neither";
}

void testValidIPAddress()
{
    //string IP1 = "172.16.254.1";
    //cout << validIPAddress(IP1) << endl;

    //string IP2 = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    //cout << validIPAddress(IP2) << endl;

    //string IP3 = "256.256.256.256";
    //cout << validIPAddress(IP3) << endl;

    //string IP4 = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    //cout << validIPAddress(IP4) << endl;

    string IP5 = "0.0.0.-0";
    cout << validIPAddress(IP5) << endl;
}

int main()
{
    testValidIPAddress();

    getchar();
    return 0;
}