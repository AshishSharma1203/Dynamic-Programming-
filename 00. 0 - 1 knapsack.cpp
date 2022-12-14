//GFG Problem link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//* By top down approach 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
    //   applying top down approach 
    
    int t[n+1][W+1];
    
    // intialising intial conditions 
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            
            if(i==0 || j==0){
                t[i][j]=0;
            }
  
  
        }
    }
    
    for(int i =1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            
    if(wt[i-1]<=j){
      
    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]] ,t[i-1][j] );
      
  }
  else {
      t[i][j]= t[i-1][j];
  }
            
        }
    }
    

    
    return t[n][W];
    
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends


--------------------------------------------xxxxxxxxxxxxxxxxxxxx-------------------------

by memoization approach 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
     
    
    int solve(int W, int wt[], int val[], int n,vector<vector<int>> &t){
        
        //   using memoization 
    if(n==0 || W==0){
        return 0;
    }
    
    if(t[n][W]!=-1){
        return t[n][W];
        
    }
    
    if(wt[n-1]<=W){
        return t[n][W]=max(val[n-1]+ solve(W-wt[n-1],wt,val,n-1,t),solve(W,wt,val,n-1,t) );
    }
    else if(wt[n-1]>W){
        return t[n][W]=solve(W,wt,val,n-1,t);
    }
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
     // decalring 2d array 
  
    
    // initialising with -1 
     vector<vector<int>> t(n+1,vector<int>(W+1,-1));
    int ans =solve(W,wt,val,n,t);
  
    return ans; 
    
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends


