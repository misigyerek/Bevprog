#include "std_lib_facilities.h"

void print_array(ostream& os, int* arr, int size){
	for (int i = 0; i < size; ++i)
		os <<  i+1 << ". value:" << arr[i] << " address:" << &arr[i] << endl;
}

	//part 2

int main(int argc, char const *argv[]){
	int i = 7;
	int* p1 = &i;
	cout << "p1 address" << p1 << ", p1 points to value:" << *p1 << endl;

	int a[7];
	for (int i = 0; i < 7; ++i)
		a[i] = pow(2,i);
	int* p2 = a;
	cout << "7 array:" << endl;
	print_array(cout, p2, 7);
	cout << endl;
	int* p3 = p2;
	p2 = p1;
	p2 = p3;
	cout << "p1 address" << p1 << ", p1 points to value:" << *p1 << endl;
	cout << "p2 address" << p1 << ", p2 points to value:" << *p2 << endl;
	cout << "p3 address" << p3 << ", p3 points to value:" << *p3 << endl;
    cout << endl << "7 array:" << endl;
    print_array(cout, p2, 7);
	
	int a2[10];
	for (int i = 0; i < 10; ++i)
		a2[i] = pow(2,i);    
	p1 = a2;
	int a3[10];
	p2 = a3;
    for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];
	cout << endl << "10 array:" << endl;
	print_array(cout, p2, 10);
	
	cout << endl << "10 vector:" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(pow(2, i));
	p1 = &v1[0];
 	print_array(cout, p1, 10);
	vector<int> v2(10);
	p2 = &v2[0];
	for (int i = 0; i < 10; i++)
		p2[i] = p1[i];
	cout << endl << "10 vector:" << endl;
	print_array(cout, p2, 10);
	return 0;
}