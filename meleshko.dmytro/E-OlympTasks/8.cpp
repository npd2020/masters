#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, r, res;
    cin >> n;
    double temp = pow(n, 0.5);
    r=temp/1;
    if((temp-r)!=0)
        r++;

    if(n==1)
        cout << 4;
    if(n==2)
        cout << 7;
    if(n>2){
        int l=n/r;
        res=(4+3*(r-1)+(l-1)*(3+(r-1)*2));
        if((l*r)==n)
            cout << res;
        if((l*r+1)==n)
            cout << res+3;
        if((l*r)!=n && (l*r+1)!=n)
            cout << res+(n-l*r-1)*2+3;
    }
    return 0;
}
