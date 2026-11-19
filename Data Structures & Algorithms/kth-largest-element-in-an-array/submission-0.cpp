class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> min_pq;

        for(int n: nums){
            if(min_pq.size()<k){
                min_pq.push(n);
            }else{
                int top = min_pq.top();
                if(n>=top){
                    min_pq.pop();
                    min_pq.push(n);
                }
            }
        }

        return min_pq.top();
    }
};
