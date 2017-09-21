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
string Selection(char a, string & b, char s);

//process
void HoursInandOut(int &, int &, int &, int &, int &, int &, int &, string &, string &);
float getRate(string, int &, int, int, 
				int, float, float);

//output
void print(string, int, int &,string &, int, int&, string &, int, 
int, int, float, char);

int main()
{
	char select, sizef, restart;	
	string vehicleType, ampmDesignator_in, ampmDesignator_out;
	int hourIn, minuteIn, hourOut, minuteOut, hourDifference,
		 minuteDifference, estimatedHour,
		 	cutoff, est_Time;
	float totalRate, firstRate, secondRate;

Selection(select, vehicleType, sizef); //Zailuj's Function 
HoursInandOut(hourIn, minuteIn, hourOut, minuteOut, hourDifference, minuteDifference,estimatedHour, ampmDesignator_in, ampmDesignator_out); //Keymer's Function
totalRate = getRate(vehicleType, hourDifference, estimatedHour,cutoff, est_Time, firstRate, secondRate); // Keymer and Zailuj's function
print(vehicleType, hourIn, minuteIn,ampmDesignator_in, hourOut, minuteOut, ampmDesignator_out, estimatedHour, 
hourDifference, minuteDifference, totalRate, restart); //Keymer and Zailuj's function


return 0;	
}
/*This function will allow the user to enter a selection for their vehicle type through a menu.
In addition, if 'Truck' is selected in menu, the program will ask an additional question to clarify 
on the size of the truck. However, the program will only accept characters that are 'C','V','S','B', or 'T'
and if the user is being asked about their truck's size, characters 'S' and 'L' are only accepted.
Once the selection is fully confirmed, it will return the character value 'select' later on.
*/
string Selection(char select, string & vehicleType, char sizef)
{
char input;	
cout << "Welcome to the Passaic County Parking Authority.\n\nPlease select the vehicle that you have parked here by entering the corresponding letter for your selection.";
cout << "\n\n\t1.	C = Car\n\t2.	V = Van\n\t3.	S = SUV\n\t4.	B = Bus\n\t5.	T = Truck" <<endl; 
cout << "\nPlease Enter Your Vehicle Type: "; cin >> input;
select= toupper(input);


while ((select!='C') && (select!='V') && (select!='S') && (select!='B') && (select!='T'))
{
cout << "Invalid input; Please try entering the information once more." << endl;
Selection(select, vehicleType, sizef);
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
*/
void HoursInandOut(int & hourIn, int & minuteIn, int & hourOut, int & minuteOut, int & hourDifference, int & minuteDifference, 
int & estimatedHour, string & ampmDesignator_in, string & ampmDesignator_out)
{
cout << "\n\nPlease enter your time of arrival, beginning with the hour value (06-24) and then minutes (00-59)" << endl;
cout << "\nHour of Arrival : "; cin >> hourIn;
	while ((hourIn < 6) && (hourIn > 24))
	{cout << "Invalid values. Please enter the values again." << endl;
	cout << "Hour of Arrival: ";
	cin >> hourIn;	
	}
cout << "\nMinute of Arrival : ";
cin >> minuteIn;	
	while ((minuteIn < 0) && (minuteIn > 60))
	{cout << "Invalid values. Please enter the values again." << endl;
	cout << "Minute of Arrival: ";
	cin >> minuteIn;
	}

cout <<	"\nPlease enter your time of departure, beginning with the hour value (06-24) and then minutes (00-59)" << endl;
cout << "\nHour of Departure : "; cin >> hourOut;
	while ((hourOut < 6) && (hourOut > 24))
	{cout << "Invalid values. Please enter the hour values again.";
	cin >> hourOut;
	}
cout << "\nMinute of Departure : "; cin >> minuteOut;	
	while ((minuteOut < 0) && (minuteOut > 60))
	{cout << "Invalid values. Please enter the minute values again.";
	cin >> minuteOut;	
	}
	
hourDifference= hourOut-hourIn;
minuteDifference= minuteOut-minuteIn;
if (minuteDifference > 0)
	{
	estimatedHour = hourDifference+1; /*Even if there is just 1 minute over zero, the 'hourDifference' variable
										 will still be increment up by 1 and place its value into the 'estimatedHour'
										 variable.*/
	}
else if (minuteDifference < 0)
	{
	hourDifference -= 1 ; 
	minuteDifference += 60; /*Because there are 60 minutes in one hour, if the 'minuteDifference' variable is negative,
								it will add 60 minutes to make it positive while decrementing the original value of hourDifference by 1, 
								similar to 'borrowing' in basic subtraction.*/
	estimatedHour = hourDifference+1; //The new value of hourDifference will be incremented by 1 and that new value will be put into the 'estimatedHour' variable.
	}
else
	{
	estimatedHour = hourDifference; //If the value of 'minuteDifference' is zero, the value of 'hourDifference' will remain the same.
	}

//Used to designate whether the time is AM or PM
if (hourIn > 12)
	{
	hourIn -= 12;
	ampmDesignator_in = "PM";
	}
else if (hourIn < 12)
	ampmDesignator_in = "AM";
else 
	ampmDesignator_in = "PM";
	
if (hourOut > 12)
	{
	hourOut -= 12;
	ampmDesignator_out = "PM";
	}
else if (hourOut < 12)
	ampmDesignator_out = "AM";
else 
	ampmDesignator_out = "PM";
}
//For calculating the rates of all vehicle types
float getRate(string vehicleType, int & hourDifference, int estimatedHour,
				  int cutoff, int est_Time, float firstRate, float secondRate)
{
est_Time = estimatedHour-cutoff; /* 'est_Time' is the estimated hours minus the cutoff. 
								This variable would ensure that the original value of
								'estimatedHour' was intact while also representing the
								amount of hours that were charged from the second rate.*/
while ((vehicleType=="Car") || (vehicleType=="Van") || (vehicleType=="SUV"))
{
firstRate=0.00;
secondRate=1.50;
cutoff = 3; // To represent that after the first 3 hours, the user will be charged with the second rate. 
if (hourDifference <=cutoff)
	{cout << "\n" << firstRate << endl;
	return firstRate;	
	}
else
	{
	float totalRate= (secondRate * (estimatedHour - cutoff));
	return totalRate;
	}

}

while ((vehicleType=="Bus") || (vehicleType=="Small Truck"))
{
firstRate=1.00;
secondRate=2.50;
cutoff = 2; //To represent that after the first 2 hours, the function will use the second rate to charge the user

if (hourDifference <=cutoff)
	return firstRate*estimatedHour;	
else
	{

	float totalRate= ((firstRate*cutoff) + (secondRate * est_Time));
	return totalRate;
	cout << "/n" << totalRate << endl;
}
}
while (vehicleType=="Large Truck")
{
firstRate=2.00;
secondRate=3.50;
cutoff = 1; //To represent that after the first hour, the function will use the second rate to charge the user.
if (hourDifference == cutoff)
	{
	return firstRate;	
	}
else
	{
	float totalRate= ((firstRate*cutoff) + (secondRate * est_Time));
	return totalRate;
	}

}
}


// used to print output for vehicles and calculate the final rate
void print(string vehicleType, int hourIn, int & minuteIn,string & ampmDesignator_in, int hourOut, int & minuteOut, string & ampmDesignator_out, int estimatedHour, 
int hourDifference, int minuteDifference, float totalRate, char restart)
{system("CLS");
cout << "\tPassaic County Parking Authority" << endl;
cout << "\n\t\tParking Lot Charges" << endl;
cout << "_______________________________________" << endl;
cout << "\nType of Vehicle: " << vehicleType << endl;
cout << fixed << showpoint << setprecision(2);

if (minuteIn < 10 )
	cout << "Time In: \t\t" << hourIn << ":" <<"0"<< minuteIn << " " << ampmDesignator_in << endl;
else
	cout <<  "Time In: \t\t" << hourIn << ":" << minuteIn << " " << ampmDesignator_in << endl;
	
if (minuteOut < 10)
	cout << "Time Out: \t\t" << hourOut << ":" <<"0"<< minuteOut <<" "<< ampmDesignator_out<< endl;
else
	cout << "Time Out: \t\t" << hourOut << ":" << minuteOut <<" "<< ampmDesignator_out<< endl;
cout << "_______________________________________" << endl;
cout << "Parking-Time \t\t" << hourDifference << "Hrs:" << minuteDifference << " minutes"<< endl;
cout << "Rounded Time: \t\t" << estimatedHour << " hours" << endl;
cout << "_______________________________________" << endl;
cout << "TOTAL DUE: \t\t" << "$" << totalRate << endl;

cout << "\n\nDo you have another vehicle? (Y/N)" << endl; cin >> restart;
restart = toupper(restart);
if (restart == 'Y')
	{
	system("CLS");
	main();
	}
else
	cout << "Have a nice day.";
}

