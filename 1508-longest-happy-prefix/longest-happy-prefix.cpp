class Solution {
public:
    void computeLPS( string str, vector<int>&lps){

        lps[0]=0;
        int len=0;

        int i=1;

        while( i<str.size()){

            if( str[i]==str[len]){
                len++;
                lps[i]= len;
                i++;
            }
            else{

                if(len!=0){
                    len= lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string longestPrefix(string s) {

      
        int n= s.size();
        vector<int>lps(n,0);

        computeLPS(s, lps);

        int length= lps[n-1];

        return  s.substr(0,length);

        
    }
};