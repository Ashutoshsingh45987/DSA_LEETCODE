class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        // modified dijkstra 

        int n= grid.size();

   
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;

        // waterlevel,  i, j

        vector<vector<bool>>vis(n ,vector<bool>(n,false));

        vector<vector<int>>dir= { {0,1},{1,0},{-1,0},{0,-1}};

        pq.push({grid[0][0],{0,0}});

        vis[0][0]=true;

        while(!pq.empty()){

            auto v= pq.top();

            pq.pop();

            int level=  v.first;
            int i= v.second.first;
            int j= v.second.second;

            if( i==n-1 && j==n-1) return level;

            for( int d=0;d<4;d++){

                int ni= i+dir[d][0];
                int nj= j+ dir[d][1];

                if( ni>=0 && nj>=0 && ni<n && nj<n && vis[ni][nj]==false){

                    int maxleveltoreach= max(grid[ni][nj], level);

                    pq.push({maxleveltoreach, {ni,nj}});

                    vis[ni][nj]= true;
                }
            }
            
        }


        return -1;
    }
};