#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n = 0;
    cin >> n;

    if( n == 1 ){
        cout << 3 << endl;
    }
    else{
        cout << long(3*pow(2, n-1) ) << endl;
    }
}
