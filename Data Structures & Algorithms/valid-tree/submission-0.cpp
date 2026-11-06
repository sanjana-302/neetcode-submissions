class Solution {
public:
    bool dfs(vector<vector<int>> &adjList,set<int> &visited,int node,int parent){
        visited.insert(node);

        for(int nbr: adjList[node]){
            if(nbr==parent) continue;
            if(visited.find(nbr)!=visited.end()) return false;
            bool checkForNbr = dfs(adjList,visited,nbr,node);
            if(checkForNbr==false) return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // a tree cannot have cycle 
        // job is to detect a cycle in given pair of edges 
        // also it should be connected

        vector<vector<int>> adjList(n,vector<int> (0));

        for(const auto edge: edges){
            int from = edge[0];
            int to = edge[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        set<int> visited;

        bool isGraphValidTree = dfs(adjList,visited,0,-1);

        return isGraphValidTree && visited.size()==n;

    }
};
