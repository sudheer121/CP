void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {   // O(logN) average 
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int find_set_naive (int v) {  // O(N) 
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
