#include <iostream>

using namespace std;

//алгоритм Евкліда - віднімання
int NOD(int A, int B)
{
while (A!=B)
if (A>B) A-=B;
else B-=A;
return A;
}

//головна функція
int main (){
int A, B;
cout<<"A > "; cin>>A;
cout<<"B > "; cin>>B;
cout<<"НCД("<<A<<", "<<B<<")="<<NOD(A, B) << endl;
return 0;
}
