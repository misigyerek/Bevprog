#include "../std_lib_facilities.h"

struct Date
{
	int y;
	int m;
	int d;
	Date(int y, int m, int d);
	void add_day(int n);
};

	Date::Date(int year, int month, int day)
{
	if (year < 1900 || year > 2200) cout << "Invalid year.";
	if (month > 12 || month < 1) cout << "Invalid month.";
	if (day > 31 || day < 1) cout << "Invalid day." << endl;
	else y = year; m = month; d = day;
}

void add_day(Date& date, int n){
	date.d += n;
	if (date.d > 31){
		date.m++;
		date.d -= 31;
		if (date.m > 12){
			date.y++;
			date.m -= 12;
		}
	}
}

ostream& operator<<(ostream& os, const Date& date)
{
	return os << date.y << "," << date.m << "," << date.d;
}

int main()
{
	Date today(1978, 6, 25);
	cout << "today: " << today << endl;
	Date tomorrow(today);
	cout << "tomorrow created and today copied into it: " << tomorrow << endl;
	add_day(tomorrow, 1);
	cout << "tomorrow after adding 1 day: " << tomorrow << endl;
	cout << "trying to fill nextDate with invalid data 2004, 13, -5: ";
	Date nextDate(1241, 13, -5);
	return 0;		
}
