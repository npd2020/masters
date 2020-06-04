#include <iostream>
#include <math.h>

using namespace std;
// ABC - room size
  double A, B, C;
  double xm, ym;
  double xp, yp, zp;
  double length;
double distance(double x2, double y2){
  return sqrt( (xm - x2)*(xm - x2) + (ym - y2)*(ym - y2)) ;
  }

int main(){

  cin >> A >> B >> C >> xm >> ym >> xp >> yp >> zp;

if (zp ==0.){
  length = distance(xp, yp);
}
else{
  if(xp ==0.){
    length = distance(-zp, yp);
  }
  else if(yp ==0.){
    length = distance(xp, -zp);
  }
  else if(xp == A){
    length = distance(zp+A, yp);
  }
  else if(yp == B){
    length = distance(xp, zp+B);
  }
  else{
    cout << "bad input" << endl;
  }
}
cout.precision(2);
cout << fixed <<length;
return 0;

}
