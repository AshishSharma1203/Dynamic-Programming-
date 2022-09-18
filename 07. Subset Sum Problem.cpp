//GFG Problem Link --> https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:


// recursive code  
// bool check(vector<int> arr,int sum ,int  n){
    
//     if(sum==0){
//         return true; 
//     }
    
//     if(n==0){
//         if(sum==0){
//             return true; 
//         }
//     }
    
//     if(arr[n-1]<=sum){
//         if(check(arr,sum-arr[n-1],n-1)){
//             return true; 
//         }
//         if(check(arr,sum,n-1)){
//             return true; 
//         }
//     }
    
//     else{
        
//         return check(arr,sum,n-1);
        
//     }
    
//     return false; 
    
// }


// memoization approach  

// bool   solve(vector<vector<int>> t,vector<int> arr, int sum,int n){
    
//     if(sum==0){
//         return true; 
//     }
//     if(n==0){
//       return sum==0?true:false; 
//     }    
    
    
//     if(t[n][sum]!=-1){
//             return t[n][sum];
//         }
    
//     if(arr[n-1]<=sum){


//   return t[n][sum]= solve(t,arr, sum,n-1) || solve(t,arr,sum-arr[n-1],n-1);
//     }
    
//     else{
        
       
//       return t[n][sum]=solve(t,arr,sum,n-1); 
        
//     }
    
// }


  bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        int n =arr.size();
         // bool flag= check(arr,sum,n);   recursive function call 
         
      
    //   initialisng the vector  
        //  vector<vector<int>> t(n+1,vector<int>(sum+1,-1));

        
        // bool  ans= solve(t,arr,sum,n);
        
        // return ans; 

     int t[n+1][sum+1];
     
     for(int i=0;i<n+1;i++){
         for(int j=0;j<sum+1;j++){
             
             if(i==0){
          t[i][j]=false;       
             }
             if(j==0){
                 t[i][j]=true; 
             }
             
         }
     }
     
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]= t[i-1][j];
            }
            
        }
    }
return t[n][sum];
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
