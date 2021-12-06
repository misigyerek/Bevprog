#include "std_lib_facilities.h"

struct Point
{
	double x, y;
};

	vector<Point> original_points;
	vector<Point> processed_points;
	ofstream output{"mydata.txt"};
	ifstream input{"mydata.txt"};

ostream& operator<<(ostream& os, vector<Point>& p)
{
 	for (int i = 0; i < p.size(); i++)
		os << p[i].x << "," << p[i].y << endl;
	return os;
}

ifstream& operator>>(ifstream& is, vector<Point>& p)
{
	double x, y;
	char ch;

	for(int i = 0; i < original_points.size(); i++)
	{
		is >> x >> ch >> y;
		p.push_back(Point{x,y});
	}
	return is;
}

int main()
{
	double x, y;
	
	cout << "enter 7 x y pairs:" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cin >> x >> y;
		original_points.push_back(Point{x,y});
	}
	cout << endl << "print original_points and write to mydata.txt:" << endl;
	cout << original_points << endl;
	output << original_points;
	output.close();
	cout << "read mydata.txt and print processed_points:" << endl;
	input >> processed_points;
	cout << processed_points << endl;

	if (original_points.size() != processed_points.size())
		cout << "Something's wrong";
	else{
		for (int i = 0; i < original_points.size(); ++i)
			if (original_points[i].x != processed_points[i].x || original_points[i].y != processed_points[i].y)
				cout << "Something's wrong";
		}

	return 0;
}
