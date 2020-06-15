#include <iostream> 
using namespace std;
int main() { 
    long long n, m = 5, s = 0; 
    cin >> n; 
    while(n >= m){
        s = s + (n / m); 
        m = m * 5;
    }
    cout << s;
    return 0;
}