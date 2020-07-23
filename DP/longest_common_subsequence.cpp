//https://repl.it/@SudheerTripathi/longestcommonsubsequence
#include <bits/stdc++.h>
using namespace std;
string s1,s2; 
int n,m; 

//dp[i][j] = lcs length if first i chars of s1 and
// first j  chars of s2 are considered. 
int dp[100][100];
int lcs()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s1[i-1] ==s2[j-1])
      {
        dp[i][j] = 1 + dp[i-1][j-1]; 
      }
      else 
      {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
      }
    }
  }
  return dp[n][m]; 
}

string lcsprinter()
{ 
  string s = ""; 
  int i = n , j = m; 
  while(i>0 && j>0)
  {
    if(s1[i-1] == s2[j-1])
    {
      s.push_back(s1[i-1]); 
      i--; j--; 
    }
    else if(dp[i-1][j] > dp[i][j-1])
    {
      i--; 
    }
    else
    {
      j--; 
    }
  }
  reverse(s.begin(),s.end());
  return s; 
}
int main()
{
  cin>>s1>>s2; 
  n = s1.size();
  m = s2.size();
  cout<<lcs()<<endl; 
  cout<<lcsprinter()<<endl; 
}
