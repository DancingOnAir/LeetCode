//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <map>
//using namespace std;
//
//vector<int> twoSum(vector<int>& nums, int target) {
//
//    cout << target << endl;
//    //map
//    vector<int> tempVec;
//    int number = 0;
//
//    map<int, int> m;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (m.find(nums[i]) == m.end())
//        {
//            m[target - nums[i]] = i;
//        }
//        else
//        {
//            tempVec.push_back(i);
//            tempVec.push_back(m[nums[i]]);
//        }
//    }
//
//    //for (int i = 0; i < nums.size(); ++i)
//    //{
//	   // number = target - nums.at(i);
//	   // for (int j = 0; j < nums.size(); ++j)
//	   // {
//		  //  if (nums.at(j) == number && j != i)
//		  //  {
//			 //   tempVec.push_back(i);
//			 //   tempVec.push_back(j);
//
//			 //   return tempVec;
//		  //  }
//	   // }
//    //}
//
//
//	return tempVec;
//}
//
//int main(void)
//{
//    //int pArray[4] = { 2, 7, 11, 15 };
//    //vector<int> vec(pArray, pArray + 4);
//    vector<int> vec = { 2,4, 5,7,11,15 };
//	//twoSum(vec, vec.at(0) + vec.at(1));
//
//	for (auto value : twoSum(vec, 9))
//	{
//		cout << value << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}