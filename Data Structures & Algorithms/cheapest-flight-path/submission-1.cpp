class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        
        // Run k + 1 times (at most k + 1 flights / k stops)
        for (int i = 0; i <= k; ++i) {
            vector<int> tmpPrices = prices; // Snapshot of previous prices
            
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];
                
                if (prices[u] != INT_MAX) {
                    tmpPrices[v] = min(tmpPrices[v], prices[u] + cost);
                }
            }
            prices = tmpPrices; // Move to the next level
        }
        
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
