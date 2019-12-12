//suffix array
#include <bits/stdc++.h>
using namespace std;
string s;
int suffixarr[100100];//contains 
struct sfx
{
  int idx; int r1; int r2;
};
bool cmp(sfx a,sfx b)
{
  if(a.r1 != b.r1) { return a.r1<b.r1;}
  else return a.r2<b.r2;
}
void sfxarr(string s,int n)
{
sfx arr[n];
for(int i=0;i<n;i++)
{
  arr[i].idx = i;
  arr[i].r1 = s[i]-'a';
  if(i==n-1) { arr[i].r2 = -1;continue;}
  arr[i].r2 = s[i+1] - 'a';
}
sort(arr, arr+n, cmp); 
int ind[n];// idx to position mapping
for(int k=4;k<=2*n;k*=2)
{
int new_rank = 0;
int old_rank = arr[0].r1; 
arr[0].r1 = new_rank;
ind[arr[0].idx] = 0; 
for(int i=1;i<n;i++)//assign r1
{
if(arr[i].r1 == old_rank && arr[i].r2 == arr[i-1].r2)
{
old_rank = arr[i].r1;
arr[i].r1 = new_rank;
} 
else
{
old_rank = arr[i].r1;
arr[i].r1 = ++new_rank;
}
ind[arr[i].idx] = i;
}
for(int i=0;i<n;i++)
{
int next_idx = arr[i].idx + k/2;
if(next_idx >= n) {arr[i].r2 = -1; continue;}
arr[i].r2 = arr[ind[next_idx]].r1;
}
sort(arr, arr+n, cmp); 
}//nlognlogn
for(int i=0;i<n;i++) { suffixarr[i] = arr[i].idx; }
}

int  lcpfunc(int n)
{
int lcp = 0; int x,y,temp;
for(int i=1;i<n;i++)
{ temp = 0;
x = suffixarr[i];
y = suffixarr[i-1];
while(x<n && y<n && s[x]==s[y]) 
{
temp++;x++;y++;
}
if(temp>lcp) { lcp=temp; }
}//for  
return lcp;
}

int main()
{int t;cin>>t;
while(t--)
{ int temp;
cin>>temp>>s;  
sfxarr(s,s.size());
//for(int i=0;i<s.size();i++){ cout<<suffixarr[i]<<" ";}
cout<<lcpfunc(s.size())<<endl;
}
return 0;}

//qn 6
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
const int maxn = 1e5+10;
int t,n,x,y;
int arr[maxn][2];

map<int,int> lrmap,rlmap;
set<int> s;

int main()
{
cin>>t;
while(t--)
{ lrmap.clear();rlmap.clear();s.clear();
cin>>n;
for(int i=0;i<n;i++)
{
cin>>arr[i][0]>>arr[i][1];
}//O(1)
for(int i=0;i<n;i++) {s.insert(arr[i][0]);}//nlogn


}
return 0;}
