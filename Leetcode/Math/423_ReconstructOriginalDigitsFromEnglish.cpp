//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//
//void getSpecificNumber(map<char, int>& m, map<int, int>& res, vector<string>& nums, int idx, char c)
//{
//    if (m.count(c) && m[c] > 0)
//    {
//        res[idx] = m[c];
//
//        for (char x : nums[idx])
//            m[x] -= res[idx];
//    }
//}
//
//string originalDigits2(string s)
//{
//    vector<string> nums= { "zero", "one", "two", "three", "four", 
//        "five", "six", "seven", "eight", "nine" };
//
//    map<char, int> m;
//    for (char c : s)
//        m[c]++;
//
//    map<int, int> res;
//    // 1st check
//    getSpecificNumber(m, res, nums, 8, 'g');
//    getSpecificNumber(m, res, nums, 6, 'x');
//    getSpecificNumber(m, res, nums, 4, 'u');
//    getSpecificNumber(m, res, nums, 2, 'w');
//    getSpecificNumber(m, res, nums, 0, 'z');
//
//    // 2nd check
//    getSpecificNumber(m, res, nums, 7, 's');
//    getSpecificNumber(m, res, nums, 5, 'v');
//    getSpecificNumber(m, res, nums, 3, 'h');
//
//    // 3rd check
//    getSpecificNumber(m, res, nums, 9, 'i');
//    getSpecificNumber(m, res, nums, 1, 'e');
//
//    string digits("");
//    for (auto iter = res.begin(); iter != res.end(); ++iter)
//    {
//        for (int i = 0; i < iter->second; ++i)
//            digits += iter->first + '0';
//    }
//
//    return digits;
//}
//
//string originalDigits(string s) {
//    vector<int> a(10, 0);
//    vector<int> alpha(128, 0);
//    for (char c : s)
//        alpha[c]++;
//    a[0] = alpha['z'];
//    a[2] = alpha['w'];
//    a[4] = alpha['u'];
//    a[6] = alpha['x'];
//    a[8] = alpha['g'];
//    a[3] = alpha['h'] - a[8];
//    a[5] = alpha['f'] - a[4];
//    a[7] = alpha['v'] - a[5];
//    a[1] = alpha['o'] - a[0] - a[2] - a[4];
//    a[9] = alpha['i'] - a[5] - a[6] - a[8];
//    string ans;
//    for (int i = 0; i < 10; i++) {
//        if (a[i] > 0)
//            ans += string(a[i], '0' + i);
//    }
//    return ans;
//}
//
//void testOriginalDigits()
//{
//    cout << originalDigits("owoztneoer") << endl;
//    cout << originalDigits("fviefuro") << endl;
//}
//
//int main()
//{
//    testOriginalDigits();
//
//    getchar();
//    return 0;
//}