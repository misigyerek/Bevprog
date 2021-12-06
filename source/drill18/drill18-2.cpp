#include "../std_lib_facilities.h"

vector<int> gv;

int factorial(int n){
	return n > 1 ? n*(factorial(n-1)) : 1; //recursion
}

void fill_vector(vector<int>& v, int sz,  char c){
	if(c == 'p')
		for (int i = 0; i < sz; ++i)
			v.push_back(pow(2,i));
	if(c == 'f')
		for (int i = 1; i < sz+1; ++i)
			v.push_back(factorial(i));
	
}

void f(vector<int> v){
	vector<int> lv;
	lv.assign(v.begin(), v.end());
	for (int i = 0; i < lv.size(); ++i)
		cout << lv[i] << ' ';
	cout << endl;
	vector<int> lv2;
	lv2.assign(v.begin(), v.end());
	for (int i = 0; i < lv.size(); ++i)
		cout << lv[i] << ' ';
	cout << endl;
}

int main()
{
	fill_vector(gv, 10, 'p');
	f(gv);
	vector<int> vv;
	fill_vector(vv, 10, 'f');
	f(vv);
	return 0;
}