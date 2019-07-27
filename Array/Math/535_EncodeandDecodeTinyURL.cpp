//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//const std::string basic = "http://tinyurl.com/";
//std::vector<std::string> urls;
//
//// Encodes a URL to a shortened URL.
//string encode(string longUrl)
//{
//    int n = longUrl.size();
//    urls.emplace_back(longUrl);
//
//    return basic + to_string(urls.size() - 1);
//}
//
//// Decodes a shortened URL to its original URL.
//string decode(string shortUrl)
//{
//    string part = shortUrl.substr(shortUrl.find_last_of('/') + 1);
//    return urls[stoi(part)];
//}
//
//void testEncodeDecode()
//{
//    string longUrl1 = "https://leetcode.com/problems/design-tinyurl";
//    string encode1 = encode(longUrl1);
//    string decode1 = decode(encode1);
//
//    cout << longUrl1 << endl;
//    cout << encode1 << endl;
//    cout << decode1 << endl;
//}
//
//int main()
//{
//    testEncodeDecode();
//
//    getchar();
//    return 0;
//}