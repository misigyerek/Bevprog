#include "../std_lib_facilities.h"

int ga[10];

int factorial(int n){
	return n > 1 ? n*(factorial(n-1)) : 1; //recursion
}

void fill_array(int a[], int sz,char c){
	if(c == 'p')
		for (int i = 0; i < sz; ++i)
			a[i] = pow(2,i);
	if(c == 'f')
		for (int i = 1; i < sz+1; ++i)
			a[i-1] = factorial(i);
}

void f(int a[], int sz){
	int la[10];
	for (int i = 0; i < sz; ++i)
		la[i] = a[i];
	for (int i = 0; i < sz; ++i)
		cout << la[i] << ' ';
	cout << endl;
	int* p = new int[sz];
	for (int i = 0; i < sz; ++i)
		p[i] = la[i];
	for (int i = 0; i < sz; ++i)
		cout << p[i] << ' ';
	cout << endl;
	delete[] p;
}

int main()
{
	fill_array(ga, 10, 'p');
	f(ga, 10);
	int a[10];
	fill_array(a, 10, 'f');
	f(a, 10);
	return 0;
}