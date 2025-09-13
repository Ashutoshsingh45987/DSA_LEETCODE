class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n= nums.size();

        if(n<=1) return;

        // find the farthest elemnent/ first element from right  : that is  smaller than the next ele

        int i= n-2;

        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }

        // now find the first element from right that is greater than i

        if(i>=0){
            int j=n-1;

            while(j>=0 && nums[i]>=nums[j]){
                j--;
            }

            // now swap the elements 

            swap(nums[i],nums[j]);
        }

        
        // reverse the elemets to right of i 

        reverse(nums.begin()+i+1, nums.end());


        

        return;
        
    }
};