class MyCircularQueue {
    int mCapacity;
    int mHeadIdx;
    int mCnt;
    std::vector<int> mArray;
public:
    MyCircularQueue(int k) {
        mCapacity = k;
        mHeadIdx = 0;
        mCnt = 0;
        mArray.assign(k, 0);
    }
    
    bool enQueue(int value) {
        if (mCnt == mCapacity)
        {
            return false;
        }
        mArray[(mHeadIdx+mCnt) % mCapacity] = value;
        mCnt++;
        return true;
    }
    
    bool deQueue() {
        if (mCnt == 0)
        {
            return false;
        }
        mArray[mHeadIdx] = 0;
        mHeadIdx = (mHeadIdx + 1) % mCapacity;
        mCnt--;
        return true;
    }
    
    int Front() {
        return mCnt == 0 ? -1 : mArray[mHeadIdx];
    }
    
    int Rear() {
        return mCnt == 0 ? -1 : mArray[(mHeadIdx + mCnt - 1)%mCapacity];
    }
    
    bool isEmpty() {
        return mCnt == 0;
    }
    
    bool isFull() {
        return mCnt == mCapacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
