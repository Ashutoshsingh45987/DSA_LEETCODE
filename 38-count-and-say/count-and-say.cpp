class Solution {
public:
    string  solve( int n){

        if(n==1){
            return "1";
        }

        string res="";

        string str= solve(n-1);

        // process

        for( int i=0;i<str.size();i++){

            char ch= str[i];
            int count=1;

            while( i< str.size()&&  str[i]==str[i+1]){
                i++;
                count++;

            }

            res= res+ to_string(count)+ ch;
        }

        return res;
    }
    string countAndSay(int n) {
        return solve( n);
    }
};