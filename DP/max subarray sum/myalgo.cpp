#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inp(a) for(int i=1;i<=n;i++) { cin>>a[i]; }
using namespace std;
#define mod  1e9+7
const int maxn = 1e5 + 100;
int n;
int a[maxn];
int sum=0,maxi=INT_MIN;
int main()
{ 
fastio;
cin>>n;
inp(a);
sum = a[1];maxi = a[1]; 
for(int i=2;i<=n;i++)
{
if( sum<=0 )
{
sum = max(sum,a[i]); maxi = max(maxi,sum);
}
else
{
if(sum + a[i]<=0) { sum = 0; }
else { sum = sum + a[i]; maxi = max(maxi,sum); }
}
}
cout<<maxi<<endl;
return 0;
}
