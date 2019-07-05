#include <iostream>
#include <vector>

using namespace std;

bool canMeasureWater(int x, int y, int z)
{

}

void testCanMeasureWater()
{
    cout << (canMeasureWater(3, 5, 4)? "T" : "F") << endl;
    cout << (canMeasureWater(2, 6, 5) ? "T" : "F") << endl;
}

int main()
{
    testCanMeasureWater();

    getchar();
    return 0;
}