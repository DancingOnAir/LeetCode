//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isPalindrome(string s)
//{
//    if (s.empty())
//        return true;
//
//    for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
//    {
//        while (!isalnum(s[i]) && i < j)
//        {
//            ++i;
//        }
//
//        while (!isalnum(s[j]) && i < j)
//        {
//            --j;
//        }
//
//        if (tolower(s[i]) != tolower(s[j]))
//            return false;
//    }
//
//    return true;
//}
//
//void testIsPalindrome()
//{
//    string s1 = "A man, a plan, a canal: Panama";
//    cout << (isPalindrome(s1)? "true" : "false") << endl;
//
//    string s2 = "race a car";
//    cout << (isPalindrome(s2) ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testIsPalindrome();
//
//    getchar();
//    return 0;
//}