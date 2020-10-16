//https://cp-algorithms.com/graph/lca_binary_lifting.html

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
/*
===============================================================================================================================================================================
Explanation of for loop inside lca() function.
We start climbing up from one side of 2(u,v) vertices,eg:u until  we reach the lca.
Imagine the distance of u from lca is a number x, if x=13 then x in binary is 1101. 
If n = 64, l = 6.
Hence first we climb 2^6. 
Check if 64th parent of u is not ancestor of v. Keep checking 32nd parent , 16th parent,8th parent of u and so on. 
According to example 8th parent is not ancestor, so climb to the 8th parent. Then 4th parent from here is not an ancestor so climb to 4th parent.
Now, 2nd parent from here is an ancestor,so skip. Now 1 parent above is a also lca , so skip. Loop ends here.Now just climb 1 parent and you get lca. 
Basically we made use of binary representation of 13. We climbed accordingly from MSB to LSB.We climbed if MSB was one, and didn't if it was zero. 


*/
