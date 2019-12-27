//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//int compareVersion(string version1, string version2)
//{
//    istringstream iss1(version1), iss2(version2);
//    string num1, num2;
//
//    while (!iss1.eof() || !iss2.eof())
//    {
//        if (iss1.eof())
//            num1 = "0";
//        else
//            getline(iss1, num1, '.');
//
//        if (iss2.eof())
//            num2 = "0";
//        else
//            getline(iss2, num2, '.');
//
//        int n1 = stoi(num1), n2 = stoi(num2);
//        if (n1 == n2)
//            continue;
//        return n1 > n2 ? 1 : -1;
//    }
//
//    return 0;
//}
//
//void testCompareVersion()
//{
//    string version11 = "0.1", version21 = "1.1";
//    cout << compareVersion(version11, version21) << endl;
//
//    string version12 = "1.0.1", version22 = "1";
//    cout << compareVersion(version12, version22) << endl;
//
//    string version13 = "7.5.2.4", version23 = "7.5.3";
//    cout << compareVersion(version13, version23) << endl;
//
//    string version14 = "1.01", version24 = "1.001";
//    cout << compareVersion(version14, version24) << endl;
//
//    string version15 = "1.0", version25 = "1.0.0";
//    cout << compareVersion(version15, version25) << endl;
//}
//
//int main()
//{
//    testCompareVersion();
//
//    getchar();
//    return 0;
//}