#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

class LRUCache
{
public:
    LRUCache(int capacity): capacity_(capacity)
    {

    }

    int get(int key)
    {
        if (!m_.count(key))
            return -1;
        
        list_.splice(list_.begin(), list_, m_[key]);
        return m_[key]->second;
    }

    void put(int key, int value)
    {
        if (m_.count(key))
        {
            list_.splice(list_.begin(), list_, m_[key]);
            m_[key]->second = value;
            
            return;
        }

        if (m_.size() >= capacity_)
        {
            int toBedeletedKey = list_.back().first;
            list_.pop_back();
            m_.erase(toBedeletedKey);
        }

        list_.emplace_front(std::make_pair(key, value));
        m_[key] = list_.begin();
    }

private:
    //int - key, pair <int, int> - key, value
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_;
    //int - key, int - value
    std::list<std::pair<int, int>> list_;
    size_t capacity_;
};

void test()
{
    LRUCache cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    // returns 1
    std::cout << cache.get(1) << std::endl;
    // evicts key 2
    cache.put(3, 3);
    // returns -1 (not found)
    std::cout << cache.get(2) << std::endl;
    // evicts key 1
    cache.put(4, 4);
    // returns -1 (not found)
    std::cout << cache.get(1) << std::endl;
    // returns 3
    std::cout << cache.get(3) << std::endl;
    // returns 4
    std::cout << cache.get(4) << std::endl;
}

int main()
{
    test();

    getchar();
    return 0;
}