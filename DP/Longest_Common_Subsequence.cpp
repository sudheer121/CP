// Longest Common Subsequence 
// Atcoder : https://atcoder.jp/contests/dp/submissions/16999394
// Learning : don't make silly mistakes
//only length : https://leetcode.com/problems/longest-common-subsequence/submissions/  
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n1,n2;
int dp[3030][3030];

int lcs(int n1,int n2) // lcs at positions n1 and n2
{
    if(dp[n1][n2] != -1) return dp[n1][n2];

    int ans;
    if(s1[n1-1] == s2[n2-1])
    {
        ans = 1 + lcs(n1-1,n2-1);
    }
    else
    {
        int c1 = lcs(n1-1, n2);
        int c2 = lcs(n1, n2-1);
        ans = max(c1, c2);
    }
    return dp[n1][n2] = ans;
}

string lcs_string(int n1,int n2)
{
    int i = n1, j = n2;
    string ans = "";
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;j--;
        }
        else if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cin>>s1>>s2;
    n1 = s1.size();
    n2 = s2.size();

    memset(dp,-1,sizeof(dp));
    int i,j;
    for(i=0;i<=n1;i++){ dp[i][0] = 0; }
    for(i=0;i<=n2;i++){ dp[0][i] = 0; }

    lcs(n1,n2);
    string ans = lcs_string(n1,n2);
    cout<<ans<<endl;

    return 0;
}
