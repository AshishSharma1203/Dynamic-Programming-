// 43).Egg Dropping Problem Recursive

// Video Link : https://youtu.be/S49zeUjeUL0  
//  GFG Problem Link : https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

//                   ------->>>>>>>>>>>------------>>>>>>>>>>>>________CODE________<<<<<<<<<<<<------------<<<<<<<<<<<<<<<<<<<<<<<<<<<           //

int eggDrop(int n, int k) 
    {
        // your code here
        
        if(k==0 || k==1)
        {
            return k; 
        }
        if(n==1)
        
        {
            return k; 
        }
        
        int ans= INT_MAX; 
        
        for(int a=1;a<=k;a++)
        {
            
            int temp= 1 + max(eggDrop(n-1,a-1), eggDrop(n,k-a));
//           max is used as we have to consider worst case scenario  
            ans=min(ans,temp);
//             min is used to store the minimum no of attempts (as asked in question )  
        }
        
        return ans; 
        
    }
