//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr) , right(nullptr) {}
//};
//
//void display(vector<TreeNode*>& input)
//{
//    if (input.empty())
//        return;
//
//    for (auto i : input)
//    {
//        if (nullptr == i)
//            cout << "NULL" << ", ";
//        else
//            cout << i->val << ", ";
//    }
//
//    cout << endl;
//}
//
//vector<string> splitVector(string input, char delimiter)
//{
//    vector<string> result;
//
//    while (!input.empty())
//    {
//        auto iter = find(input.begin(), input.end(), delimiter);
//        if (iter == input.end())
//        {
//            result.emplace_back(input);
//            input.clear();
//        }
//        else
//        {
//            auto l = iter - input.begin();
//            result.emplace_back(input.substr(0, l));
//            input = input.substr(l + 1, input.size() - l + 1);
//        }
//    }
//
//    return result;
//}
//
//bool isValidSerialization2(string preorder)
//{
//    if (preorder.empty())
//        return false;
//
//    int nodeCount = 0, nullCount = 0;
//    auto v = splitVector(preorder, ',');
//    for (size_t i = 0; i < v.size(); ++i)
//    {
//        if ("#" == v[i])
//            ++nullCount;
//        else
//            ++nodeCount;
//
//        if (nullCount >= nodeCount + 1 && i != v.size() - 1)
//            return false;
//    }
//
//    return nullCount == nodeCount + 1;
//}
//
//bool isValidSerialization(string preorder)
//{
//    if (preorder.empty())
//        return false;
//
//    vector<TreeNode *> vec;
//    //string temp = preorder;
//
//    while (!preorder.empty())
//    {
//        auto iter = find(preorder.begin(), preorder.end(), ',');
//        auto len = iter - preorder.cbegin();
//
//        if ("#" == preorder.substr(0, len))
//        {
//            vec.emplace_back(nullptr);
//            if (iter != preorder.end())
//                preorder = preorder.substr(len + 1, preorder.size() - len);
//            else
//                break;
//
//            continue;
//        }
//
//        int val = std::stoi(preorder.substr(0, len));
//        TreeNode* p = new TreeNode(val);
//        vec.emplace_back(p);
//
//        if (iter != preorder.end())
//            preorder = preorder.substr(len + 1, preorder.size() - len);
//        else
//            break;
//    }
//
//    display(vec);
//    //TreeNode* root = new TreeNode(preorder.sp)
//}
//
//void testIsValidSerialization()
//{
//    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
//    auto result = isValidSerialization2(preorder);
//
//    cout << (result ? 1 : 0) << endl;
//}
//
//int main()
//{
//    testIsValidSerialization();
//    system("pause");
//    return 0;
//}