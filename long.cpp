//prob 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int a[9]; 
int main() {
int t,n,x,y; ll sum;
cin>>t;
while(t--)
{
cin>>n;sum=0;
memset(a,0,9*sizeof(int));
while(n--)
{
  cin>>x>>y;
  if(x<9 && y>a[x]) { a[x]= y; }
}
for(int i=1;i<9;i++) { sum+=a[i]; }
cout<<sum<<endl;
}
return 0;
}
//prob2
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int t,n,a[3];
ll x,ans;
int main()
{
cin>>t;
while(t--)
{
cin>>n;a[0]=0;a[2]=0;ans=0;
for(int i=0;i<n;i++)
{
  cin>>x;
  if(x==0) { a[0]++; }
  if(x==2) { a[2]++; }
}  
ans = (a[0]*(a[0]-1))/2 + (a[2]*(a[2]-1))/2;
cout<<ans<<endl;
}  
  return 0;
}
