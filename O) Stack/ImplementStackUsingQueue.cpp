#include<iostream>
#include<queue>

using namespace std;

// Problem Statement:
// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

class Stack{
public:
    queue<int> q;
    void push(int val){
        q.push(val);
    }
    int pop(){
        int i = q.size()-1;
        while (i!=1){
            int temp = q.front();
            q.push(temp);
            q.pop();
            i--;
        }
        int temp = q.front();
        q.pop();
        return temp;
    }
    int top(){
        return q.back();
    }
    bool empty(){
        return q.empty();
    }
};

int main(){
    Stack* st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    st->push(40);
    cout<<st->pop()<<endl;
    cout<<st->top()<<endl;
}