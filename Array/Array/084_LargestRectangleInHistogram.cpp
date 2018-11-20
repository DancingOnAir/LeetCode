#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) 
{
    if (heights.empty())
        return 0;

    int maxArea = 0;
    stack<int> st;
    heights.emplace_back(0);

    for (int i = 0; i < heights.size(); ++i)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            int curHeight = heights[st.top()];
            st.pop();

            int width = st.size() > 0 ? (i - st.top() - 1) : i;
            if (curHeight * width > maxArea)
                maxArea = curHeight * width;
        }
        st.emplace(i);
        
    }
    return maxArea;
}

void testLargestRectangleArea()
{
    vector<int> heights = { 2,1,5,6,2,3 };
    int result = largestRectangleArea(heights);

    cout << result << endl;
}

int main()
{
    testLargestRectangleArea();
    getchar();
}