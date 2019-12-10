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
