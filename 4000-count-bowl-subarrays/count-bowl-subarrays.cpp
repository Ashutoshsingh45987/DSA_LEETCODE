class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {

        int n= nums.size();

        vector<int> prevGreatest(n,-1);
        vector<int> nextGreatest(n,-1);


        vector<int> st;
        
        for(int i=0;i<n;i++){

            while(!st.empty() && nums[st.back()]< nums[i]){
                st.pop_back();
            }

            if(!st.empty()){
                prevGreatest[i]= st.back();
            }

            st.push_back(i);
        }

        st.clear();

        for(int i= n-1;i>=0;i--){

            while(!st.empty() && nums[st.back()]<nums[i]){
                st.pop_back();
            }

            if(!st.empty()){
                nextGreatest[i]= st.back();
            }

            st.push_back(i);
        }

        int count =0;

        for(int i=0;i<n;i++){

            if(prevGreatest[i]!=-1 &&  nextGreatest[i]!=-1){
                count++;
            }
        }

        return count;
        
    }
};