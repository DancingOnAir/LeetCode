//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//vector<vector<string>> findDuplicate(vector<string>& paths)
//{
//    vector<vector<string>> res;
//    if (paths.empty())
//        return res;
//
//    unordered_map<string, vector<string>> m;
//    for (string& str : paths)
//    {
//        istringstream iss(str);
//        string tmp;
//        string directory;
//        while (iss >> tmp)
//        {
//            size_t pos = tmp.find('(');
//            if (pos != string::npos)
//            {
//                string content = tmp.substr(pos + 1, tmp.size() - pos - 2);
//                m[content].emplace_back(directory + '/' + tmp.substr(0, pos));
//            }
//            else
//            {
//                directory = tmp;
//            }
//        }
//    }
//
//    for (auto& iter : m)
//    {
//        if (iter.second.size() > 1)
//            res.emplace_back(iter.second);
//    }
//
//    return res;
//}
//
//void display(const vector<vector<string>>& paths)
//{
//    for (auto& col : paths)
//    {
//        for (auto& row : col)
//            cout << row << ", ";
//        cout << endl;
//    }
//}
//
//void testFindDuplicate()
//{
//    vector<string> paths1 = { "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)" };
//    auto res1 = findDuplicate(paths1);
//    display(res1);
//}
//
//int main()
//{
//    testFindDuplicate();
//
//    getchar();
//    return 0;
//}