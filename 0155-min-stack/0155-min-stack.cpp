class MinStack {
public:
    stack<pair<int,int>> st;
    int minimum;
    MinStack() {
        minimum = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            int minvalue = min(val,st.top().second);
            cout<<"minvalue"<<minvalue<<endl;
            st.push({ val, min(val,st.top().second) });
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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