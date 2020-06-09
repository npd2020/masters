#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <vector>

int main()
{
  int t1,t2;
  int h1;
  int h2;
  int m1;
  int m2;
  int s1;
  int s2;
  int h, m,s;
  int diff;
  std::cout << "Input time1: " << std::endl;
  std::cin >> h1 >> m1 >> s1;
  std::cout << "Input time2>time1: " << std::endl;
  std::cin >> h2 >> m2 >> s2;
  if (h1 > 24 || h2 > 24){
  	std::cout << "Please input correct time format!" << std::endl;
  }
  if (m1 > 60 || m2 > 60 || s1 > 60 || s2>60){
  	std::cout << "Please input correct time format!" << std::endl;
  }
  else{
  //std::cout << h1 << std::endl;
  diff = (3600*h2+m2*60+s2)-(3600*h1+m1*60+s1);
  h = diff/3600;
  m= (diff - h*3600)/60;
  s = diff - h*3600 - m*60;
  std::cout << "Time difference: "<< h <<"h"<< m <<"m"<<s <<"s"<<"\n"<< std::endl;
}
}
