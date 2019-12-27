//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <unordered_map>
//using namespace std;
//
//class RandomizedSet {
//public:
//    /** Initialize your data structure here. */
//    RandomizedSet()
//    {
//        std::srand(time(0));
//        m_vec.clear();
//        m_vec.shrink_to_fit();
//    }
//
//    ~RandomizedSet()
//    {
//        m_vec.clear();
//        m_vec.shrink_to_fit();
//
//        m_map.clear();
//        m_map.swap(unordered_map<int, int>{});
//    }
//
//    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//    bool insert(int val)
//    {
//        if (m_map.find(val) != m_map.end())
//            return false;
//
//        m_vec.emplace_back(val);
//        m_map[val] = m_vec.size() - 1;
//        return true;
//    }
//
//    /** Removes a value from the set. Returns true if the set contained the specified element. */
//    bool remove(int val)
//    {
//        if (m_map.find(val) == m_map.end())
//            return false;
//
//        int last = m_vec.back();
//        m_map[last] = m_map[val];
//        m_vec[m_map[val]] = last;
//        m_map.erase(val);
//        m_vec.pop_back();
//
//        return true;
//    }
//
//    /** Get a random element from the set. */
//    int getRandom()
//    {
//        return m_vec[rand() % m_vec.size()];
//    }
//
//private:
//    vector<int> m_vec;
//    unordered_map<int, int> m_map;
//};
//
//void testRandomizedSet()
//{
//    // Init an empty set.
//    RandomizedSet randomSet;
//
//    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
//    cout << (randomSet.insert(1) ? "true": "false") << endl;
//
//    // Returns false as 2 does not exist in the set.
//    cout << (randomSet.remove(2)? "true" : "false") << endl;
//
//    // Inserts 2 to the set, returns true. Set now contains [1,2].
//    cout << (randomSet.insert(2)? "true":"false") << endl;
//
//    randomSet.insert(3);
//    // getRandom should return either 1 or 2 randomly.
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//
//    // Removes 1 from the set, returns true. Set now contains [2].
//    cout << (randomSet.remove(1)?"true":"false") << endl;
//
//    // 2 was already in the set, so return false.
//    cout << (randomSet.insert(2)? "true" : "false") << endl;
//
//    // Since 2 is the only number in the set, getRandom always return 2.
//    cout << randomSet.getRandom() << endl;
//}
//
//int main()
//{
//    testRandomizedSet();
//    getchar();
//
//    return 0;
//}