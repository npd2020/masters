#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long int n, r, res;
    cin >> n;
    long double temp = pow(n, 1.0/3);
    r=temp/1;
    if((temp-r)!=0)
        r++;

    if(n==1)
        cout << 12;
    if(n==2)
        cout << 18;
    if(n>2 && n<=(r*r)){
        long int l=n/r;
        res=(12+8*(r-1)+(l-1)*(8+(r-1)*5));
        if((l*r)==n)
            cout << res;
        if((l*r+1)==n)
            cout << res+8;
        if((l*r)!=n && (l*r+1)!=n)
            cout << res+(n-l*r-1)*5+8;
    }
    if(n>(r*r) && n<(r*r*r)){
        long int h=n/(r*r);
        res=((12+8*(r-1)+(r-1)*(8+(r-1)*5))+((r+1)*(r+1)+(r+1)*r*2)*(h-1));
        if((r*r*h)==n)
            cout << res;
        if((r*r*h+1)==n)
            cout << res+8;
        if((n-r*r*h)>1 && (n-r*r*h)<=r)
            cout << res+(n-r*r*h-1)*5+8;
        if((n-r*r*h)>r){
            int m=n-r*r*h;
            if(((n-r*r*h)%r)==0){
                cout << res;+(r-1)*5+8+((r-1)*3+5)*((n-r*r*h)/r-1);
                cout << "\n" << (r-1)*5+8;}
            if(((n-r*r*h)%r)!=0){
                cout << res+(r-1)*5+8+((r-1)*3+5)*((n-r*r*h)/r-1)+((n-r*r*h)%r-1)*3+5;
            }
        }

    }

    if(n==pow(r, 3))
        cout << pow((r+1), 2)*r*3;
    return 0;
}
