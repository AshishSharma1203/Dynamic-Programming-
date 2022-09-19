// 44 & 45 ). Egg Dropping Problem Memoization 

// Video Link : https://youtu.be/jkygQmOiCCI
// GFG Problem link : https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1 


//                   ------->>>>>>>>>>>------------>>>>>>>>>>>>________CODE________<<<<<<<<<<<<------------<<<<<<<<<<<<<<<<<<<<<<<<<<<            //


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    
      int dp[201][201];
   
   int solve(int n,int k)
   {
       //base case
       
       if(n==1) return k;
       if(k==0) return 0;
       
       //memoization
       if(dp[n][k]!=-1) return dp[n][k];
       
     
       
       int ans=INT_MAX;   //we want minimum value
       
       for(int i=1;i<=k;i++){
           //egg broken
           int broken=solve(n-1,i-1);
           //egg not broken
           int not_broken=solve(n,k-i);
           
           int maxval=max(broken,not_broken);
           
           ans=min(ans,maxval+1);
       }
       
       return dp[n][k]=ans;
   }
   
int eggDrop(int n, int k) 
   {
       // your code here
       memset(dp,-1,sizeof(dp));
       
       return solve(n,k);
       
   }

    
};
