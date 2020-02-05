#include <iostream>
#include <math.h>

using namespace std;

// room size: AxBxC
// f - fly, s - spider     
double A, B, C;
double xf, yf;        //zf == 0 // fly coordinates (is lying on the floor)
double xs, ys, zs;    // spider coordinates
double path;          // spider path

double dist(double x2, double y2){
  return sqrt( (xf-x2)*(xf-x2) +  (yf-y2)*(yf-y2));
}

int main(){

  cin >> A >> B >> C;
  cin >> xf >> yf >> xs >> ys >> zs;

  if(zs == 0.){
    path = dist(xs, ys);
  }
  else{
    
    if(xs == 0.){
      path = dist(-zs, ys);
    }
    else if(ys == 0.){
      path = dist(xs, -zs);
    }
    else if(xs == A){
      path = dist(A+zs, ys);
    }
    else if(ys == B){
      path = dist(B+xs, zs);
    }
  }
  
  cout.precision(2);
  cout << fixed << path;
  return 0;

} // main
