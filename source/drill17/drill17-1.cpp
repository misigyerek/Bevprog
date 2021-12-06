#include "std_lib_facilities.h"

void print_array10(ostream& os, int* arr){
	for (int i = 0; i < 10; ++i)
		os <<  i << ". value:" << arr[i] << " address:" << &arr[i] << endl;
}

void print_array(ostream& os, int* arr, int size){
	for (int i = 0; i < size; ++i)
		os <<  i << ". value:" << arr[i] << " address:" << &arr[i] << endl;
}

int* create_array(int size, int starter_value){
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
		arr[i] = starter_value++;
	return arr;
}

vector<int*> create_vector(int size, int starter_value){
	vector<int*> vec;
	for (int i = 0; i < size; ++i)
		vec.push_back(new int{starter_value++});
	return vec;
}

void print_vector(ostream& os, vector<int*> vec){
	for (int i = 0; i < vec.size(); i++)
		os <<  i << ". value:" << *vec[i] << " address:" << vec[i] << endl;
}


int main()
{
	//part 1

	cout << endl << "ten array" << endl;
	int* ten = new int[10];
	for (int i = 0; i < 10; ++i)
		cout << i << ". value:" << ten[i] << " address:" << &ten[i] << endl;
	delete[] ten;
	
	cout << endl << "ten_2 array" << endl;
	int* ten_2 = new int[10];
	for (int i = 0; i < 10; ++i)
		ten_2[i] = 100 + i;
	print_array10(cout, ten_2);
	delete[] ten_2;

	cout << endl << "eleven array" << endl;
	int* eleven = new int[11];
	for (int i = 0; i < 11; ++i)
		eleven[i] = 100 + i;
	print_array(cout, eleven, 11);	
	delete eleven;

	cout << endl << "twenty array" << endl;
	int* twenty = create_array(20, 100);
	print_array(cout, twenty, 20);
	delete twenty;
	
	cout << endl << "ten vector" << endl;
	vector<int*> ten_v = create_vector(10, 100);
	print_vector(cout, ten_v);
	delete ten_v;

	cout << endl << "eleven vector" << endl;
	vector<int*> eleven_v = create_vector(11, 100);
	print_vector(cout, eleven_v);
	delete eleven_v;
	
	cout << endl << "twenty vector" << endl;
	vector<int*> twenty_v = create_vector(20, 100);
	print_vector(cout, twenty_v);
	delete twenty_v;


	return 0; 
}