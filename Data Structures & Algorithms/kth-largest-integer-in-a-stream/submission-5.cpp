class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> min_pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // create a min heap of size k 
        this->k = k;
        for(int n: nums){
            if(min_pq.size()>=k && n>min_pq.top()){
                min_pq.pop();
                min_pq.push(n);
            }else if(min_pq.size()<k){
                min_pq.push(n);
            }
        }
    }
    
    int add(int val) {
        if(min_pq.size()<k){
            min_pq.push(val);
        }
        else if(val>min_pq.top()){
            min_pq.pop();
            min_pq.push(val);
        }
        return min_pq.top();
    }
};
