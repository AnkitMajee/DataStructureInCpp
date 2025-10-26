#include <stack>
#include <climits>
using namespace std;

class MinStack
{
private:
    stack<long> st;
    long currMin;

public:
    MinStack() { currMin = LONG_MAX; }

    /**
     * push
     * Pushes a value onto the stack and stores the current minimum.
     * Time Complexity: O(1)
     */
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            currMin = val;
        }
        else
        {
            if (val > currMin)
                st.push(val);
            else
            {
                st.push(2 * (long)val - currMin);
                currMin = val;
            }
        }
    }

    /**
     * pop
     * Pops the top element. If stack is empty, does nothing.
     * Time Complexity: O(1)
     */
    void pop()
    {
        if (st.empty())
            return;
        long top = st.top();
        if (top < currMin)
            currMin = 2 * currMin - top;
        st.pop();
    }

    /**
     * top
     * Returns the top element's value. If empty, returns INT_MIN as sentinel.
     */
    int top()
    {
        if (st.empty())
            return INT_MIN;

        long top = st.top();
        if (top < currMin)
            return currMin;
        else
            return top;
    }

    /**
     * getMin
     * Returns the current minimum. If empty, returns INT_MIN as sentinel.
     */
    int getMin()
    {
        if (st.empty())
            return INT_MIN;
        return currMin;
    }
};