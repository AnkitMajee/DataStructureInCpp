/*
    Q: Reverse a stack using recursion.
    Level : Medium
    Reference : https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void Reverse(stack<int> &St)
    {
        // Base case: if stack is empty, return
        if (St.empty())
        {
            return;
        }

        // Remove the top element from the stack
        int num = St.top();
        St.pop();

        // Recursively call Reverse for the remaining elements
        Reverse(St);

        // Place the removed element at the bottom of the stack
        insertAtBottom(St, num);
    }

private:
    // Helper function to place an element at the bottom of the stack
    void insertAtBottom(stack<int> &St, int num)
    {
        // Base case: if stack is empty, push the element
        if (St.empty())
        {
            St.push(num);
            return;
        }

        // Remove the top element
        int top = St.top();
        St.pop();

        // Recursively call insertAtBottom to reach the base
        insertAtBottom(St, num);

        // Push the top element back
        St.push(top);
    }
};