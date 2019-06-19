#include <iostream>
#include <algorithm>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F);

    int left = max(A, E);
    int right = max(left, min(C, G));
    int bottom = max(B, F);
    int top = max(bottom, min(D, H));

    return s1 + s2 - (right - left) * (top - bottom);
}

void testComputerArea()
{
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
}

int main()
{
    testComputerArea();

    getchar();
    return 0;
}