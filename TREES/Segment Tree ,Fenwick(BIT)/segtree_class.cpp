//Range sum and updates
struct SegmentTree {
  int n;
  vector<ll> tree; 
  void build(vector<ll> &arr,int si,int ss,int se)
  {
    int mid = (ss + se)/2; 
    if(ss == se) { tree[si] = arr[ss]; return; }
    build(arr,2*si,ss,mid);
    build(arr,2*si+1,mid+1,se); 
    tree[si] = tree[2*si] + tree[2*si+1]; 
  }
  ll query(int si,int ss,int se,int ql,int qr)
  {
    int mid = (ss + se)/2; 
    if(se < ql || ss > qr) { return 0; }
    if(ss >= ql && se <= qr) { return tree[si]; }
    return query(2*si,ss,mid,ql,qr) + query(2*si+1,mid+1,se,ql,qr);
  }
  ll query(int left,int right){ return query(1,0,n-1,left,right); }
  void update(int si,int ss,int se,int i,ll val) //point update
  { int mid = (ss + se)/2; 
    if(i<ss || i>se) { return; }
    if(ss == se) { tree[si] = val; return; }
    update(2*si,ss,mid,i,val);
    update(2*si+1,mid+1,se,i,val);
  }
  void update(int index,ll val){ update(1,0,n-1,index,val); }
  SegmentTree(vector<ll> &arr) //constructor
  { 
    n = arr.size();
    tree.resize(4*(n + 1)) ;  
    build(arr,1,0,n-1); 
  }
  SegmentTree(){}
};

int main()
{ int n; 
  vector<int> v(50);
  for(int i=0;i<n;i++){ cin>>v[i]; } 
  SegmentTree st = SegmentTree(v);
}
