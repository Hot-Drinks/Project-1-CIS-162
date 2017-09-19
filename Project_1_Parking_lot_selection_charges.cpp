/* Name : Keymer Botero , Zailuj Hernandez			*
   Date : September 14th, 2017					*
   Due Date : September 25th, 2017				*
   Program Name : Project 1 - Passaic County			*
   					Parking Authority	*
   Course # : CIS-161-ME1					*
   Program Description : This program allows			*
   					the user to input data  *
   					consisting of vehicle	*
   					type and 4 integers	*
   					representing entering	*
   					and leaving hours and	*
   					minutes in a		*
   					user-friendly manner.	*
*****************************************************************
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//input
char funcSelection(char & a, string & b);
//process
void funcHoursInandOut(int &, int &, int &, int &, int &, int &);
float setRate(const float & a);
//output

int main()
{
char select;	
string vehicleType;
int hourIn, minuteIn, hourOut, minuteOut, hourDifference, minuteDifference;
funcSelection(select, vehicleType);
funcHoursInandOut(hourIn, minuteIn, hourOut, minuteOut, hourDifference, minuteDifference);
return 0;	
}

char funcSelection(char & select, string & vehicleType)
{
char input;	
cout << "Please Enter Your Vehicle Type: " << endl;
cin >> input;
select= toupper(input);

while ((select!='C') && (select!='V') && (select!='S') && (select!='B') && (select!='T'))
{
cout << "Invalid input; Please try entering the information once more." << endl;
funcSelection(select, vehicleType);
}

switch(select)
{
case 'C':
{vehicleType="Car";
break;
}
case 'V':
{vehicleType="Van";
break;
}
case 'S':
{vehicleType="SUV";
break;
}

case 'B':
{vehicleType="Bus";
break;
}

// makes the destinction between a large truck or small truck
case 'T':
{char size, sizef;
cout << "Small or Large? ";
cin >> size;
sizef= toupper(size);
	while ((sizef!= 'S') && (sizef!='L')) 
	{cout << "Invalid input; Please re-enter the value." << endl;
	cout << "Small or Large? ";
	cin >> size;
	sizef= toupper(size);	
	}
		switch (sizef)
		{
		case 'S':
		{
		vehicleType= "Small Truck";
		break;
		}
		case 'L': 
		{
		vehicleType= "Large Truck";	
		break;
		}
		}
}
}
cout << "You entered: " << select << endl;
cout << "Vehicle: " << vehicleType << endl;
return select;
}

void funcHoursInandOut(int & hourIn, int & minuteIn, int & hourOut, int & minuteOut, int & hourDifference, int & minuteDifference)
{
cout << "Please enter your time of arrival, beginning with the hour value (06-24) and then minutes (0-59)" << endl;
cout << "Time of Arrival: ";
cin >> hourIn;
	while ((hourIn > 0) && (hourIn < 6) && (hourIn > 24))
	{cout << "Invalid values. Please enter the values again.";
	cout << "Time of Arrival: ";
	cin >> hourIn;	
	}
cin >> minuteIn;	
	while ((minuteIn < 0) && (minuteIn > 60))
	{cout << "Invalid values. Please enter the values again.";
	cout << "Time of Arrival: ";
	cin >> minuteIn;
	}

cout <<	"Please enter your time of departure, beginning with the hour value (06-24) and then minutes (0-59)" << endl;
cout << "Time of Departure: ";
cin >> hourOut;
	while ((hourOut > 0) && (hourOut < 6) && (hourOut > 24))
	{cout << "Invalid values. Please enter the values again.";
	cin >> hourOut;
	}
cin >> minuteOut;	
	while ((minuteOut < 0) && (minuteOut > 60))
	{cout << "Invalid values. Please enter the minute values again.";
	cin >> minuteOut;	
	}
	
hourDifference= hourOut-hourIn;
if ((hourDifference > 3) && (minuteOut > 1))
{hourDifference++;}

minuteDifference= minuteOut-minuteIn;

cout << "Time Elapsed: " << hourDifference << " hours" << endl;	
}
