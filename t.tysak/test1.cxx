#include <iostream>

using namespace std;

int main(){
       int n = 0, m = 1;
       cin >> n;

       double n_res;
       n_res = n;
       while(n_res > 10.){
  m += 1;
  n_res = double(n_res)/10.;
       }
       
       cout << m << "\n";
  return 0;

} // main
