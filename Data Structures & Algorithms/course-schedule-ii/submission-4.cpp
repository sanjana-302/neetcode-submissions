class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort 
        // count indegrees first 
        // start from element that has 0 indegree

        vector<int> res;

        vector<int> indegree(numCourses,0);

        vector<vector<int>> adjList(numCourses,vector<int> (0));

        for(const auto prerequisite: prerequisites){
            int from = prerequisite[0];
            int to = prerequisite[1];

            // count indegree
            indegree[from]++;

            // make graph
            adjList[to].push_back(from);
        }
        // indegree : 0:1, 1:0, 2,0
        queue<int> q;
        bool hasZeroIndegree = false;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                hasZeroIndegree = true;
                q.push(i);
            }
        }

        if(hasZeroIndegree==false) return res;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            res.push_back(front);
            for(int nbr: adjList[front]){
                if(indegree[nbr]==1){
                    indegree[nbr]--;
                    q.push(nbr);
                }else{
                    indegree[nbr]--;
                }

            }
        }

        return res.size()==numCourses? res : std::vector<int>{};
    }
};
