//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool canPlaceFlowers(vector<int>& flowerbed, int n)
//{
//    int count = 0;
//    int gap = 1;
//    bool isEmpty = true;
//    flowerbed.emplace_back(0);
//    for (int i = 0; i < flowerbed.size(); ++i)
//    {
//        if (flowerbed[i] == 1)
//        {
//            isEmpty = false;
//
//            if (gap != 0)
//            {
//                count += (gap - 1) / 2;
//            }
//            gap = 0;
//        }
//
//        if (flowerbed[i] == 0 && isEmpty == false)
//        {
//            isEmpty = true;
//            gap = 1;
//        }
//        else if (flowerbed[i] == 0 && isEmpty == true)
//        {
//            ++gap;
//        }
//    }
//
//    if (gap != 0)
//    {
//        count += (gap - 1) / 2;
//    }
//
//    return (count >= n);
//}
//
//bool canPlaceFlowers2(vector<int>& flowerbed, int n)
//{
//    for (int i = 0; i < flowerbed.size(); ++i)
//    {
//        if (!flowerbed[i] && (0 == i || !flowerbed[i - 1]) && (flowerbed.size() - 1 == i || !flowerbed[i + 1]))
//        {
//            flowerbed[i] = 1;
//            --n;
//        }
//    }
//
//    return n <= 0;
//}
//
//bool canPlaceFlowers3(vector<int>& flowerbed, int n)
//{
//    flowerbed.insert(flowerbed.begin(), 0);
//    flowerbed.emplace_back(0);
//
//    for (int i = 1; i < flowerbed.size() - 1; ++i)
//    {
//        if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0)
//            --n, ++i;
//    }
//
//    return n <= 0;
//}
//
//void testCanPlaceFlowers()
//{
//    vector<int> flowerbed = { 1,0,0,0,1, 0, 0 };
//    int n = 1;
//
//    cout << (canPlaceFlowers(flowerbed, n) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testCanPlaceFlowers();
//
//    getchar();
//    return 0;
//}