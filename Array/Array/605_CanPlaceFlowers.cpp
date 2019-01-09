#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int count = 0;
    int gap = 1;
    bool isEmpty = true;
    flowerbed.emplace_back(0);
    for (int i = 0; i < flowerbed.size(); ++i)
    {
        if (flowerbed[i] == 1)
        {
            isEmpty = false;

            if (gap != 0)
            {
                count += (gap - 1) / 2;
            }
            gap = 0;
        }

        if (flowerbed[i] == 0 && isEmpty == false)
        {
            isEmpty = true;
            gap = 1;
        }
        else if (flowerbed[i] == 0 && isEmpty == true)
        {
            ++gap;
        }
    }

    if (gap != 0)
    {
        count += (gap - 1) / 2;
    }

    return (count >= n);
}

void testCanPlaceFlowers()
{
    vector<int> flowerbed = { 1,0,0,0,1, 0, 0 };
    int n = 1;

    cout << (canPlaceFlowers(flowerbed, n) ? "True" : "False") << endl;
}

int main()
{
    testCanPlaceFlowers();

    getchar();
    return 0;
}