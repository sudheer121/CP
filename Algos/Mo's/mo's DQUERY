#include<bits/stdc++.h>
#define p push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int maxn = 500000;
const int maxq = 5000000;
int a[maxn],n,qr,blk,answer=0;
int freq[maxq]={0};
int ans[maxq];
struct query{
int l,r,i;
} q[maxq];

bool cmp(query x,query y)
{
if(x.l/blk != y.l/blk)
{
  return x.l/blk < y.l/blk;
  //if lie in different block then laft block first
}
return x.r < y.r ;//same block then r in increasing order
}

void add(int index)
{
freq[a[index]]++;
if(freq[a[index]]==1)
{
  answer++;
}
}
void remove(int index)
{
freq[a[index]]--;
if(freq[a[index]] == 0)
{
	answer--;
}
}

int main()
{ 
fastio;
int x,y;
query k;
cin>>n;
for(int i=0;i<n;i++)
{
 cin>>a[i];
}

cin>>qr;
blk = (int)sqrt(n+.0) + 1;//block size

for(int i=0;i<qr;i++)
{
cin>>q[i].l>>q[i].r;
q[i].l--;q[i].r--;
q[i].i = i;
}
sort(q,q+qr,cmp);
int curl=0,curr =-1; //current l and r(the 2 moving pointers)
//curr is -1 because if it is 0 then it means I am including 
// it in array;
for(int i=0;i<qr;i++)
{
  int l = q[i].l;
  int r = q[i].r;
  while(curl<l)
  {
    remove(curl);
    curl++;
  }
  while(curl>l)
  {
    add(curl-1);
    curl--;
  }
  while(curr>r)
  {
    remove(curr);
    curr--;
  }
  while(curr<r)
  {
    curr++;
    add(curr);
  }
  ans[q[i].i] = answer;
}
for(int i=0;i<qr;i++)
{
  cout<<ans[i]<<"\n";
}
return 0; 
}
