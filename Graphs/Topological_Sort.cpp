/*  
THEORY : 
Order of vertices such that for every directed edge u->v in graph, u comes before v in the ordering. 
Works only on DAG -> makes sense 
Algo : You basically do DFS and print the vertices in reverse. This is done by pushing vertices on stack while returning back from a dfs branch ending. 
Then just read the stack upsidedown. 
*/
// ======================================= CP ALGO ==========================================================
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
// ======================================= MY ALGO ==========================================================
int rs[n], vis[n]; // rs -> recursion stack , vis -> visited vertex 
vi g[n]; 
bool f; // f = 1 means cyclic graph 

void dfs(int u) { 
    rs[u] = 1; 
    vis[u] = 1; 
    for(int v:g[u]){ 
        if(rs[v]) { f = 1; return; }
        if(!vis[v]) dfs(v); 
    }
    rs[u] = 0; 
    st.pb(u); 
}
void ts() { 
    int i; 
    fo(i,0,26){ 
        if(!vis[i] && g[i].size()){ 
             dfs(i); 
        } 
    }
}
