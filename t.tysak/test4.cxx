
#include <iostream>
#include <math.h>

using namespace std;
int  m, am;
int n;
int main(){

  cin >> am >> m ;
n = int( - (am + 0.5) + sqrt(am*am - am + 2. * m + 2.25));

cout << fixed <<n;
return 0;

}
