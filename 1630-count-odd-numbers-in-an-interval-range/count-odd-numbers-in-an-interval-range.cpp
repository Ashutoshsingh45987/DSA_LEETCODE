class Solution {
public:
    int countOdds(int low, int high) {

        int start= low%2==0?low+1:low;

        int count=0;

        for( int i= start;i<=high;i=i+2){
            count++;
        }

        return count;
        
    }
};