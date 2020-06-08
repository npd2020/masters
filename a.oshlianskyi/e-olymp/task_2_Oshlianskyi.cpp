#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1;
    while(true){
        n = int(n/10);
        count += 1;
        if(n < 10)
            break;
    }
    if(n == 0)
        count = 1;
    cout << count << endl;
}
