class DisjointSetUnion{
private:
    vector<int> parent;
public:
    DisjointSetUnion(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
    }

    bool join(int u,int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU==rootV) return false;

        parent[rootU] =  rootV;
        return true;
    }

    int find(int u){
        if(parent[u]==u){
            return u;
        }

        return find(parent[u]);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // optimal way will be to reconstruct this graph using DSU
        int n = edges.size(); // exactly n edges are present

        DisjointSetUnion* d = new DisjointSetUnion(n+1);

        for(const auto edge: edges){
            int to = edge[0];
            int from = edge[1];
            if(!d->join(to,from)) return edge;
        }

        return {};
    }
};
