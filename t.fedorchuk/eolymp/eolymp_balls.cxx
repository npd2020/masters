#include <iostream>
#include <math.h>

using namespace std;
double logs_array[100000000];

int main(){

    int n = 0;
    cin >> n;

    double logs = 0;
    //double logs_array[n];
    logs_array[0] = 0;
    logs_array[1] = 0;

    for(int i = 2; i < n; i++){
        logs += log(i);
        logs_array[i] = logs;
    }
    double output = 0;
    output += logs_array[n-2] - 2*logs_array[n/2 - 1] + (n - 2)*log(0.5);
    output = 1.0 - exp(output);
    printf("%.8lf\n", output);
    // double output[n];
    // output[0] = 0;
    // output[1] = 0 ;
    // for(int i = 2; i < n; i += 2){
    //     output[i] += logs_array[i-2] - 2*logs_array[i/2 - 1] + (i - 2)*log(0.5);
    // }

}
