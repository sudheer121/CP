const int maxn = 2e5 + 10; 
int vis[maxn], recStack[maxn];
vector<int> g[N];
 
bool isCyclic(int k) //dfs 
{
    if(!visited[k])
    {
        visited[k]=1;
        recStack[k]=1;
        for(auto it:g[k])
        {
            if(!visited[it] && isCyclic(it))
                return true;
            else if(recStack[it])
                return true;
        }
    }
    recStack[k]=false;
    return false;
}
 
bool checkCyclic() // call this function in main() 
{
    memset(visited, 0, sizeof(visited));
    memset(recStack, 0, sizeof(recStack));
    for(int i=1;i<=n;i++) // need to do this for disconnected graphs
    {
        if(isCyclic(i))
            return true;
    }
    return false;
}


//THEORY
/*
Cycle detection in undirected graphs is easy -->  just see if a node has been visited peviously.But this can't be done for DAG because it returns true in case of false cycle
meaning it's closed but not completely cyclic eg: 1->2->3->4, 1->4 

Cycle detection in DAG is done by using a recusion stack, the idea being if a cycle exists, we will encounter the repeated element within the same dfs branch. 
Basically you check if the vertex is in recursion stack. 
*/
