#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[20][100][100][2];

ll l,r;
int k; 
vector<int> num; 
/*
Here whole vector 'num' represents a number num.(i.e each element of vector is a digit)
Suppose sz is sizeof number num (i.e sizeof vector 'num'). 
Let set S represent all numbers divisible by k with sum of digits divisible by k. 
Let suff(i) be the suffix of num from i to num.size() - 1. (0 base).

dp[i][0][0][0] gives the count of numbers from set S which are in range
(0,suff(i)) 

i represents the msb of the number 
m represents the prefix[0 to i]%k.
s represents the sum[num[0],num[i]]%k.
less = 1, means the number is already less hence we can now join any number from 0 to 9 in prefix. 
*/

ll state(int i, int m, int s,int less) 
{ 
   
    if(i==num.size()) 
    {
        if(m==0 && s==0) { return 1;} 
        return 0; 
    }
    if(dp[i][m][s][less] != -1){ return dp[i][m][s][less]; }

    ll res = 0; 
    int lim = 9; 
    if(less == 0)
    {
        lim = num[i];
    }

    for(int j=0;j<=lim;j++)
    {   
        if(j<lim){
            res += state(i+1, (m*10 + j)%k, (s + j) % k, 1); 
        }
        else {
            res += state(i+1, (m*10 + j)%k, (s + j) % k, less); 
        }
    }
    return dp[i][m][s][less] = res; 
}
ll solve(int x)
{
    memset(dp,-1,sizeof(dp));
    string str = to_string(x); 
    num.clear();
    for(char x:str){ num.push_back(x-'0'); }
    ll ans = state(0,0,0,0);
    return ans; 
}
int main()
{   int t;
    cin>>t;
    int i,j;
    for(i=1;i<=t;i++)
    {
        cin>>l>>r>>k; 
        cout<<"Case "<<i<<": "; 
        if(k>100){ cout<<0<<endl;}
        else cout<<solve(r)-solve(l-1)<<endl;
    }
    return 0; 
}
