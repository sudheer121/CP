//Extended EUCLID'S algorithm gives gcd in terms of original numbers
#include<bits/stdc++.h>
using namespace std;
int gx,gy,gcd,temp;//x_1 is x1,y_1 is y_1
int GCD(int A, int B) {
    
    if(B==0)
        {   gx=1;gy=0;gcd=A;
            return A;
        }
    else
        {   GCD(B, A % B);
            temp = x_1;
            gx = gy; gx = temp-(A/B)*gy;
            return 0;
        }
}
int main()
{   int x,y;
    cin>>x>>y;
    GCD(x,y);
    cout<<gcd<<"  "<<x_1<<" "<<y_1<<endl;
    return 0;
}
