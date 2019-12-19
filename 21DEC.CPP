//21 DEC
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mxn = 1e3 + 10;
int arr[mxn][mxn];
vector<int>  v[mxn];
int dst[mxn],used[mxn],sum[mxn];
queue<int> q;
int bfs(int src,int dest,int m)
{   int cnt = 0;
    while(!q.empty())q.pop(); memset(dst,0,sizeof(int)*mxn) ; memset(used,0,sizeof(int)*mxn) ;
    q.push(src) ; used[src] = 1 ; dst[src] = 0 ;
    while(!q.empty())
    {
        int pa = q.front() ; q.pop();
        for(int ch : v[pa])
        { if(ch == dest) { dst[ch] = dst[pa]+1; 
        sum[ch] = arr[ch/m][ch%m] + sum[pa]; break;
                        }
          if(used[ch]) { continue; }
            used[ch] = 1;
            q.push(ch);
            dst[ch] = dst[pa] + 1;
        }
    }
    return cnt;
}

int main()
{
int n,m,x,y,z,w,q;
for(int i=0;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
cin>>arr[i][j];
  }
}
for(int i=1;i<n;i++)
{
  for(int j=1;j<m;j++)
  {
x = arr[i][j]; y = arr[i][j-1] ; z = arr[i-1][j];
if(x != '*' && y!= '*') { v[m*i+j].pb(m*i+j-1); v[m*i+j-1].pb(m*i+j);}//left conn
if(x != '*' && z!= '*') { v[m*i+j].pb(m*i+j-n); v[m*i+j-n].pb(m*i+j);}//up connect
  }
}
cin>>x>>y>>q;
while(q--)
{
cin>>z>>w;
}
}
