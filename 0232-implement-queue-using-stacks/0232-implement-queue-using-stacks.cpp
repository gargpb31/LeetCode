class MyQueue {
public:

    stack<int> s1,s2;
    MyQueue() {
            while(!s1.empty()) s1.pop();
            while(!s2.empty()) s2.pop();
     }
    
    void push(int x) {
       while(!s1.empty())
       {
            int y = s1.top();
            s1.pop();
            s2.push(y);

       }
       s2.push(x);
       while(!s2.empty())
       {
       int y = s2.top();
            s2.pop();
        s1.push(y);
       }


    }
    
    int pop() {
        int x = s1.pop();
        return x;
    }
    
    int peek() {
        int x = s1.top();
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */