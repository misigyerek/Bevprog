#include "../std_lib_facilities.h"

class Date
{
private:
	int y, m, d;
public:
	Date(int y, int m, int d);
	void add_day(int n);
	int month() {return m;}
	int day() {return d;}
	int year() {return y;}
};

Date::Date(int y, int m, int d){
	if (y < 1900 || y > 2200) cout << "Invalid year.";
	if (m > 12 || m < 1) cout << "Invalid month.";
	if (d > 31 || d < 1) cout << "Invalid day." << endl;
	else Date::y = y; Date::m = m; Date::d = d;
}

void Date::add_day(int n){
	d += n;
	if (d > 31){
		m++;
		d -= 31;
		if (m > 12){
			y++;
			m -= 12;
		}
	}
}

int main()
{
	Date today(1978, 6, 25);
	cout << "today: " << today.year() << ", " << today.month() << ", " << today.day() <<  endl;
	Date tomorrow(today);
	cout << "tomorrow created and today copied into it: " << tomorrow.year() << ", " << tomorrow.month() << ", " << tomorrow.day() <<  endl;
	tomorrow.add_day(1);
	cout << "tomorrow after adding 1 day: " << tomorrow.year() << ", " << tomorrow.month() << ", " << tomorrow.day() <<  endl;
	cout << "trying to fill nextDate with invalid data 2004, 13, -5: ";
	Date nextDate(1241, 13, -5);
	return 0;
}