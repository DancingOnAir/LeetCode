//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//using namespace std;
//
//struct Employee
//{
//    int id;
//    int importance;
//    vector<int> subordinates;
//
//    Employee(int i, int v, const vector<int>& s): id(i), importance(v), subordinates(s)
//    {
//    
//    }
//
//    Employee& operator=(const Employee& e)
//    {
//        if (this != &e)
//        {
//            this->id = e.id;
//            this->importance = e.importance;
//            this->subordinates.clear();
//            this->subordinates.assign(e.subordinates.begin(), e.subordinates.end());
//        }
//        return *this;
//    }
//};
//
//int getImportanceRecursive(unordered_map<int, Employee*>& m, int id)
//{
//    if (!m.count(id))
//        return 0;
//
//    int total = m[id]->importance;
//    for (auto s : m[id]->subordinates)
//    {
//        total += getImportanceRecursive(m, s);
//    }
//
//    return total;
//}
//
//int getImportance2(vector<Employee*> employees, int id)
//{
//    if (employees.empty() || id < 0)
//        return 0;
//
//    unordered_map<int, Employee*> m;
//    for (int i = 0; i < employees.size(); ++i)
//    {
//        m[employees[i]->id] = employees[i];
//    }
//
//    return getImportanceRecursive(m, id);
//}
//
//int getImportance(vector<Employee*> employees, int id)
//{
//    if (employees.empty() || id < 0)
//        return 0;
//    
//    unordered_map<int, int> m;
//    for (int i = 0; i < employees.size(); ++i)
//        m[employees[i]->id] = i;
//
//    queue<int> q;
//    q.emplace(id);
//    int res = 0;
//
//    while (!q.empty())
//    {
//        int tmp = q.front();
//        q.pop();
//
//        res += employees[m[tmp]]->importance;
//        vector<int> vec = employees[m[tmp]]->subordinates;
//        for (int v : vec)
//        {
//            q.emplace(v);
//        }
//    }
//
//    return res;
//}
//
//void testGetImportance()
//{
//    Employee e1 = Employee(1, 5, vector<int>(2, 3));
//    Employee e2 = Employee(2, 3, vector<int>());
//    Employee e3 = Employee(3, 3, vector<int>());
//    vector<Employee*> es = { &e1, &e2, &e3 };
//    cout << getImportance(es, 1) << endl;
//}
//
//int main()
//{
//    testGetImportance();
//
//    getchar();
//    return 0;
//}