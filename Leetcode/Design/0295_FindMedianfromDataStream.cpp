#include <iostream>
#include "0295_FindMedianfromDataStream.h"
using namespace std;

void testMedianFinder()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl;
}

int main()
{
    testMedianFinder();

    getchar();
    return 0;
}