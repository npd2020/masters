#include <iostream>
#include <math.h>

using namespace std;

int m, a;
int n;

int main(){

  cin >> a >> m;

  n = int( - (a + 0.5) + sqrt( a*a - a + 2.*m + 2.25 ) );
  
  cout << fixed << n;
  return 0;

} // main
