/*  AVOID DOUBLE COUNTING....................................
https://leetcode.com/problems/coin-change-2/submissions/

You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.

*/

//O(N*K*K) solution
/*

Here dp[i][j] = no of ways to make i from all coins with index<=j
Hence from dp[i][j] we can go to dp[i+coins[x]][x] where j<=x<=K-1 (K is the size of coins array)
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.size()==0) { if(amount) return 0; return 1; };
        unsigned int dp[amount+1][coins.size()] ;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=0;i<coins.size()&&coins[i]<=amount;i++)
        { dp[coins[i]][i]=1; }
        
        for(int i=1;i<amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {   if(dp[i][j]!=0)
                {
                for(int k=j;k<coins.size();k++)
                {
                if(i+coins[k]<=amount){dp[i+coins[k]][k]+=dp[i][j];}
                }
                }
            }
        }
        int ans=0;
        for(int i=0;i<coins.size();i++){ ans+=dp[amount][i]; }
        return ans;
    }
};

