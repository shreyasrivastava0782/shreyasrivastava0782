#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {
        s2.push(x);  // Push to input stack
    }

    int pop() {
        if (s1.empty()) {
            // Transfer all elements from s2 to s1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        if (s1.empty()) return -1; // Queue is empty
        int val = s1.top();
        s1.pop();
        return val;
    }

    int peek() {
        if (s1.empty()) {
            // Transfer all elements from s2 to s1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        if (s1.empty()) return -1; // Queue is empty
        return s1.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};