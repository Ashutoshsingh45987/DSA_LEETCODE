class Solution {
public:

    int n,a,b;
    int t[201][101][101];

    bool solve( int i, int j ,int k ,string &s3, string &s1, string &s2 ){

        if(i==n && j==a && k==b){
            return true;
        }
        else if( i!=n && j==a && k==b){
            return false;
        }
        else if( s3[i]!=s1[j] && s3[i]!=s2[k]){
            return false;
        }

        // memo

        if(t[i][j][k]!=-1) return t[i][j][k];



        bool takes1= false,  takes2=false;

        if( j<a && s3[i]== s1[j]){
             
            takes1= solve( i+1,j+1,k,s3,s1,s2);
        }

        if( k<b && s3[i]==s2[k]){
            takes2= solve(i+1,j,k+1, s3,s1,s2);
        }

        return  t[i][j][k]=takes1 || takes2;


    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s3.size();
        a=s1.size();
        b=s2.size();

        memset(t,-1,sizeof(t));

        return solve( 0,0,0,s3,s1,s2);
    }
};