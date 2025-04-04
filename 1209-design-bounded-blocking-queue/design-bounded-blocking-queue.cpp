class BoundedBlockingQueue {
public:
    queue<int> q;
    int cap;
    int i;
    mutex mtx;
    condition_variable cv;
    BoundedBlockingQueue(int capacity) {
        cap=capacity;
        i=0;
    }
    
    void enqueue(int element) {
        unique_lock lock(mtx);
        cv.wait(lock, [this](){
            return i<cap;
        });
       
            q.push(element);
            i++;
            cv.notify_all();
        
    }
    
    int dequeue() {
        unique_lock lock(mtx);
        cv.wait(lock,[this](){
            return i>0;
        });
        
            int val=q.front();
            q.pop();
            i--;
             cv.notify_all();
            return val;
       
    }
    
    int size() {
        unique_lock lock(mtx);
        return i;
    }
};