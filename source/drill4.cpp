#include "std_lib_facilities.h"

int main()
{
	vector<double> numbers;
	vector<string> units = {"m", "cm", "in", "ft"};
	double number, largest, smallest;
	string unit;
	cout << "provide a number and a unit of measurement (cm, m, in, ft):";
	while (cin >> number >> unit){
		bool unitCheck = false;
		for (int i = 0; i < units.size(); ++i)
		{
			if (unit == units[i])
			{
				unitCheck = true;
			}
		}
		if (!unitCheck)
			cout<<"invalid unit";
		else
		{
			if(unit == "in")
					number = number * 0.0254;
			if(unit == "ft")
					number = number * 0.3048;
			if(unit == "cm")
					number = number * 0.01;
			numbers.push_back(number);
			smallest = *std::min_element(numbers.begin(),numbers.end());
			largest = *std::max_element(numbers.begin(),numbers.end());
			cout << "value entered: " << number << "m";
			if (numbers.size() > 1)
			{
				if (number == largest)
					cout << " largest so far \n";
				if (number == smallest)
					cout << " smallest so far \n";
			}
		}
	}
	sort(numbers.begin(),numbers.end());
	double sum;
	cout << "sorted list:\n";
	for (int i = 0; i < numbers.size(); ++i)
	{
		sum += numbers[i];
		cout << numbers[i] << ", ";
	}
	cout << "\n";
	cout << "sum:"<<sum<<"m" << "\n" << "max:"<<largest<< "m"<<"\n" << "min:"<< smallest << "m"<<"\n";
	return 0;
}