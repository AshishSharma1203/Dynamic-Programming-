/*

26 .Longest Palindromic Subsequence
Video Link : https://youtu.be/wuOOOATz_IA
GFG problem link : https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

Code : -------------->>>>>>>>>>>>>>>>>>>>

Approach: i).  make another string identical to given one ;
ii). Reverse that string and 
iii). then find the length of  longest common subsequence 

----------------------xxxxxxxxxxxxx---------------xxxxxxxxxxxxx_________CODE___________xxxxxxxxxxxxxxx---------------------xxxxxxxxxxxxxxx----------
*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
   int LCS(string s1,string s2,int n,int m, vector<vector<int>> &t)
    {
        
        
        if(n==0 || m==0)
        {
            return 0;
        }
        
        if(t[n][m]!=-1)
        {
            return t[n][m];
        }
        
        if(s1[n-1]==s2[m-1])
        {
            return t[n][m]= 1+LCS(s1,s2,n-1,m-1,t);
        }
        
        else{
            return t[n][m]= max(LCS(s1,s2,n-1,m,t), LCS(s1,s2,n,m-1,t));
        }
        
        
    }
  
    int longestPalinSubseq(string A) {
        //code here
        
        string s1=A;
        string s2= A;
        reverse(s2.begin(),s2.end());
        
        int n=A.size(),m=n;
        
        vector<vector<int>> t (n+1,vector<int> (m+1,-1) ) ; 
        
        int ans=LCS(s1,s2,n,m,t);
        
        return ans; 
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}


// } Driver Code Ends
