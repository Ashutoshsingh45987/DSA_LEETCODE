class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {

        unordered_map<int,int>mp;
        int n = arrivals.size();
        int discard = 0;
            
        for(int i = 0; i < n; i++){
            mp[arrivals[i]]++;

            if(i >= w){
                mp[arrivals[i-w]]--;
                 
            }

            if(mp[arrivals[i]] > m){
                discard++;
                mp[arrivals[i]]--;
                arrivals[i] = 0;

            }
        }

        return discard;
    }
};
