class Solution {
public:
    unordered_map<int, vector<int>> adj;

    void dfs( int u, vector<int>&disc, vector<int>&low, vector<int>&parent, vector<vector<int>>&bridges){

        static int time=0;
        disc[u]=low[u]=time;
        time++;

        for(auto v : adj[u]){

            if(disc[v]==-1){

                parent[v]=u;

                dfs(v, disc, low, parent, bridges);

                low[u]= min(low[u], low[v]);

                if(low[v]>disc[u]){
                    bridges.push_back({u,v});
                }
            }
            else if( v!=parent[u]){

                low[u]= min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        for(auto it: connections){

            int u= it[0];
            int v= it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // disc
        vector<int>disc(n,-1);

        // low :  the earliest discovery time reachable through node
        vector<int>low(n,-1);

        //parent
        vector<int>parent(n,-1);

        // bridge
        vector<vector<int>>bridges;

        for(int i=0;i<n;i++){

            if(disc[i]==-1){
                dfs(i,disc, low, parent, bridges);
            }

        }
        

        return bridges;
    }
};