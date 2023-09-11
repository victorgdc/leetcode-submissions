// https://leetcode.com/problems/min-stack

class MinStack {
public:

    struct node {
        int val;
        int minuntilnow;
    };

    int globalmin;
    stack<node*> s;

    MinStack() {
        this->globalmin = 1e5;
    }
    
    void push(int val) {
        
        node* n = new node;
        n->val = val;
        
        if (this->s.empty()) {
            n->minuntilnow = val;
            this->globalmin = val;
        }
        else {
            if (val < this->globalmin) {
                this->globalmin = val;
                n->minuntilnow = val;
            }
            else {
                n->minuntilnow = this->globalmin;
            }
        }
        this->s.push(n);
    }
    
    void pop() {
        this->s.pop();
        this->globalmin = (this->s.top())->minuntilnow;
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