#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; ++i)
    {
        // Pop elements from stack while the current bar is shorter than the stack's top bar
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    // Process remaining elements in the stack
    while (!st.empty())
    {
        int h = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    
    return 0;
}