//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isOneBitCharacter(vector<int>& bits)
//{
//    int n = bits.size();
//    if (0 == n || 1 == bits[n - 1])
//        return false;
//
//    int pos = 0;
//    while (pos < n)
//    {
//        if (bits[pos] == 1)
//            pos += 2;
//        else
//        {
//            ++pos;
//            if (pos == n)
//                return true;
//        }
//
//    }
//
//    return false;
//}
//
//void testIsOneBitCharacter()
//{
//    vector<int> bits = { 1, 1, 1, 0 };
//    vector<int> bits2 = { 1, 0, 0 };
//    cout << (isOneBitCharacter(bits2)?"True":"False") << endl;
//}
//
//int main()
//{
//    testIsOneBitCharacter();
//
//    getchar();
//    return 0;
//}