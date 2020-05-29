#include <iostream>
#include <functional>
#include <string>

int main ()
{

  char a = 'a';
  char b = 'a';
  std::string sa = "a";
  std::string sb = "a";
  char nts1[] = "Test";
  char nts2[] = "Test";
  std::string str1 (nts1);
  std::string str2 (nts2);


  std::hash <char> c_hash;
  std::hash<char*> ptr_hash;
  std::hash<std::string> str_hash;
  


  std::cout << "hash value:"<< '\n';
  std::cout << "hash a:"<<  c_hash(a) << '\n';
  std::cout <<  "hash b:"<< c_hash(b) << '\n';
  std::cout << "hash a:"<<  str_hash(sa) << '\n';
  std::cout <<  "hash b:"<< str_hash(sb) << '\n';
  std::cout <<  "hash nts1:"<< ptr_hash(nts1) << '\n';
  std::cout << "hash nts2:"<<  ptr_hash(nts2) << '\n';
  std::cout <<  "hash str1:"<< str_hash(str1) << '\n';
  std::cout <<  "hash str2:"<< str_hash(str2) << '\n';


  std::cout << "same hashes:\n" << std::boolalpha;
  std::cout << "nts1 and nts2: " << (ptr_hash(nts1)==ptr_hash(nts2)) << '\n';
  std::cout << "str1 and str2: " << (str_hash(str1)==str_hash(str2)) << '\n';
  std::cout << "a and b: " << (c_hash(a)== c_hash(b)) << '\n';

  return 0;
}
