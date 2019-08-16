//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//using namespace std;
//
//string reverseWords(string s)
//{
//    //string res("");
//    //istringstream iss(s);
//    //string temp;
//    //vector<string> stk;
//    //while (getline(iss, temp, ' '))
//    //{
//    //    if (temp == "")
//    //        continue;
//    //    else
//    //        stk.emplace_back(temp);
//    //}
//
//    //if (stk.empty())
//    //    return res;
//
//    //for (int i = stk.size() - 1; i > 0; --i)
//    //    res += stk[i] + ' ';
//
//    //return res + stk[0];
//
//    string res("");
//    istringstream iss(s);
//    string temp;
//    vector<string> stk;
//    while (iss >> temp)
//    {
//        res = temp + " " + res;
//    }
//
//    return res.size() == 0? res : res.substr(0, res.size() - 1);
//}
//
//void testReverseWords()
//{
//    string s0 = " ";
//    cout << reverseWords(s0) << endl;
//
//    string s1 = "the sky is blue";
//    cout << reverseWords(s1) << endl;
//
//    string s2 = "  hello world!  ";
//    cout << reverseWords(s2) << endl;
//
//    string s3 = "a good   example";
//    cout << reverseWords(s3) << endl;
//}
//
//int main()
//{
//    testReverseWords();
//
//    getchar();
//    return 0;
//}