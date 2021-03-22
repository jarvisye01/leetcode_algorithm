#include <iostream>
#include <stack>

using std::stack;

class MyQueue {
public:
    stack<int> *s1;
    stack<int> *s2;
    /** Initialize your data structure here. */
    MyQueue() {
        s1 = new stack<int>;
        s2 = new stack<int>;
    }

    /** Size of Queue */
    int size() {
        return s1->size() + s2->size();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = peek();
        s2->pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2->size() == 0) {
            while (s1->size() > 0) {
                s2->push(s1->top());
                s1->pop();
            }
        }
        return s2->top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size() == 0;
    }

    ~MyQueue() {
        if (s1 != nullptr) delete s1;
        if (s2 != nullptr) delete s2;
    }
};

int main(int argc, char **argv) {
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(1);
    q->push(2);
    q->push(4);
    q->push(5);

    while (!q->empty()) {
        std::cout << q->pop() << " ";
        std::cout << std::endl;
    }
    return 0;
}