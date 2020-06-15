#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
    int n, k = 0;
    cin >> n;     cin.ignore(); 
    const int N = 2 * n + 1;
    char c[N];
    for(int i = 0; i < n; i++) {
        fgets(c, N, stdin); 
        for(int j = 0; j < i; j++) 
            k = k + c[j << 1] - 48; //переведення з ascii кода в число
    }
    cout << k;
 
    return 0;
}