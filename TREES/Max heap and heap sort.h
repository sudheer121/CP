// MAX HEAP
#include<bits/stdc++.h>
using namespace std;
void max_heapify(int a[],int index,int N)
{   int largest;
    int left = 2*index;
    int right = 2*index+1;
    
    if(left<=N && a[left]>a[index])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }
    if(right<=N && a[right]>a[largest])
    {
        largest = right;
    }
    if(largest != index)
    {
        swap(a[largest],a[index]);
        max_heapify(a,largest,N);
    }
}// Complexity : O(log(N))
void build_maxheap(int a[],int n)
{   
    for(int i=1;i<=n;i++) { cin>>a[i]; }
    for(int i=n/2;i>=1;i--)
    {
        max_heapify(a,i,n);
    }
}
// Complexity : O(N)
// Overall complexity appears : NlogN
// But actually is : O(N) in worst case. Proof :http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf
// Concept : https://www.hackerearth.com/fr/practice/data-structures/trees/heapspriority-queues/tutorial/

void heap_sort(int a[],int n)
{   int heapsize = n;
    build_maxheap(a,n);
    for(int i=n;i>=2;i--)
    {
        swap(a[1],a[i]);
        heapsize = heapsize - 1;
        max_heapify(a,1,heapsize);
    }
}// complexity : O(Nlog(N))

int main()
{ 
int n,a[100];
//cout<<"\nEnter array size\n";cin>>n;
//build_maxheap(a,n);
//for(int i=1;i<=n;i++) { cout<<a[i]<<" "; }
cout<<"\nEnter array size\n";cin>>n;
heap_sort(a,n);
for(int i=1;i<=n;i++) { cout<<a[i]<<" "; }
}

