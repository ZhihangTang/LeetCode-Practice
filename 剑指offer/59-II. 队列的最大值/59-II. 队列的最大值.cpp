class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(max_q.empty())return -1;
        int t=max_q.front();
        return t;
    }
    
    void push_back(int value) {
        while(!max_q.empty()&&max_q.back()<value){
            max_q.pop_back();
        }
        max_q.push_back(value);
        q.push(value);

    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int t=q.front();
        q.pop();
        if(t==max_q.front()) max_q.pop_front();
        return t;
    }
private:
    queue<int> q;
    deque<int> max_q;
    // max_q 队头始终存最大值，元素入队的时候，分别max_q队尾比较，队尾小于当前值，则弹出。
    // 元素出队时候，判断弹出元素q.font() 是否是max_q.front()是最大值，是则弹出，否则不做处理。
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */