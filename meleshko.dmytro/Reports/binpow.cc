#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std::chrono;

long long int binpow (int a, int n) {
	if (n == 0)
		return 1;	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		long long int b = binpow (a, n/2);
		return b * b;
	}
}

long long int power (int a, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	else {
		long long int b = power (a, n-1);
		return b * a;
	}
}

int main(){

  int a, n;
	std::cout << '\n' << "===== a^n calculation ===== " << '\n';
	std::cout << "Enter a: " << '\n';
  std::cin >> a;
	std::cout << "Enter n: " << '\n';
  std::cin >> n;

	if (n == 0 && a==0)
		{std::cout << '\n' << "ERROR!!! a=n=0 is forbidden! " << '\n'; return 0;}

	auto start1 = high_resolution_clock::now();
	long long int val1=binpow(a, n);
	for (int i=0; i<1E4; i++)
		val1=binpow(a, n);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	auto start2 = high_resolution_clock::now();
	long long int val2=power(a, n);
	for (int i=0; i<1E4; i++)
		val2=power(a, n);
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);

	std::cout << '\n' << "***** Binary algorythm *****  " << '\n' << "Answer:  " << val1 << '\t' << " Execution time:  " << duration1.count() << " microseconds" << '\n';
	std::cout << '\n' << "***** Standard algorythm *****  " << '\n' << "Answer:  " << val2 << '\t' << " Execution time:  " << duration2.count() << " microseconds" << '\n' << '\n';
}
