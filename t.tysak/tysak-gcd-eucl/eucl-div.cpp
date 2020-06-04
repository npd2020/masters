#include <iostream>

using namespace std;

//алгоритм Евкліда - ділення
int NOD(int A, int B)
{
while (A!=0 && B!=0)
if (A>B) A%=B; else B%=A;
return A+B;
}

//головна функція
int main (){
int A, B;
cout<<"A > "; cin>>A;
cout<<"B > "; cin>>B;
cout<<"НСД("<<A<<", "<<B<<")="<<NOD(A, B) << endl;
return 0;
}
