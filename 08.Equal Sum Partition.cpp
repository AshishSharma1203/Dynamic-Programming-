// GFG problem Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:


bool solve(int arr[],int n,int sum,vector<vector<int>> &t){
    
    if(n==0 ){
        return sum==0?1:0;
    }
    if(sum==0){
        return 1;
    }
    
    if(t[n][sum]!=-1){
        return t[n][sum];
    }
    
    if(arr[n-1]<=sum){
        return t[n][sum] = solve(arr,n-1,sum-arr[n-1],t) || solve(arr,n-1,sum,t);
    }
    else if(arr[n-1]>sum){
        return t[n][sum]= solve(arr,n-1,sum,t);
    }
    
    
}



    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum =0;
        for(int i=0;i<N;i++){
            sum+= arr[i];
        }
        
        if(sum%2!=0){
            return 0; 
        }
        
      vector<vector<int>> t (N+1,vector<int> (sum+1,-1)); 
      
            return solve(arr, N,sum/2,t);
        
        
       --------------------------xxxxxxxxxxxxxxx---------------xxxxxxxxxxxxxxxxxxxxxxxxxxxx-----------------------xxxxxxxxxxxxxxxxxxx--------------------------------
        
       -->  applying top down approach 
        
    //     vector<vector<bool>> t;
        
    //     for(int i=0;i<N;i++){
    //         for(int j=0;j<N;j++){
                
    //             if(i==0){
    //                 t[i][j]=false;
    //             }
    //             if(j==0){
    //                 t[i][j]=true;
    //             }
    //         }
    //     }
        
    //     sum=sum/2;
    //   for(int i=1;i<N;i++){
    //       for(int j=1;j<N;j++){
               
    //           if(arr[i]<=j){
    //               t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
    //           }
    //           else{
    //               t[i][j]=t[i-1][j];
    //           }
               
    //       }
    //   }
    //   return t[N][sum];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
