#include <iostream>
#include <cmath>

using namespace std;
  int A, B, C;
  int x_f, y_f;
  int x_s, y_s, z_s;
  double length;
  double distance(double x, double y){
  return sqrt( (x_f - x)*(x_f - x) + (y_f- y)*(y_f- y) ) ;
  }

int main(){

  cin >> A >> B >> C >> x_f >> y_f >> x_s >> y_s >> z_s;

if (z_s ==0){ length = distance(x_s, y_s);}
else{ if(x_s ==0){ length = distance(-z_s, y_s); }
      else if(y_s ==0){ length = distance(x_s, -z_s); }
           else if(x_s == A){ length = distance(z_s+A, y_s); }
                else if(y_s == B){ length = distance(x_s, z_s+B); }
                     else{ cout << "wrong request" << endl; }
}
cout.precision(2);
cout << fixed <<length;
return 0;

}
