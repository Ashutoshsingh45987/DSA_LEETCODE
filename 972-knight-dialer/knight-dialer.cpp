class Solution {
public:
    typedef long long ll;
    int mod= 1e9+7;

    unordered_map<int,vector<int>> adj;

    int t[50001][11];
    int ans=0;

    int  solve( int n, int curr){

        if(n==0){
            return 1;
        }

        // memo
        if(t[n][curr]!=-1) return t[n][curr];

        int res=0;

        for(auto next: adj[curr]){

            res= (res+solve(n-1, next)%mod)%mod;
        }


        return t[n][curr]=res;

    }
    int knightDialer(int n) {

        // fill the adj

        adj[0].push_back(4);
        adj[0].push_back(6);
        adj[1].push_back(6);
        adj[1].push_back(8);
        adj[2].push_back(9);
        adj[2].push_back(7);
        adj[3].push_back(8);
        adj[3].push_back(4);
        adj[4].push_back(9);
        adj[4].push_back(3);
        adj[4].push_back(0);
        adj[6].push_back(1);
        adj[6].push_back(7);
        adj[6].push_back(0);
        adj[7].push_back(2);
        adj[7].push_back(6);
        adj[8].push_back(1);
        adj[8].push_back(3);
        adj[9].push_back(4);
        adj[9].push_back(2);

        memset(t,-1, sizeof(t));
        
        for(int i=0;i<=9;i++){

            ans= (ans+solve(n-1, i)%mod )%mod;
        }

       
        return ans;
    }
};