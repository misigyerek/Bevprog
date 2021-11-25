#include "std_lib_facilities.h"

void swap_v(int a,int b){ // works with a copy of the original variables only, will not change original variable values
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "in swap_v: a: " << a << " " << "b: " << b << endl;
}

void swap_r(int& a,int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "in swap_r: a: " << a << " " << "b: " << b << endl;
}

/*
won't compile, cannot change read only reference 

void swap_cr(const int& a, const int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/ 

int main()
{
	int x = 7, y = 9;
	cout << "Original int x: " << x << " " << " y: " << y << endl << "----------------" << endl;
	cout << "swap_r(x,y)" << endl;
	swap_r(x,y);
	cout << "in main: x: " << x << " " << "y: " << y << endl << "----------------" << endl; // swap OK in method and main, ref. passed
	x = 7, y = 9;
	cout << "swap_v(x,y)" << endl;
	swap_v(x,y);
	cout << "in main: x: " << x << " " << "y: " << y << endl << "----------------" << endl; // swap OK in method, swap NOK in main, value not passed
	cout << "swap_v(7,9)" << endl;
	swap_v(7,9); //still swaps inside method at least
	//swap_r(7,9); won't compile, expects ref.
	cout << endl;

	const int cx = 7, cy = 9;
	cout << endl <<"Original const int cx: " << cx << " " << " cy: " << cy << endl << "----------------" << endl;
	swap_v(cx, cy); 
	cout << "in main: cx: " << cx << " " << "cy: " << cy << endl << "----------------" << endl; //swap OK in method, swap NOK in main, value not passed
	//swap_r(cx, cy); won't compile, const cannot be modified
	cout << "swap_v(7.7,9.9)" << endl;
	swap_v(7.7,9.9); //still swaps inside method at least, decimals cut off
	//swap_r(7.7,9.9); won't compile, method expects var ref.
	cout << endl;

	double dx = 7.7, dy = 9.9;
	cout << endl << "Original double dx: " << dx << " " << " dy: " << dy << endl << "----------------" << endl;
	swap_v(dx,dy);
	cout << "in main: dx: " << dx << " " << "dy: " << y << endl << "----------------" << endl; // swap OK in method but decimals cut off (converted to int), swap NOK in main, value not passed
	//swap_r(dx,dy); wont compile, expects int ref
	//swap_r(7.7,9.9); won't compile, method expects var ref.

	return 0;
}