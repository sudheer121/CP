#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mxn = 1e5 + 10;

vector<int>  v[mxn];
int dst[mxn],used[mxn];
queue<int> q;
int bfs(int src,int dist)
{   int cnt = 0;
    while(!q.empty())q.pop(); memset(dst,0,sizeof(int)*mxn) ; memset(used,0,sizeof(int)*mxn) ;
    q.push(src) ; used[src] = 1 ; dst[src] = 0 ;
    while(!q.empty())
    {
        int pa = q.front() ; q.pop();
        for(int ch : v[pa])
        { if(used[ch]) { continue; }
            used[ch] = 1;
            q.push(ch);
            dst[ch] = dst[pa] + 1;
            if(dst[ch] == dist) { cnt++; }
        }
    }
    return cnt;
}

int main()
{ int n,e,m,x,y;
cin>>n>>e;
while(e--)
{
    cin>>x>>y; v[x].pb(y) ;v[y].pb(x) ;
}
cin>>m;
while(m--)
{
    cin>>x>>y;
    cout<<bfs(x,y)<<endl;
}

    return 0;
}
