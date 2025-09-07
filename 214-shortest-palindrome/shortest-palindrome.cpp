class Solution {
public:
    void computeLPS( string str, vector<int>&lps){

        int len=0;

        lps[0]=0;
        int i=1;

        while(i<str.size()){

            if(str[i]==str[len]){
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
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());

        vector<int>lps(2*n+1,0);

        computeLPS( s+"_"+rev  ,lps);

        string toadd= rev.substr(0,n-lps[2*n]);


        return toadd + s;


    }
};