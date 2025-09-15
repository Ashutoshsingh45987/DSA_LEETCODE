class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

        int n= coins.size();

        unordered_map<int,vector<int>> adj;

        vector<int>deg(n);

        for(auto edge:edges){

            int u= edge[0], v= edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;
        }


        // phase 1 pruing - removing  leaf withoud coins 

        queue<int>q;

        for(int i=0;i<n;i++){
            if( deg[i]==1 && coins[i]==0) q.push(i);
        }

        while(!q.empty()){

            int node= q.front();
            q.pop();


            deg[node]=0;

            for( auto v: adj[node]){

                if(deg[v]>0){

                    deg[v]--;
                    if(deg[v]==1 && coins[v]==0) q.push(v);
                }
            }
        }
        
        // phase 2 pruning  - remove node from where coin can be collected from 

        for( int s=0;s<2;s++){  // since we can move 2 steps , we need to prune 2 time 

            for(int i=0;i<n;i++){
                if(deg[i]==1) q.push(i);
            }

            while(!q.empty()){
                int u=q.front();
                q.pop();

                if(deg[u]==0) continue;
                deg[u]=0;

                for(auto v:adj[u]){

                    if(deg[v]>0) deg[v]--;
                }
            }
        }


        int ans= 0;

        for(auto e: edges){

            if(deg[e[0]]>0 && deg[e[1]]>0) ans++;
        }

        return ans*2;
        
    }
};