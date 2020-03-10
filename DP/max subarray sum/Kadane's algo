//KADANE'S ALGORITHM 
#include<bits/stdc++.h>
using namespace  std;
#define ll long long
const int maxn = 1e5 + 10;
int n,a[maxn];

int kadane(int a[],int n)
{
int maxcurrent,maxglobal;
maxcurrent = maxglobal = a[1];
for(int i=2;i<=n;i++)
{
maxcurrent = max(maxcurrent+a[i],a[i]);
if(maxcurrent>maxglobal) {  maxglobal = maxcurrent; }
}
return maxglobal;
}

int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
  cin>>a[i];
}
cout<<kadane(a,n);
return 0;}
