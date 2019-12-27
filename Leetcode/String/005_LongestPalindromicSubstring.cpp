//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//string longestPalindrome1(string s) 
//{
//	vector<int> dict(256, -1);
//	int position = -1;
//	int end = -1;
//	int start = -1;
//	int maxLength = 0;
//	string result = "";
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (dict[s[i]] > position)
//		{
//			//if (i - end == 1 && start != -1)
//			//	start = position;
//			//else
//			//	start = dict[s[i]];
//			position = dict[s[i]];
//			end = i;
//		}
//
//		dict[s[i]] = i;
//		maxLength = max(maxLength, end - position);
//	}
//
//	if (position == -1)
//		return s;
//
//	result = s.substr(position, maxLength + 1);
//	return result;
//}
//
//string longestPalindrome2(string s)
//{
//	if (s.empty()) return "";
//	if (s.size() == 1) return s;
//	int min_start = 0, max_len = 1;
//	for (int i = 0; i < s.size();) {
//		int j = i, k = i;
//		while (k < s.size() - 1 && s[k + 1] == s[k]) 
//			++k; // Skip duplicate characters.
//		i = k + 1;
//		while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) 
//		{	
//			++k; 
//			--j; 
//		} // Expand.
//		int new_len = k - j + 1;
//		if (new_len > max_len) 
//		{ min_start = j; max_len = new_len; }
//	}
//	return s.substr(min_start, max_len);
//}
//
////int helper(std::string s, int start, int end)
////{
////    if (start == end)
////        return 1;
////
////    if (start > end)
////        return 0;
////
////    if (s[start] == s[end])
////        return helper(s, start + 1, end - 1) + 2;
////    else
////        return std::max(helper(s, start + 1, end), helper(s, start, end - 1));
////}
////
//////calcaute size of palindrome
////int longestPalindrome3(std::string s)
////{
////    return helper(s, 0, s.size() - 1);
////}
//
//string longestPalindrome4(string s)
//{
//    //int len = s.size();
//    //vector<vector<int>> dp(len, vector<int>(len, 0));
//
//    //if (0 == len || 1 == len)
//    //    return len;
//
//    //for (int i = len - 1; i >= 0; --i)
//    //{
//    //    dp[i][i] = 1;
//    //    for (int j = i + 1; j < len; ++j)
//    //    {
//    //        if (s[i] == s[j])
//    //            dp[i][j] = dp[i + 1][j - 1] + 2;
//    //        else
//    //            dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
//    //    }
//    //}
//
//    //int start = 0;
//    //for (int i = 0; i < len; ++i)
//    //{
//    //    for (int j = i; j < len; ++j)
//    //    {
//    //        if (dp[i][j] == dp[0][len - 1])
//    //        {
//    //            start = i;
//    //            break;
//    //        }
//    //    }
//    //}
//
//    //cout << s.substr(start, dp[0][len - 1]);
//    //return dp[0][len - 1];
//
//    int n = s.size();
//    
//    if (0 == n || 1 == n)
//        return s;
//
//    vector<vector<int>> dp(n, vector<int>(n, 0));
//    for (int j = 0; j < n; ++j)
//    {
//        dp[j][j] = 1;
//        for (int i = j - 1; i >= 0; --i)
//        {
//            if (s[i] == s[j])
//                dp[i][j] = dp[i + 1][j - 1] + 2;
//            else
//                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//        }
//    }
//
//    cout << dp[0][n - 1] << endl;
//
//    int start = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = i; j < n; ++j)
//        {
//            if (dp[i][j] == dp[0][n - 1])
//            {
//                start = i;
//                break;
//            }
//        }
//    }
//
//    return s.substr(start, dp[0][n - 1]);
//}
//
//string longestPalindrome5(string s)
//{
//    int n = s.size();
//    if (0 == n || 1 == n)
//        return s;
//
//    int maxLength = 1;
//    int maxStart = 0;
//    vector<vector<bool>> dp(n, vector<bool>(n, false));
//
//    for (int i = 0; i < n; ++i)
//        dp[i][i] = true;
//
//    for (int i = 0; i < n - 1; ++i)
//    { 
//        if (s[i] == s[i + 1])
//        {
//            dp[i][i + 1] = true;
//            maxLength = 2;
//            maxStart = i;
//        }
//    }
//
//    for (int len = 3; len <= n; ++len)
//    {
//        for (int i = 0; i + len - 1< n; ++i)
//        {
//            int j = i + len - 1;
//            if (s[i] == s[j] && dp[i + 1][j - 1])
//            {
//                dp[i][j] = true;
//                maxLength = len;
//                maxStart = i;
//            }
//        }
//    }
//
//    return s.substr(maxStart, maxLength);
//}
//
//int main(void)
//{
//    string s = "ccc";
//    //string result = longestPalindrome2(s);
//
//    cout << longestPalindrome5(s) << endl;
//    //cout << result << endl;
//    system("pause");
//    return 0;
//}