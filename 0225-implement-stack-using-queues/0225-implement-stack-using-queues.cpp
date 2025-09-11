#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        // queues are already initialized as member variables
    }

    void push(int x) {
        q2.push(x);

        // Push all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 so q1 always has the top at front
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;

        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) return -1;

        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */