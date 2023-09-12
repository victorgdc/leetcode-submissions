// https://leetcode.com/problems/min-stack

class MinStack {
public:

    struct node {
        int val;
        int minuntilnow;
    };
    
    stack<node*> s;

    MinStack() {
 
    }
    
    void push(int val) {
        
        node* n = new node;
        n->val = val;
        
        if (this->s.empty()) {
            n->minuntilnow = val;
        } else {
            n->minuntilnow = min((this->s.top())->minuntilnow, val);
        }

        this->s.push(n);
    }
    
    void pop() {
        this->s.pop();
    }
    
    int top() {
        return (this->s.top())->val;
    }
    
    int getMin() {
        return (this->s.top())->minuntilnow;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */