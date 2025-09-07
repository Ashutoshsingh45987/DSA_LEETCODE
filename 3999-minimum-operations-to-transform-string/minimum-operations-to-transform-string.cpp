class Solution {
public:
    int minOperations(string s) {
        
        int n= s.size();

        vector<int>freq(26, 0);

        for(auto it: s){

            int ind= it-'a';
            freq[ind]++;
        }

        int target=0;
        int count=0;

        for(int i=25;i>=1;i--){

            if(freq[i]>0){
                count+=  (target-i+26)%26;

                target=i;
            }
        }

        return count;
    }
};