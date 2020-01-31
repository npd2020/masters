#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    double x1, y1, r1, x2, y2, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int state = 0;
    double d = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));

    if(d == 0){
        state = -1;
    }
    else{
        if( (d < r1 + r2) && (d > abs(r1 - r2) ) ){
            state = 2;
        }
        else{
            if((d == r1 + r2) || (d == abs(r1 - r2))){
                state = 1;
            }
            if( (d > r1 + r2) || (d < abs(r1 - r2)) ){
                state = 0;
            }
        }
    }
    cout << state << endl;
}
