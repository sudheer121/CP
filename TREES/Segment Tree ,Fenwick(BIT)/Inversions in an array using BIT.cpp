//Counting number of inversions in an array in nlogn time using bit.
// Best Resource : http://pavelsimo.blogspot.com/2012/09/counting-inversions-in-array-using-BIT.html
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define max 200100
#define el cout<<endl;
int n;
ll a[max];
ll b[max];
ll bit[max] = {0};
// eg. a = [1000,4,5,4]
void update(int idx)
{
    for(int x=idx;x<=n;x+=(x&-x))
    { bit[x]++; }
}

ll query(int idx)
{   ll count=0;
    for(int x=idx;x>0; x -= (x&-x))
    { count += bit[x]; } 
    return count;
}
int main()
{  ll x, inv_count = 0 ;
ios_base::sync_with_stdio(false); cin.tie(NULL);
cin>>n;
for(int i=1;i<=n;i++) { cin>>a[i]; b[i-1]=a[i]; }
sort(b,b+n);//nlongn
for(int i=0;i<n;i++)
{
     int rank = int(lower_bound(b, b + n, a[i+1]) - b); //gives vakues 0 to n-1
     a[i+1] = rank+1; 
}
// If previously a = [1000,4,5,4] .Now a = [3,2,1,2]
//till this point the max value of a[i] will be n if all elements are distinct 
//hence now the values will fit into bit


for(int i=n;i>0;i--) //start reading from end and update the cooresponding element
{   if(a[i]!=1)
    { x = query(a[i]-1); }//gives the number of numbers less than a[i]
    update(a[i]);
    inv_count += x;
}
    cout<<inv_count;
    return 0;
}


