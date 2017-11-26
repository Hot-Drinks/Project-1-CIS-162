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
# include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

const int LIST = 20;
//====================================================================================

//Array of Structures
typedef struct Student
{
	int id,q1, q2, q3;
	float avgt;
	
}Stud[LIST];

/*			VECTORS
		These are temporarily holding these values.
		They will be replaced with appropriate pointers.
*/		
typedef vector <float> Searchvalues;
typedef vector <int> Positionvalues;  

void setdata (Student *);
//Project 5 functions
void simpsearch(Student *);
void firstSearch(Student *);
	void bubbleSort(Student *);
		void swap(float * x, float * y);
		void swap(int * x, int * y);
	int Bin_Search(Student *, float & value);
//====================================================================================

int main()
{

	Student * GradeInfo;
	GradeInfo= new Stud;
	ofstream disp("PR5OUTPUT.txt");
    	{
    	setdata (GradeInfo);
		simpsearch(GradeInfo);
		firstSearch(GradeInfo);
	}
	delete[] GradeInfo;
}

//=====================================================================================		

void setdata(Student * Info)
{
ifstream read("pr5data.txt");
	if (!read)
       cout << "File does not exist or is not open " << endl;
    else
		
	
	int i = 0;
	cout << fixed << showpoint << setprecision(2);					

	for (int j = 0 ; j < LIST ; j++, Info++)
     	{
   			 read >> (*Info).id;
    		 read >> (*Info).q1;
    		 read >> (*Info).q2;
    		 read >> (*Info).q3;
			    
    (*Info).avgt = ((*Info).q1 + (*Info).q2 + (*Info).q3)/3.0;
	cout <<"ID NUMBER : " << (*Info).id << "    "<<" AVGT: "<<(*Info).avgt<<endl;

		}
read.close();
}



//====================================================================================================================================
/*			LISTS STUDENTS WHO SCORED 85 OR MORE
		
		The purpose is to list all students who had 
		scored at least 85 or higher and their ids as well.
		
		
		*	Function will then call another to sort the array 
		of students on based on test averages.
*/
void simpsearch(Student * Info)
{
	
	cout << "The students that have a quiz average of 85 or more are : \n" << endl;
		for(int i = 20; i > 0; i--)
		{
			//cout << (*Info).avgt<<endl;
			if ((*Info).avgt >= 85.00)
				{
				cout << "ID number : " << (*Info).id << " has a " << (*Info).avgt << " average so far." << endl;
				}
		Info++;
		}
}

//==============================================================================================
/*
			FIRSTSORT
	The firstSearch function serves as a hub for the first
	necessary sort and search function. It will call a
	function to sort the values in ascending order, and
	then will call a binary search to search for the
	position of those values
*/

void firstSearch(Student * Info)
{
	Positionvalues position;
	Searchvalues values;
	int elements=0;
//call function that sorts the arrays in ascending order based on the averages
bubbleSort(Info);
// A for loop to count how many values are going to be searched
// and store them in a vector 
for (int i=0; i< LIST; i++)
{
// To test if structure is passing	
//cout << i+1 <<  ": ID: " << ((Info+i)->id) << "\tAVGT: " << ((Info+i)->avgt) << endl;
if ((Info+i)->avgt >= 85.00)
{
	cout << "IMPORTANT POSITION " << i << ": " << ((Info+i)->avgt) << endl;	// test dialogue to show value position
	elements++;
	values.push_back((Info+i)->avgt);
}
}
//	To test if elements are being counted correctly
/*for (int i=0; i < elements; i++)
{
	cout << (values[i]) << " " << endl;
}
cout << "Elements: " << elements << endl;*/

// call search function that uses a binary search to return the position if score of >=85 found	
for (int i=0; i < elements; i++)
{
position.push_back(Bin_Search(Info, values[i]));
cout << "Value: " << values[i] << endl;
//cout << "Position: " << position[i] << endl;
cout << "ID: "<< (Info+position[i])->id << "\t AVGT: " << (Info+position[i])->avgt << " \n" << endl;
}

}


/*
			BUBBLE SORT 
	This sort function performs a bubble sort to
	sort the values within the structure in ascending
	order. It will then search for any score above 85,
	store the values and how many there are to aid in
	searching
*/
void bubbleSort(Student * Info) //float * average, int * id
{
for (int i = 0; i < (LIST-1); i++)
 {
 	
 for (int j = 0; j < (LIST-i-1); j++)
{
if (((Info+j)->avgt) >= ((Info+(j+1))->avgt))
{
swap(((Info+j)->avgt), ((Info+(j+1))->avgt));
swap(((Info+j)->id), ((Info+(j+1))->id));	
}
}
}
}

/* 

				SWAP FUNCTIONS
	These are overloaded functions meant to swap whatever values
	are needing to be swapped in sort functions. There is one
	to swap inter pointers and one to swap float pointers.

*/
void swap(float * x, float * y)
{
float * t = x;
x = y;
y = t;
}

void swap(int * x, int * y)
{
int * t = x;
x = y;
y = t;
}

//==============================================================================================
/*
		BINARY SEARCH FUNCTIONS
	Bin_Search:
	The first binary search function will search for a test score
	(represented as a float value) within a sorted list and return
	its relative position.
	
*/

int Bin_Search(Student * Info, float & value)
{
int first = 0, // First array element
	last = LIST-1, // Last array element
middle, // Midpoint of search
position = -1; // Position of search value
bool found = false; // Flag
while (!found && first <= last)
{
middle = (first + last) / 2; // Calculate midpoint
if ((Info+middle)->avgt == value) // If value is found at mid
{
found = true;
position = middle;
}
else if ((Info+middle)->avgt > value) // If value is in lower half
last = middle - 1;
else
first = middle + 1; // If value is in upper half
}
return position;
}

/*
			SELECTIONSORT
			
*/
 void selectionSort(Student * const Info)
{
int passes=0;	
int startScan, minIndex, minValue;
for (startScan = 0; startScan < (LIST - 1); startScan++)
{
minIndex = startScan;
minValue = (Info+startScan)->id;
//cout << "Min Value: " << minValue << endl;
for(int index = startScan + 1; index < LIST; index++)
{
if (((Info+index)->id) < (minValue))
{
minValue = (Info+index)->id;
minIndex = index;
passes++;
}
}

(Info+minIndex)->id = (Info+startScan)->id;
(Info+startScan)->id = minValue;
//cout << (Info+startScan)->id << endl;
}
for (int i=0; i< LIST; i++)
{
	cout << "ID: " << (Info+i)->id << "\t AVGT: " << (Info+i)->avgt << endl;
}
cout << "Sorted " << passes <<  " times" << endl;
}
