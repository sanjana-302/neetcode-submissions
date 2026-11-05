class Solution {
public:
// thinks of diamond edge case - always imagine as edge case
// 0 
// 1 -> 4
// 2 -> 4
// 3 -> 1, 2
// 4 

// 0 -> unprocessed
// 1 -> in processing 
// processed
    bool dfs(vector<vector<int>> &adjList,vector<int> &visited,int node){
        visited[node] = 1;

        for(int nbr: adjList[node]){
            if(visited[nbr]==1){
                return true;
            }
            if(visited[nbr]==0){
                bool isCycleFound = dfs(adjList,visited,nbr);
                if(isCycleFound) return isCycleFound;
            }
        }
        visited[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect cycle in a directed graph 
        // two possible solutions for this
        // kahn's algorithm (bfs and indegree) && dfs 

        vector<vector<int>> adjList(numCourses,vector<int> (0)); 

        for(const vector<int> &courseSet : prerequisites){
            int course = courseSet[0];
            int courseDependency = courseSet[1];
            adjList[course].push_back(courseDependency);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                bool cycleIsPresent = dfs(adjList,visited,i);
                if(cycleIsPresent) return false;
            }
            // either reset visited here 
            visited.clear();
        }

        return true;
    }
};
