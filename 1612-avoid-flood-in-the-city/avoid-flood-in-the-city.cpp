class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n= rains.size();

        unordered_map<int,int> mp;   // This basically stores the   lake->day (last day it rained over that lake)

        vector<int>s;        // This will contain the available dry day indices 
         

        vector<int>ans(n);

        for(int i=0 ;i<n;i++){

            int curr_lake= rains[i];

            if( rains[i]==0){      // This is dry day 

                ans[i]=1;  // default
                s.push_back(i);
            }
            else{

                ans[i]=-1;

                if( mp.find(curr_lake)!=mp.end()){

                    int last_rain_day= mp[curr_lake];

                    auto it= upper_bound(s.begin(), s.end(), last_rain_day);

                    if(it== s.end()) return {};

                    ans[*it]= curr_lake;

                    s.erase(it);

                }

                //update the last day this lake rained 

                mp[curr_lake]=i;
              
            }
        }

        return ans;
        
    }
};