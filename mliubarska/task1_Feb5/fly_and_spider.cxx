#include <iostream>
#include <math.h>

using namespace std;

// room size: AxBxC
// f - fly, s - spider     
double A, B, C;
double xf, yf;        //zf == 0 // fly coordinates (is lying on the floor)
double xs, ys, zs;    // spider coordinates
double path;          // spider path

double dist(double x1, double y1, double x2, double y2){
  return sqrt( (x1-x2)*(x1-x2) +  (y1-y2)*(y1-y2));
}

int main(){

  cin >> A >> B >> C;
  cin >> xf >> yf >> xs >> ys >> zs;

  if(zs == 0.){
    path = dist(xf, yf, xs, ys);
  }
  else{

    if( (xf==0 && xs==0)){
      path = dist(0., yf, zs, ys);
    } 
    else if(yf==0 && ys==0){
      path = dist(xf, 0., xs, zs);
    }
    else if(xf==A && xs==A){
      path = dist(0., yf, zs, ys);
    }
    else if(yf==B && ys==B){
      path = dist(xf, 0., xs, zs);
    }
    else if(xs == 0.){
      path = dist(xf, yf, -zs, ys);
    }
    else if(ys == 0.){
      path = dist(xf, yf, xs, -zs);
    }
    else if(xs == A){
      path = dist(xf, yf, A+zs, ys);
    }
    else if(ys == B){
      path = dist(xf, yf, xs, zs+B);
    }
  }
  
  cout.precision(2);
  cout << fixed << path;
  return 0;

} // main
