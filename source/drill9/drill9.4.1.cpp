#include "../std_lib_facilities.h"

struct Date
{
	int y;
	int m;
	int d;
};

void init_date(Date& date, int y, int m, int d){
	if (y < 1900 || y > 2200) cout << "Invalid year.";
	if (m > 12 || m < 1) cout << "Invalid month.";
	if (d > 31 || d < 1) cout << "Invalid day." << endl;
	else date.y = y; date.m = m; date.d = d;
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
	Date today;
	init_date(today, 1978, 6, 25);
	cout << "today: " << today << endl;
	Date tomorrow = today;
	cout << "tomorrow created and today copied into it: " << tomorrow << endl;
	add_day(tomorrow, 1);
	cout << "tomorrow after adding 1 day: " << tomorrow << endl;
	Date nextDate;
	cout << "trying to fill nextDate with invalid data 2004, 13, -5: ";
	init_date(nextDate, 2004, 13, -5);
	return 0;		
}
