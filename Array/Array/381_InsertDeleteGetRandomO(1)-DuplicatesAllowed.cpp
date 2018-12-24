#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
        std::srand(time(nullptr));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        auto res = m_map.find(val) == m_map.end();

        m_map[val].emplace_back(m_vec.size());
        m_vec.emplace_back(make_pair(val, m_map[val].size() - 1));
        
        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        auto res = m_map.find(val) != m_map.end();
        if (res)
        {
            auto last = m_vec.back();
            m_map[last.first][last.second] = m_map[val].back();
            m_vec[m_map[val].back()] = last;
            
            m_map[val].pop_back();
            if (m_map[val].empty())
                m_map.erase(val);

            m_vec.pop_back();
        }

        return res;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return m_vec[rand() % m_vec.size()].first;
    }

private:
    vector<pair<int, int>> m_vec;
    unordered_map<int, vector<int>> m_map;
};

void testRandomizedCollection()
{
    // Init an empty collection.
    RandomizedCollection collection;

    // Inserts 1 to the collection. Returns true as the collection did not contain 1.
    cout << (collection.insert(10) ? "true" : "false") << endl;

    // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    cout << (collection.insert(10) ? "true" : "false") << endl;

    // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    cout << (collection.insert(20) ? "true" : "false") << endl;
    cout << (collection.insert(20) ? "true" : "false") << endl;
    cout << (collection.insert(30) ? "true" : "false") << endl;
    cout << (collection.insert(30) ? "true" : "false") << endl;


    // Removes 1 from the collection, returns true. Collection now contains [1,2].
    cout << (collection.remove(10) ? "true" : "false") << endl;
    cout << (collection.remove(10) ? "true" : "false") << endl;
    cout << (collection.remove(20) ? "true" : "false") << endl;
    cout << (collection.remove(20) ? "true" : "false") << endl;
    // getRandom should return 1 and 2 both equally likely.
    cout << collection.getRandom() << endl;
    // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    cout << collection.getRandom() << endl;
}

int main()
{
    testRandomizedCollection();
    getchar();
}