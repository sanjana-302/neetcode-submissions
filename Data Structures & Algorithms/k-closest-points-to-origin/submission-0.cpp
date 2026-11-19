class Solution {
public:
    double euclideanDistance(int x,int y){
        return sqrt(pow(x,2)+pow(y,2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap 
        priority_queue<pair<double,int>> max_pq; // (distance,coordinate idx)

        // define a method to calculate e distance 

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            double distance = euclideanDistance(x,y);

            if(max_pq.size()<k){
                max_pq.push({distance,i});
            }else{
                auto top = max_pq.top();
                double topDistance = top.first;
                int idx = top.second;
                if(topDistance>distance){
                    max_pq.pop();
                    max_pq.push({distance,i});
                }
            }
        }

        vector<vector<int>> result;

        while(!max_pq.empty()){
            auto top = max_pq.top();
            result.push_back(points[top.second]);
            max_pq.pop();
        }

        return result;
    }
};
