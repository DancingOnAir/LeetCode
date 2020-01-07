#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

class LRUCache
{
public:
    LRUCache(int capacity): _capacity(capacity)
    {

    }

    int get(int key)
    {
        if (m.count(key))
            return m[key];
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (m.count(key) || m.size() < len)
        {
            m[key] = value;
            times[key] = 0;
            return;
        }

        
        
        
        
    }

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;
    std::list<std::pair<int, int>> _list;
    size_t _capacity;
};

void test()
{
    LRUCache cache = LRUCache(2);
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