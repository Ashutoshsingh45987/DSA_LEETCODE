class Solution {
public:
    int n;
    void NSE( vector<int>&nums, vector<int>&nse){

        vector<int>st;

        for( int i=n-1;i>=0;i--){

            while(!st.empty()&&  nums[st.back()]>=nums[i]){
                st.pop_back();
            }

            if(!st.empty()){
                nse[i]= st.back();
            }

            st.push_back(i);
        }
    }


    void PSE( vector<int>&nums,vector<int>&pse){

        vector<int>st;

        for(int i=0;i<n;i++){

            while(!st.empty()&&  nums[st.back()]>nums[i]){
                st.pop_back();
            }

            if(!st.empty()){
                pse[i]= st.back();
            }

            st.push_back(i);

        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        n= arr.size();

        vector<int>nse( n, n);
        vector<int>pse(n,-1);

        NSE(arr,nse);
        PSE(arr,pse);


        long long  totalSum=0;
        int M=1e9+7;

        for( int i=0; i<n;i++){

            long long lc= i- pse[i];

            long long rc= nse[i]- i;

            long long val= ( arr[i]*lc* rc)%M;

            totalSum= (totalSum + val)%M;

        }

        return totalSum;
    }
};