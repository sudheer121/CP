const int mod  = 1e9+7;
const int maxn = 100;
int a[maxn][maxn]; 
int vis[maxn][maxn]; 

int n,m; 
int val(int i,int j){
    if(i==0 || j==0 || i==n+1 || j==m+1) return -1;
    return a[i][j];
}
int dx[] = {0,1,0,-1}; 
int dy[] = {1,0,-1,0};  
void dfs(int x,int y,int px,int py){ 
    
    vis[x][y] = 1;
    int i,j; 
    fo(i,0,4){ 
        if(x+dx[i]==px && y+dy[i]==py) continue; 
        if(val(x+dx[i],y+dy[i])==a[x][y]){ 
            if(vis[x+dx[i]][y+dy[i]]) { 
                cout<<"Yes\n";
                exit(0); 
            }
            dfs(x+dx[i],y+dy[i],x,y); 
        }
    }
}
int main()
{
io(); 
int i,j;
cin>>n>>m;
fo(i,1,n+1) { 
    string s; 
    cin>>s; 
    fo(j,0,m){ 
        a[i][j+1] = s[j]-'A'; 
    }
} 

fo(i,1,n+1) { 
    fo(j,0,m){ 
        if(!vis[i][j+1]){ 
            dfs(i,j+1,-1,-1); 
        } 
    }
} 
cout<<"No"; exit(0); 
return 0;
}
