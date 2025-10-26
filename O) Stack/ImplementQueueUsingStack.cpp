/**
 * ImplementQueueUsingStack.cpp
 * ----------------------------
 * Demonstrates how to implement a FIFO queue using two LIFO stacks.
 *
 * Class: MyQueue
 * - Uses two stacks (s1, s2) to maintain queue order.
 *
 * Public methods:
 * - void push(int x): Enqueue element x to the back of the queue.
 * - int pop(): Dequeue and return the front element of the queue.
 * - int peek(): Return the front element without removing it.
 * - bool empty(): Return true if the queue is empty.
 *
 * Complexity:
 * - push: O(n) worst-case (because elements may be moved between stacks)
 * - pop: O(1)
 * - peek: O(1)
 * - space: O(n) where n is the number of elements stored
 *
 * Usage example is provided in main().
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * MyQueue
 * Implements a queue using two stacks (s1 and s2). The implementation keeps
 * the front of the queue at the top of s1 by moving elements between s1 and s2
 * during push operations.
 */
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    /**
     * push
     * Enqueue an element to the queue.
     * @param x Integer element to be enqueued.
     * Time Complexity: O(n) in the worst case (moves existing elements to maintain order).
     */
    void push(int x)
    {
        if (s1.empty())
            s1.push(x);
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    /**
     * pop
     * Dequeue the front element from the queue.
     * @return The integer at the front of the queue. Caller must ensure queue is not empty.
     * Time Complexity: O(1)
     */
    int pop()
    {
        int elem = s1.top();
        s1.pop();
        return elem;
    }

    /**
     * peek
     * Retrieve (without removing) the front element of the queue.
     * @return The integer at the front of the queue.
     */
    int peek() { return s1.top(); }

    /**
     * empty
     * Check whether the queue is empty.
     * @return true if the queue has no elements.
     */
    bool empty() { return s1.empty(); }
};

/**
 * main
 * Simple demonstration of MyQueue.
 */
int main()
{
    MyQueue *q = new MyQueue();
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    cout << q->pop() << endl;
    cout << q->peek() << endl;
}