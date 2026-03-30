class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int , int>>>adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<int>dist(n, 1e9);
        pq.push({0, {src, 0}});
        dist[src] = 0;

        while(!pq.empty()){
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int d = pq.top().second.second;
            pq.pop();
            if(stops > k) continue;
            for(auto it : adj[node]){
                int wt = it.second;
                int adjNode = it.first;
                if(dist[adjNode] > wt + d){
                    dist[adjNode] = wt + d;
                    pq.push({stops + 1, {adjNode, wt + d}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};