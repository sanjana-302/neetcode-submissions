class Solution {
public:
    // traversal over maps over vectors when working with graphs 
    // working with auto, const and & when traversing and editing values in memory
    void dfs(map<string,vector<pair<string,bool>>> &adjList,string node,vector<string> &result){

        for(auto &nbr: adjList[node]){
            string nbrNode = nbr.first;
            bool isExhausted = nbr.second;
            if(isExhausted==false){
                nbr.second = true;
                dfs(adjList,nbrNode,result);
            }
        }

        result.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<pair<string,bool>>> adjList;
        // map will look like this
        // JFK : HOU,Yes CNG,No

        for(const auto &ticket : tickets){
            adjList[ticket[0]].push_back({ticket[1],false});
        }

        // sort all vectors within adjList

        for(auto &ticket : adjList){
            sort(ticket.second.begin(),ticket.second.end());
        }

        vector<string> result;

        // perform modified post order dfs 
        dfs(adjList,"JFK",result);
        reverse(result.begin(),result.end());
        return result;
    }
};
