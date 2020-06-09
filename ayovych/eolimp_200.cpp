#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>


double d(int x1, int y1, int x2, int y2){
	double d;
	d = sqrt((x1-x2)^2+(y1-y2)^2);
	return d;

}
int perpendic(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int a1,a2,b1,b2;
	int w;
	a1 = x2-x1;
	a2 = y2-y1;
	b1 = x4-x3;
	b2 = y4-y3;
	w = a1*b1 + a2*b2;
	return w;

}


int main()
{
  int x1,x2, x3, x4, y1,y2,y3,y4;
  std::cout << "Input x1 y1: " << std::endl;
  std::cin >> x1 >> y1;
  std::cout << "Input x2 y2: " << std::endl;
  std::cin >> x2 >> y2;
  std::cout << "Input x3 y3: " << std::endl;
  std::cin >> x3 >> y3;
  std::cout << "Input x4 y4: " << std::endl;
  std::cin >> x4 >> y4;

  if (d(x1,y1,x2,y2)==d(x3,y3,x4,y4)|| perpendic(x1, y1, x2, y2, x3, y3, x4, y4)==0){
  	std::cout << "YES" << std::endl;
  }
  else{
  std::cout << "NO" << std::endl;
}
}
