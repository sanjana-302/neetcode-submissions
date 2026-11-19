class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq;

        for(int stone: stones){
            max_pq.push(stone);
        }

        while(max_pq.size()>1){
            int firstStone = max_pq.top();
            max_pq.pop();
            int secondStone = max_pq.top();
            max_pq.pop();
            int remainingWt = firstStone-secondStone;
            if(remainingWt!=0) max_pq.push(remainingWt);
        }

        return max_pq.size()==1?max_pq.top():0;
    }
};
