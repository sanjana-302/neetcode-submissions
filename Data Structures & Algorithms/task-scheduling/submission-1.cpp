class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> counter;
        priority_queue<pair<int,char>> max_pq;
        queue<pair<int,pair<int,char>>> onHold;

        for(char c: tasks){
            counter[c]++;
        }

        for(const auto &[key,val]: counter){
            max_pq.push({val,key});
        }

        int time = 0;

        while(!max_pq.empty() || !onHold.empty()){
            // check if there is a task on hold that is available now 
            if(onHold.size()>0){
                pair<int,pair<int,char>> pending = onHold.front();
                int availableTime = pending.first;
                pair<int,char> availableTask = pending.second;

                if(availableTime<=time){
                    max_pq.push(availableTask);
                    onHold.pop();
                }else if(availableTime>time && max_pq.empty()){
                    time = availableTime;
                    max_pq.push(availableTask);
                    onHold.pop();
                }
            }

            // get the most frequent task 
            pair<int,char> frequentTask = max_pq.top();

            // perform the task 
            time++;
            frequentTask.first--;
            max_pq.pop();
            // apply cool down and insert in queue 
            if(frequentTask.first>0){
                int timeToStart = time + n;
                onHold.push({timeToStart,frequentTask});
            }

        }

        return time;
    }

    // X-2,Y-2, {}, 0
    // Y-2, {4,X-1}, 1
    // , {4,X-1}{5,Y-1},2
    // ,{5,Y-1},4+1
};
