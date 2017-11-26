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
#include <string>
#include <cctype>

using namespace std;

const int LIST = 20;
//====================================================================================

//Array of Structures
typedef struct Student
{
	int id,q1, q2, q3;
	float avgt;
	
}Stud[LIST];
  

void setdata (Student *);
//Project 5 functions
void simpsearch(Student *);
void firstSearch(Student *);
	void bubbleSort(Student *);
		void swap(float * x, float * y);
		void swap(int * x, int * y);
	int Bin_Search(Student *, float * value);
void selectionSort(Student * const);
void userInputSearch(Student *);
		int Search(Student *, int *);

//====================================================================================

int main()
{

	Student * GradeInfo;
	
	GradeInfo= new Stud;
	
	ofstream disp("PR5OUTPUT.txt");
    	{
    		setdata (GradeInfo);
    			cin.get();
			simpsearch(GradeInfo);
				cin.get();
			firstSearch(GradeInfo);
				cin.get();
			selectionSort(GradeInfo);
				cin.get();
			userInputSearch(GradeInfo);
		}
	delete [] GradeInfo;
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
			FIRSTSEARCH
			
	The firstSearch function serves as a hub for the first
	necessary sort and search function. It will call a
	function to sort the values in ascending order, and
	then will call a binary search to search for the
	position of those values
*/

void firstSearch(Student * Info)
{
int elements=0, j=0;
	int * position;
	float * values;
	position= new int[elements];
	values= new float[elements];

cout << "\tCurrent Students At Or Above An 85.00 Average " << endl;	
	for (int i=0; i< LIST; i++)
	{
	// displays the ids and averages that are greater than or equal to 85.00
		if ((Info+i)->avgt >= 85.00)
		{
		cout << "ID: " << ((Info+i)->id) << "\t";
		cout << "AVERAGE: " << ((Info+i)->avgt) << endl;
		}
	}
//call function that sorts the arrays in ascending order based on the averages
	bubbleSort(Info);

// A for loop to count how many values are going to be searched and 
// store them in a float value
	for (int i=0; i< LIST; i++)
	{
	// To test if structure is passing	
	//cout << i+1 <<  ": ID: " << ((Info+i)->id) << "\tAVGT: " << ((Info+i)->avgt) << endl;
		if ((Info+i)->avgt >= 85.00)
		{
		//cout << "IMPORTANT POSITION " << i << ": " << ((Info+i)->avgt) << endl;	// test dialogue to show actual value position
		elements++;
		*(values+j)= (Info+i)->avgt;
		j++;
		//cout << "VALUES: " << *(values+(j-1)) << endl;	// test Value output
		}
	}
	//	To test if elements are being counted correctly
	/*for (int i=0; i < elements; i++)
	{
	cout << *(values+i) << " " << endl;
	}
	cout << "Elements: " << elements << endl;*/

// call search function that uses a binary search to return the position if score of >=85 found	
	cout << "\tCurrent Students At Or Above 85.00 Average" << endl;
	cout << "\t(Sorted by Average)" << endl;	
	for (int i=0; i < elements; i++)
	{
	*(position+i)= Bin_Search(Info, (values+i));	
	//cout << "Value: " << *(values+i)<< endl; // to test if values is being stored correctly
	cout << "Position: " << *(position+i) << endl;
	cout << "ID: "<< (Info+(*(position+i)))->id 
	<< "\t AVERAGE: " << (Info+(*(position+i)))->avgt << "\n" << endl;
	}
delete [] values;
delete [] position;
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
bool swoop;
do
{
	for (int i = 0; i < (LIST-1); i++)
 	{
 	swoop=false;	
 		for (int j = 0; j < (LIST-i-1); j++)
		{
		if (((Info+j)->avgt) >= ((Info+(j+1))->avgt))
		{
		swap(((Info+j)->id), ((Info+(j+1))->id));	
		swap(((Info+j)->avgt), ((Info+(j+1))->avgt));
		swap(((Info+j)->q1), ((Info+(j+1))->q1));
		swap(((Info+j)->q2), ((Info+(j+1))->q2));
		swap(((Info+j)->q3), ((Info+(j+1))->q3));
		swoop=true;
		}
		}
	}
}while (swoop);
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
			BINARY SEARCH FUNCTION
			
	The first binary search function will search for a test score
	(represented as a float value) within a sorted list and return
	its relative position.
	
*/

int Bin_Search(Student * Info, float * value)
{
int first = 0, // First array element
	last = LIST-1, // Last array element
middle, // Midpoint of search
pos = -1; // Position of search value
bool found = false;
	while (!found && first <= last)
	{
	middle = (first + last) / 2; // Calculate midpoint
		if ((Info+middle)->avgt == *(value)) // value is found at mid
		{
		found = true;
		pos = middle;
		}
			else if ((Info+middle)->avgt > *(value)) // value is in lower half
			last = middle - 1;
				else
				first = middle + 1; // value is in upper half
	}
return pos;
}

//==============================================================================================

/*
			SELECTION SORT METHOD
		
	A function that sorts the array, in ascending order, based on id, 
	using the selection sort. This function also has a counter to keep 
	the number of comparisons it took before the array became sorted.
*/

void selectionSort (Student * const Info)
{
	
	int start, minIndex, minValue, passes = 0;
	
	for(start = 0; start < (LIST-1); start++)
	{
	minIndex = start;
	minValue = (Info+start)->id; //Makes minValue equal to the first
								//ID in the array
											 
		for (int index = start + 1; index < LIST; index++)
		{
		//This is how it sorts the IDs in ascending order. 
		//If the second ID is less than the first ID
		//They swap.
			  
			if (((Info+index)->id) < minValue)
			{
			minValue = (Info+index)->id;
			minIndex = index;
			passes++;
			}
		}
	//This is the exchange that occurs outside
	//the internal for loop
	swap((Info+minIndex)->id, (Info+start)->id);
	swap((Info+minIndex)->q1, (Info+start)->q1);
	swap((Info+minIndex)->q2, (Info+start)->q2);
	swap((Info+minIndex)->q3, (Info+start)->q3);
	swap((Info+minIndex)->avgt, (Info+start)->avgt);
	(Info+start)->id = minValue;
	}
	cout << "\tStudent List" << endl;
	cout << "\t(Sorted by average)" << endl;	
	for(int i = 0; i < LIST; i++)
	{
	cout << "ID: " << (Info+i)->id << "\t AVERAGE: " << (Info+i)->avgt << endl;		
	}	
	
	cout << "Sorted " << passes << " times in order to be fully organized in ascending order" << endl;
}

//==============================================================================================

/*
			BINARY SEARCH AND PROMPT LOOP
			
	Perform a binary search that will display the id, test1, test2, test3 
	and average for a requested id, this should repeat until the user enters 
	'n' or 'N' as a response to a prompt.
	
	*In addition, Function will call a sub-function to perform a binary search
	for the ID in question.
*/

void userInputSearch(Student * Info)
{

int pos_Results, * searchTerm;
char r, repeat;
searchTerm= new int;

		cout << "Please enter a valid ID : "; cin >> *(searchTerm);
 		pos_Results = Search(Info, searchTerm);
 	// If pos = -1, the code was not found
 		if (pos_Results == -1)
			cout << "That ID does not exist";
 		else	
 			cout << "ID NUMBER : "<< (Info+pos_Results)->id<< "\n" << "\tQuiz 1: " << (Info+pos_Results)->q1 << "\t" 
			<< "Quiz 2: " << (Info+pos_Results)->q2 << "\t" << "Quiz 3: " << (Info+pos_Results)->q3 << 
			"\n\tAverage: " << (Info+pos_Results)->avgt << endl; 				
 		cout << "\nLook up another ID? If you do, enter any character. If you do not, enter 'n' or 'N': " << endl;
 		cin  >> r;
 		repeat= toupper(r);
 		if (repeat=='N')
 		{
 		cout << "\nThank you, you may press any button to exit the program now.";	
		}
		else
		{
		userInputSearch(Info);
		}
		delete searchTerm;
}


//==============================================================================================


/*		
			SEARCH FOR REQUESTED ID
			
	This function performs a linear search on an array of Student objects.
	using the user-inputted ID as the key-field
	
	If the desired ID is found, its array subscipt is returned. Otherwise -1
	is returned.
*/

int Search(Student * Info, int * searchTerm)
{
int first = 0, last = LIST-1, // first and last element
middle, pos = -1; // Middle of search and search value position
int found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint

		if ((Info+middle)->id == *(searchTerm)) // value is found at mid
		{
		found = true;
		pos = middle;
		}
			else if ((Info+middle)->id > *(searchTerm)) // value is in lower half
			last = middle - 1;
				else
				first = middle + 1; // value is in upper half
	}
cout << "Position: " << pos << endl;	
return pos;
}
