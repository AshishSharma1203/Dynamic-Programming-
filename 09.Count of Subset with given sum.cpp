//GFG Problem Link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// Error: Code not accepted 

// Progress --> pending  ( not accepted ) .....->> 

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
// 	int  solve(int arr[],int n,int sum ,int &count){
	    
// 	     if(sum==0){
// 	       return 1; 
// 	    }
	
// 	    if(n==0){
// 	        return sum==0?1:0;
// 	    }
	   
// 	 if(arr[n-1]<=sum){
//         int a= solve(arr,n-1,sum-arr[n-1],count);
// 	     int b= solve(arr,n-1,sum,count);
// 	     return a+b; 
// 	 }
// 	 else{
	     
// 	     return solve(arr,n-1,sum,count);
	     
// 	 }
	    
	    
// 	}
	
// 	using memoization \

  int  solve(int arr[],int sum, int n, vector<vector<int>> &t){
      
      if(sum==0){
          return 1;
      }
      
      if(n==0){
          return sum==0?1:0;
      }
      
      if(t[n][sum]!=-1){
          return t[n][sum];
      }
      
       	 if(arr[n-1]<=sum){
        return t[n][sum]=solve(arr,sum-arr[n-1],n-1,t) + solve(arr,sum,n-1,t);
	 }
	 else{
	     
	     return t[n][sum]=solve(arr,sum,n-1,t);
	     
	 }
      
      return t[n][sum];
      
  }
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> t(n+1,vector<int> (sum+1,-1)); 
        
        int ans =0;int count=0;
    count=solve(arr,sum,n,t); 
        
        return count; 
        
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends


