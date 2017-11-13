/*********************************************
	Name: Keymer A. Botero and Zailuj Hernadez
	Class: CIS-161 ME1
	Date: November 11th, 2017
	Due Date: November 20th, 2017
	Program Name: Project 5 - Back to Quiz 
	Statistics (Search and Sort Version)
	Description: This program reads a list of
	Students, from their four-digit IDs. and 
	each of their three quizzes that they have 
	taken during the term, from an array of 
	structures. In addition, the function will
	display ids and averages of the quizzes above 
	a specificied score in ascending order using 
	multiple search-and-sort methods
***********************************************/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int LIST = 20;
//User-Defined Arrays
typedef int intarray[LIST];
typedef float farray[LIST];

//Funcs used here
int getdata(intarray ,farray, farray, farray, ifstream &);
float findqzavg(int, farray);
void findstavg(int, intarray, farray, farray, farray, farray);
//====================================================================================

//Project 5 functions
void simpsearch(const intarray,const farray , int);
	void sort(farray [], farray []);
int Bin_Search(const intarray, const farray,int, int, int);
//====================================================================================

//template declarations


//====================================================================================

int main()
{
	intarray studidnum;
	farray quiz ,quiz1, quiz2, quiz3, stavg, avgquiz;
	int numofelements, Pos, Result_85;
	ifstream read("pr5data.txt");
	ofstream disp("PR5OUTPUT.txt");
		if (!read)
       cout << "File does not exist or is not open " << endl;
    else
    	{
    	numofelements = getdata (studidnum, quiz1, quiz2, quiz3, read);
		findstavg(numofelements, studidnum, quiz1, quiz2, quiz3, stavg);
		
		avgquiz[0]=findqzavg(numofelements, quiz1);
		avgquiz[1]= findqzavg(numofelements, quiz2);
		avgquiz[2]= findqzavg(numofelements, quiz3);

		simpsearch(studidnum, stavg, Pos);
	}
}

//=====================================================================================		
//Subject to array of structures 
int getdata(intarray studidnum, farray quiz1, farray quiz2, farray quiz3, ifstream & read)
{
	int i = 0;
	while ( read >> studidnum[i])
     	{
	read >> quiz1[i];
	read >> quiz2[i];
	read >> quiz3[i];	
	i++;
		 }
	return i-1; //To accomodate size of array	 
}

//=====================================================================

//Subject to change
float  findqzavg(int numofelements, farray quiz)
{
float sum, avg;
for (int i=0; i < numofelements; i++)
	{
		sum+=quiz[i];	
	}
	
avg= (sum/numofelements);
return avg;
}

//====================================================================================================================


void findstavg(int numofelements, intarray studentid, farray quiz1, farray quiz2, farray quiz3, farray stavg)
{
farray sum;	// this array will hold the sums of the student's 3 test grades
for (int i=0; i <= numofelements; i++)
{
	sum[i]= (quiz1[i] +quiz2[i] + quiz3[i]);
	stavg[i]= sum[i]/3;
}		
}
		
//====================================================================================================================================
/*			LISTS STUDENTS WHO SCORED 85 OR MORE
		
		The purpose is to list all students who had 
		scored at least 85 or higher and their ids as well.
		
		
		*	Function will then call another to sort the array 
		of students on based on test averages.
*/
void simpsearch(intarray const studidnum, farray const stavg, int Pos)
{
int z = 0;

	cout << "The students that have a quiz average of 85 or more are : \n" << endl;
		for(int i = 0; i < LIST-1; i++)
		{
			if (stavg[i] >= 85.00)
				{
				cout << fixed << showpoint << setprecision(2);					
				cout << "ID number : " << studidnum[i] << " has a " << stavg[i]<< " average so far." << endl;
				}
		}
	cin.get();
	//sort(stavg, stavg);
	cin.get();
	//Pos = Bin_Search(studidnum, stavg, 85, 0, LIST-1);
	/*if (Pos = -1)
	{
		cout << " Sorry, didn't work";
	}
		else
			cout << "YES";
	*/
}

//==============================================================================================
/*void sort(farray & x, farray & y)
{
float t = x;
x = y;
y = t;
}
*/
//==============================================================================================

int Bin_Search(intarray const studidnum, farray const stavg,int Result_85, int LowerB, int UpperB)
{
	
int middle;

middle = (0 + UpperB)/2;
cout << "Middle is : " << middle;
if	(LowerB > UpperB)
		return -1;
else	
	/*
	while (LowerB <= UpperB)
		if (Result_85 == stavg[middle])
			return middle;
		else 
			if (Result_85 < stavg[middle])
				LowerB = middle-1;
		else
			if (Result_85 > stavg[middle])
				UpperB = middle-1;	
	*/
return 0;				
}
