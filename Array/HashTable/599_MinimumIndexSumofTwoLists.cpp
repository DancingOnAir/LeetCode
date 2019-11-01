//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
//{
//    unordered_map<string, int> m;
//    vector<string> res;
//    int minIndex = INT_MAX;
//
//    for (int i = 0; i < list1.size(); ++i)
//        m[list1[i]] = i;
//
//    for (int i = 0; i < list2.size(); ++i)
//    {
//        if (m.count(list2[i]))
//        {
//            if (m[list2[i]] + i < minIndex)
//            {
//                res.clear();
//                res.emplace_back(list2[i]);
//                minIndex = m[list2[i]] + i;
//            }
//            else if (m[list2[i]] + i == minIndex)
//            {
//                res.emplace_back(list2[i]);
//            }
//        }
//    }
//
//    return res;
//}
//
//void display(const vector<string>& vec)
//{
//    for (string str : vec)
//        cout << str << ", ";
//    cout << endl;
//}
//
//void testFindRestaurant()
//{
//    vector<string> list11 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
//    vector<string> list21 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
//    auto res1 = findRestaurant(list11, list21);
//    display(res1);
//
//    vector<string> list12 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
//    vector<string> list22 = { "KFC", "Shogun", "Burger King" };
//    auto res2 = findRestaurant(list12, list22);
//    display(res2);
//}
//
//int main()
//{
//    testFindRestaurant();
//
//    getchar();
//    return 0;
//}