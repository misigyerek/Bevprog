#include "../std_lib_facilities.h"

class Year {
	static constexpr int min = 1900;
	static constexpr int max = 2200;
public:
	class Invalid { };
	Year(int x) : y{x} {if (x<min || max<=x) throw Invalid{};}
	int year() {return y;}
	void incr() {y++;}
private:
	int y;
};

enum class Month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

Month operator++(Month& m){
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

ostream& operator<<(ostream& os, Month m){
	return os << int(m);
}
ostream& operator<<(ostream& os, Year y){
	return os << y.year();
}
Year operator++(Year& y){
	y.incr();
	return y;
}

class Date
{
private:
	Year y;
	Month m;
	int d;
public:
	class Invalid{};
	Date(Year y, Month m, int d): y(y), m(m), d(d) {if(!valid_day()) throw Invalid{};}
	void add_day(int n);
	bool valid_day();
	Month month() { return m; }
	int day() { return d; }
	Year year() { return y; }
};

bool Date::valid_day(){
	if(d > 0 && d <= 31 ) return true;
	else return false;
}

void Date::add_day(int n){
	d += n;
	if(d > 31) {
		++m;
		d-= 31;
	}
	if(m == Month::jan) {
		++y;
	}
}

int main(){
	try{
	Date today {Year{1978}, Month::jun, 25};

	cout << "Today: " << today.year() << ' ' << today.month() << ' ' << today.day() << '\n';

	Date tomorrow = today;

	tomorrow.add_day(1);

	cout << "Tomorrow: " << tomorrow.year() << ' ' << tomorrow.month() << ' ' << tomorrow.day() << '\n';

	Date invalid {Year{1066}, Month::dec, -5};

	return 0;
	}
	catch(Date::Invalid){
		cerr << "Invalid day" << endl;
		return 1;
	}
	catch(exception& e){
		cerr << e.what();
		return 2;
	}
	catch(Year::Invalid){
		cerr << "Invalid year"<< endl;
		return 3;
	}
	catch(...){
		cerr << "Some error" << endl;
		return 4;
	}
}