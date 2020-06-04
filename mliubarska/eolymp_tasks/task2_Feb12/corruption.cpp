#include <iostream>
#include <math.h>

using namespace std;

int n;
double fee; // %

int main(){

  cin >> n >> fee;

  double accounts[n];

  for(int i=0; i<n; i++){
    cin >> accounts[i];
  }

  for(int i=0; i<n; i++){
    cout << accounts[i] << endl;
  }


  
  return 0;
}
