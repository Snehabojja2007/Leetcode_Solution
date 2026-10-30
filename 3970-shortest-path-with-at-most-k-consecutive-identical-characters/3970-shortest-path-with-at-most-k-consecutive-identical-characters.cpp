const long long inf = LLONG_MAX/4;
#define V vector< long long> 
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k+1, inf));
        priority_queue< V, vector<V>, greater<V> > pq;
        dist[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto e = pq.top();
            long long dis = e[0];
            int node = e[1];
            int cur = e[2];
            pq.pop();
            if(dis != dist[node][cur]) continue;
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                int newCur = (labels[adjNode] == labels[node] ? cur+1 : 1);
                if(newCur > k) continue;
                if(dis + edgeWt < dist[adjNode][newCur]){
                    dist[adjNode][newCur] = dis + edgeWt;
                    pq.push({dist[adjNode][newCur], adjNode, newCur});
                }
            }
        }
        long long ans = inf;
        for(int i = 1; i<=k; i++){
            ans = min(ans, dist[n-1][i]);
        }
        return ans == inf ? -1:ans;
    }
};