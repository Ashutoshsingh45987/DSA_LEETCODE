class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n= heights.size();

        vector<int>res(n,0);

        vector<int>st;

        for( int i=n-1;i>=0;i--){

            int val=0;

            while(!st.empty() && st.back()<heights[i]){
                val++;
                st.pop_back();
            }

            if( !st.empty()){
                val++;
            }

            st.push_back( heights[i]);

            res[i]=val;
        }

        return res;
        
    }
};