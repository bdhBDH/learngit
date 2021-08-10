/*
	剑指offer 09： 用两个栈实现队列
    2021/8/2

*/class CQueue {
public:
 stack<int>cache;
 stack<int>ans;
    CQueue() {

    }
    
    void appendTail(int value) {
        cache.push(value);
    }
    
    int deleteHead() {
        if(ans.empty())
        {
            if(cache.empty()) return -1;
            while(cache.size())
            {
                auto top = cache.top();
                cache.pop();
                ans.push(top);
            }
        }
         int x = ans.top();
            ans.pop();
            return x;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */