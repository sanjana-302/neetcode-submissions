class MedianFinder {
public:
    priority_queue<int> maxPq;
    priority_queue<int,vector<int>,greater<int>> minPq;
    int count;
    MedianFinder() {
        count = 0;
    }

    // ________1 (max) || 2 (min)_______ 
    // 5 || 3
    // 3 || 5
    
    void addNum(int num) {
        count++;
        // 1 2 3 7 0 
        // always start from max heap 
        // max , min : 1
        // max 1, min : 2
        // max 1, min 2, : 3 
        // max 1, min 2,3 : 7 => issue with 7 is if i just insert and do not remove min will max-min will have inbalance of more than 1 
        // max 1,2 min 3,7 : 0 
        // max 0,1,2 min 3,7 : 12 
        // what if state was like this?
        // max 0,1,2,3 min 4,7,12,13 : 3

        // add edge case for empty pq

        if(maxPq.size()==0 && minPq.size()==0){
            maxPq.push(num);
            return;
        }else if(minPq.size()==0){
            if(maxPq.top()>num){
                int x = maxPq.top();
                minPq.push(x);
                maxPq.pop();
                maxPq.push(num);
            }else{
                minPq.push(num);
            }
            return;
        }

        int leftMax = maxPq.top();
        int rightMin = minPq.top();

        if(num>rightMin){
            minPq.push(num);
        }else{
            maxPq.push(num);
        }

        // check if difference in size becomes greater than 1 

        int sizeLeft = maxPq.size();
        int sizeRight = minPq.size();

        while(abs(sizeLeft-sizeRight)>1){
            if(sizeLeft>sizeRight){
                int leftVal = maxPq.top();
                maxPq.pop();
                minPq.push(leftVal);
            }else{
                int rightVal = minPq.top();
                minPq.pop();
                maxPq.push(rightVal);
            }
            sizeLeft = maxPq.size();
            sizeRight = minPq.size();
        }
    }
    
    double findMedian() {
        double currentMedian = INT_MAX; // garbage val
        if(count%2){
            if(minPq.size()>maxPq.size()){
                return currentMedian = minPq.top();
            }else{
                return currentMedian = maxPq.top();
            }
        }else{
            return currentMedian = (minPq.top()+maxPq.top())/2.0;
        }

        return currentMedian;
    }
};
