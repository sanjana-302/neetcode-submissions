class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // shortest path algorithm -> from source to all nodes

        vector<vector<pair<int,int>>> adjList(n+1);

        for(const auto &time : times){
            int from = time[0];
            int to = time[1];
            int t = time[2];

            adjList[from].push_back({to,t});
        }

        vector<int> dist(n+1,INT_MAX);

        // create a minHeap -> will store pair like this {wt,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // insert source node and corresponding wt
        dist[k] = 0;
        minHeap.push({0,k});

        while(!minHeap.empty()){
            pair<int,int> currNode = minHeap.top();
            minHeap.pop();
            int wt = currNode.first;
            int node = currNode.second;

            for(const auto nbr: adjList[node]){
                int nbrNode = nbr.first;
                int currWt = nbr.second;

                if(currWt+wt < dist[nbrNode]){
                    dist[nbrNode] = currWt+wt;
                    minHeap.push({currWt+wt,nbrNode});
                }
            }
        }

        int minTimeNeededToReachAllNode = INT_MIN;

        for(int i=1;i<=n;i++){
            minTimeNeededToReachAllNode = max(minTimeNeededToReachAllNode,dist[i]);
        }

        return minTimeNeededToReachAllNode==INT_MAX ? -1 : minTimeNeededToReachAllNode;
    }
};
