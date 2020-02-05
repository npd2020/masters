#include <iostream>
#include <math.h>

using namespace std;

int main(){

  double x1, y1, r1, x2, y2, r2;
  double dist, sum_r; //between centers
  int n_cross;

  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  dist = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
  sum_r = r1 + r2;

  //spivp
  if(dist == 0){
      if(r1 == r2) {
      n_cross = -1;
    }
    else if(r1 != r2)
    n_cross = 0;
  }

  else if(dist > sum_r){
    n_cross = 0;
  }
  //1 tochka
  else if(dist == sum_r){
    n_cross = 1;
  }
  
  else if(dist < sum_r){

    double rmin, rmax, dist2line;
    rmin = min(r1, r2);
    rmax = max(r1, r2);
    dist2line = rmax - dist;

    if(rmin > dist2line){
      n_cross = 2;
    }
    else if(rmin == dist2line){
      n_cross = 1;
    }
    else if(rmin < dist2line){
      n_cross = 0;
    }
  }
  else{
    cout << "wtf" << "\n";
  }

  cout << n_cross << "\n";

  return 0;

} // main
