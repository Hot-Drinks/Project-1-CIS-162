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
string funcSelection(char a, string & b, char s);

//process
void funcHoursInandOut(int &, int &, int &, int &, int &, int &, int &, int &);
float getRate(string vehicleType, int hourDifference, int estimatedHour, float & firstRate, float & secondRate);

//output
void print(string vehicleType, int hourIn, int minuteIn, int hourOut, int minuteOut, int estimatedHour, int estimatedMinute, 
int hourDifference, int minuteDifference, float & firstRate, float & secondRate, float totalRate);
/*
class car
{
    private:
        char select;
        int hourin, minutein, hourout, minuteout, hourDifference,
				 minuteDifference, estimatedHour, estimatedMinute;
        
        const float getfirstrate();
        const float getsecondrate();
        
        
    public:
        ~car(){}
        car();
        void setrate();
        void print() const;
};
class Bus
{
    private:
        char select;
        int hourin, minutein, hourout, minuteout, hourDifference,
				 minuteDifference, estimatedHour, estimatedMinute;
        
        const float getfirstrate();
        const float getsecondrate();
        
        
    public:
        ~bus(){}
        bus();
        void setrate();
        void print() const;
};
*/



int main()
{
	char select, sizef;	
	string vehicleType;
	int hourIn, minuteIn, hourOut, minuteOut, hourDifference,
		 minuteDifference, estimatedHour, estimatedMinute;
	float totalRate, firstRate, secondRate;

funcSelection(select, vehicleType, sizef);
funcHoursInandOut(hourIn, minuteIn, hourOut, minuteOut, hourDifference, minuteDifference,estimatedHour,estimatedMinute);
if ((select='C') || (select='V') || (select='S'))
{
print(vehicleType, hourIn, minuteIn, hourOut, minuteOut, estimatedHour, estimatedMinute, 
	hourDifference, minuteDifference, firstRate, secondRate, totalRate);
}
	else
	{	
	if ((select='B') || (select='T') && (sizef='S'))
	{
	print(vehicleType, hourIn, minuteIn, hourOut, minuteOut, estimatedHour, estimatedMinute, 
	hourDifference, minuteDifference, firstRate, secondRate, totalRate);
	}
	}
return 0;	
}
/*This function will allow the user to enter a selection for their vehicle type through a menu.
In addition, if 'Truck' is selected in menu, the program will ask an additional question to clarify 
on the size of the truck. However, the program will only accept characters that are 'C','V','S','B', or 'T'
and if the user is being asked about their truck's size, characters 'S' and 'L' are only accepted.
Once the selection is fully confirmed, it will return the character value 'select' later on.
*/
string funcSelection(char select, string & vehicleType, char sizef)
{
char input;	
cout << "Welcome to the Passaic County Parking Authority.\n\nPlease select the vehicle that you have parked here by entering the corresponding letter for your selection.";
cout << "\n\n\t1.	C = Car\n\t2.	V = Van\n\t3.	S = SUV\n\t4.	B = Bus\n\t5.	T = Truck" <<endl; 
cout << "\nPlease Enter Your Vehicle Type: "; cin >> input;
select= toupper(input);

while ((select!='C') && (select!='V') && (select!='S') && (select!='B') && (select!='T'))
{
cout << "Invalid input; Please try entering the information once more." << endl;
funcSelection(select, vehicleType, sizef);
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
cout << "S = Small or L = Large? ";
cin >> size;
sizef= toupper(size);
	while ((sizef!= 'S') && (sizef!='L')) 
	{cout << "Invalid input; Please re-enter the value." << endl;
	cout << "S = Small or L = Large? ";
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
return vehicleType;
}

/*
 In this function, the user will asked when they have entered the parking lot
 and when they have left by reading the variables inputted only by the user. It will
 then calculate the hours and minutes given and print the time that has passed.
 The function will not accept characters, irrational numbers, or values between 0 and 6 and over 24.
 The variables in this function will be passed by reference later for our output. 
*/
void funcHoursInandOut(int & hourIn, int & minuteIn, int & hourOut, int & minuteOut, int & hourDifference, int & minuteDifference, 
int & estimatedHour, int & estimatedMinute)
{
cout << "\nPlease enter your time of arrival, beginning with the hour value (06-24) and then minutes (0-59)" << endl;
cout << "Hour of Arrival : "; cin >> hourIn;
	while ((hourIn > 0) && (hourIn < 6) && (hourIn > 24))
	{cout << "Invalid values. Please enter the values again.";
	cout << "Hour of Arrival: ";
	cin >> hourIn;	
	}
cout << "Minute of Arrival : ";
cin >> minuteIn;	
	while ((minuteIn < 0) && (minuteIn > 60))
	{cout << "Invalid values. Please enter the values again.";
	cout << "Minute of Arrival: ";
	cin >> minuteIn;
	}

cout <<	"Please enter your time of departure, beginning with the hour value (06-24) and then minutes (0-59)" << endl;
cout << "Hour of Departure : "; cin >> hourOut;
	while ((hourOut > 0) && (hourOut < 6) && (hourOut > 24))
	{cout << "Invalid values. Please enter the hour values again.";
	cin >> hourOut;
	}
cout << "\nMinute of Departure : "; cin >> minuteOut;	
	while ((minuteOut < 0) && (minuteOut > 60))
	{cout << "Invalid values. Please enter the minute values again.";
	cin >> minuteOut;	
	}
	
hourDifference= hourOut-hourIn;
if (minuteOut > 1)
estimatedHour = hourDifference+1;

minuteDifference= minuteOut-minuteIn;
if(minuteDifference < 0)
((minuteDifference *= -1) && (hourDifference-1) && (estimatedMinute = minuteDifference*0));

cout << "Time Elapsed: " << hourDifference << " hours and " << minuteDifference << " minutes";
	
}

//for calculating the rates of all vehicles
float getRate(string vehicleType, int hourDifference, int estimatedHour, float & firstRate, float & secondRate)
{
while ((vehicleType=="Car") || (vehicleType=="Van") || (vehicleType=="SUV"))
{
firstRate=0.00;
secondRate=1.50;

if (hourDifference <=3)
	{cout << "\n" << firstRate << endl;
	return firstRate;	
	}
	else
	{
	float totalRate= (secondRate * (estimatedHour - 3));
	return totalRate;
	cout << "/n" << totalRate << endl;
	}
}

while ((vehicleType=="Bus") || (vehicleType=="Small Truck"))
{
firstRate=1.00;
secondRate=2.50;

if (hourDifference <=2)
	{cout << "\n" << firstRate << endl;
	return firstRate;	
	}
	else
	{
	float totalRate= (firstRate+(secondRate * (estimatedHour-2)));
	return totalRate;
	cout << "/n" << totalRate << endl;
}

while (vehicleType=="Large Truck")
{
firstRate=2.00;
secondRate=3.50;
if (hourDifference <=1)
	{cout << "\n" << firstRate << endl;
	return firstRate;	
	}
	else
	{
	float totalRate= (firstRate + (secondRate * (estimatedHour-1)));
	return totalRate;
	cout << "/n" << totalRate << endl;
}

}
}
}


// used to print output for vehicles and calculate the final rate
void print(string vehicleType, int hourIn, int minuteIn, int hourOut, int minuteOut, int estimatedHour, int estimatedMinute, 
int hourDifference, int minuteDifference, float & firstRate, float & secondRate, float totalRate)
{	
cout << "\n Type of Vehicle: " << vehicleType << endl;
cout << "Time In: " << hourIn << ":" << minuteIn << endl;
cout << "Time Out: " << hourOut << ":" << minuteOut << endl;
cout << "Parking-Time " << hourDifference << ":" << minuteDifference << endl;
cout << "Rounded Time: " << estimatedHour << " hours" << endl;
totalRate=getRate(vehicleType, hourDifference, estimatedHour, firstRate, secondRate);
cout << "TOTAL DUE: " << "$" << totalRate << endl;
}
