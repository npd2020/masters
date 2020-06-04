#include <iostream>
using namespace std;

//бінарний алгоритм розрахунку НСК
int NSK(int A, int B)
{
int k=1;
while ((A!=0) && (B!=0))
{
while ((A%2==0) && (B%2==0))
{
A/=2;
B/=2;
k*=2;
}
while (A%2==0) A/=2;
while (B%2==0) B/=2;
if (A>=B) A-=B; else B-=A;
}
return B*k;
}

//головна функція
int main() {
int A, B;
cout<<"A > "; cin>>A;
cout<<"B > "; cin>>B;
cout<<"НСД("<<A<<", "<<B<<")="<<NSK(A, B)<< endl;
return 0;
}
