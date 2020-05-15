// Kadane's algo / Maximum subarray sum.
// Kadane's algo assumes there is at least one positive element in array
/*
This solution requires extra space of O(N)
Let a[] be original array,
Let b[] be an array where b[i] is the maximum sum ending at i.
Let 'ans' store the maximum value calculated on the way. -> max so far.
Let's say I have calculated the answer till b[i-1]

b[i] = max(b[i-1]+a[i],a[i])
Maximum sum ending at index i either continues max sum ending at i-1 or is on its own.
Then ans = max(ans,b[i])

*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n,ans=0;
int a[maxn],b[maxn]; 

int main()
{
cin>>n;
for(int i=0;i<n;i++) { cin>>a[i]; }
b[0] = a[0]; 
for(int i=1;i<n;i++)
{
b[i] = max(b[i-1]+a[i],a[i]); 
ans = max(ans,b[i]);
}
cout<<ans; 
return 0;
}
/*
If u notice closely, we can also solve the answer without considering the extra array b[]
Let's call b[i] as max_ending_here

Consider u are at index i, so max_ending_here has the solution till i-1;
if (max_ending_here + a[i] > max_ending_here):
    max_ending_here = a[i] + max_ending_here
else:
    max_ending_here = a[i] 
ans = max(ans,max_ending_here)

This approach is coded below.
max_current = max_ending_here
*/



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
