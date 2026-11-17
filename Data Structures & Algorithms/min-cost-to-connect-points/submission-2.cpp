class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    bool unionOnDsu(int u,int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU==rootV) return true; 

        if(rank[rootU]>rank[rootV]){
            parent[rootV] = rootU;
        }else if(rank[rootU]<rank[rootV]){
            parent[rootU] = rootV;
        }else{
            rank[rootU]++;
            parent[rootV] = rootU;
        }

        return false; // same root, true -> cycle
    }

    int find(int x){
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // connect all vertices with minimum total edge wt and no cycle 

        // for all points calculate manhattan distance and add in min pq
        // min pq will be of type - (wt, array coordinate index)

        priority_queue<pair<int,pair<int,int>>, std::vector<pair<int,pair<int,int>>>, std::greater<pair<int,pair<int,int>>>> min_pq;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            for(int j=i+1;j<points.size();j++){
                int xx = points[j][0];
                int yy = points[j][1];

                int dist = abs(x-xx) + abs(y-yy);

                min_pq.push({dist,{i,j}});
            }

        }

        int minWt = 0;
        int count = 0; // count of edges, we aim for n-1 if n in number of nodes
        int n = points.size();
        DSU* d = new DSU(n);

        while(count<n-1 && min_pq.size()>0){
            auto front = min_pq.top();
            int wt = front.first;
            int p1 = front.second.first;
            int p2 = front.second.second;

            bool hasCycle = d->unionOnDsu(p1,p2);
            min_pq.pop();

            if(hasCycle==false){
                count++;
                minWt += wt;
            }
        }

        return minWt;

    }
};
