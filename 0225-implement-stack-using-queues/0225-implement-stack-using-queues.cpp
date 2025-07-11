class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        while (!q1.empty()) {
    q1.pop();
}
       while (!q2.empty()) {
    q2.pop();
}
    }
    
    void push(int x) {
        q2.push(x);
       while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
        }
        swap(q2,q1);
    }
    
    int pop() {
        
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
         int x = q1.front();
         return x;
    }
    
    bool empty() {
        if(q1.empty())
        {
            return true;
        }
        return false;
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