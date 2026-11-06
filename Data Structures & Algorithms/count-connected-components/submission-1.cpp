class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<bool> &visited,int node){
        visited[node] = true;

        for(int nbr: graph[node]){
            if(visited[nbr]==false){
                dfs(graph,visited,nbr);
            }
        }

        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);

        vector<vector<int>> graph(n,vector<int> (0)); 

        for(const vector<int> edge: edges){
            int to = edge[0];
            int from = edge[1];
            graph[to].push_back(from);
            graph[from].push_back(to);
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(graph,visited,i);
                count++;
            }
        }

        return count;
    }
};
