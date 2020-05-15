// Kadane's algo / Maximum subarray sum.
// Kadane's algo assumes there is at least one positive element in array
/*
This solution requires extra space of O(N)
Let a[] be original array,
Let b[] be an array where b[i] is the maximum sum ending at i.
Let 'ans' store the maximum value calculated on the way. -> max so far.
Let's say I have calculated the answer till b[i-1]

We can say,
if(a[i] > b[i-1] + a[i]):
    b[i] = a[i]
else 
    b[i] = b[i-1] + a[i]
    
In short, b[i] = max(b[i-1]+a[i],a[i])
Maximum sum ending at index i either continues max sum ending at i-1 or is on its own.
Then ans = max(ans,b[i])

*/
void soln1(int a[],int n)
{
int ans=0;
int b[maxn];     
b[0] = a[0]; 
for(int i=1;i<n;i++)
{
b[i] = max(b[i-1]+a[i],a[i]); 
ans = max(ans,b[i]);
}
return ans;     
}

/*
We don't need array b[] because at any point we only need b[i-1].
Let's store b[i-1] in max_ending_here and update it in every iteration. 

Consider u are at index i, so max_ending_here has the solution till i-1;
if (a[i] > max_ending_here + a[i]):
    max_ending_here = a[i] 
else:
    max_ending_here = a[i] + max_ending_here

Inshort, max_ending_here = max(a[i], max_ending_here + a[i]);
ans = max(ans,max_ending_here)

*/

int soln2(int a[],int n)
{
// Here, ans is maxglobal and max_ending_here is maxcurrent
int maxcurrent,maxglobal;
maxcurrent = maxglobal = a[0];
for(int i=1;i<n;i++)
{
maxcurrent = max(maxcurrent+a[i],a[i]);
if(maxcurrent>maxglobal) {  maxglobal = maxcurrent; }
}
return maxglobal;
}

