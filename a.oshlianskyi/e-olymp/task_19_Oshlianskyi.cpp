#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;
    int l = N.length();
    int count = 0;
    if (l%2==1){
        count+=1;}
    for (int i = 0; i<=(l/2-1); i++){
        if (N[i] == N[l-1-i]){count+=1;}
    }
    
    cout<<count;

}
