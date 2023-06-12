#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> queue;
    MyStack()
    {
    }

    void push(int x)
    {
        this->queue.push(x);
        for (int i = 0; i < queue.size() - 1; ++i)
        {
            this->queue.push(this->pop());
        }
    }

    int pop()
    {
        int elem = this->top();
        this->queue.pop();
        return elem;
    }

    int top()
    {
        return this->queue.front();
    }

    bool empty()
    {
        return this->queue.empty();
    }
};