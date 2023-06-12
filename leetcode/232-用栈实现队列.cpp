#include <stack>

using namespace std;

class MyQueue {
public:
stack<int> head;
    stack<int> tail;

    MyQueue() {
        
    }
    
    void push(int x) {
        this->tail.push(x);
    }
    
    int pop() {
        int elem = this->peek();
        this->head.pop();
        return elem;
    }
    
    int peek() {
        if (this->head.empty())
        {
            while (!this->tail.empty())
            {         
                this->head.push(this->tail.top());
                this->tail.pop();
            }
        }
        return this->head.top();
    }
    
    bool empty() {
        return this->head.empty() && this->tail.empty();
    }
};