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
	//void sort(farray [], farray []);
//int Bin_Search(const intarray, farray,int, int, int);
//====================================================================================

int main()
{

	Stud GradeInfo;
	ofstream disp("PR5OUTPUT.txt");
    	{
    	setdata (GradeInfo);
		simpsearch(GradeInfo);
	}
}

//=====================================================================================		

void setdata(Student * Info)//intarray ID, farray quiz1, farray quiz2, farray quiz3, farray stavg,  ifstream & read)
{
ifstream read("pr5data.txt");
	if (!read)
       cout << "File does not exist or is not open " << endl;
    else
		
	
	int i = 0;
	cout << fixed << showpoint << setprecision(2);					

	for (int j = 0 ; j < LIST ; j++)
     	{
   			 read >> (*Info).id;
    		 read >> (*Info).q1;
    		 read >> (*Info).q2;
    		 read >> (*Info).q3;
			    
    (*Info).avgt = ((*Info).q1 + (*Info).q2 + (*Info).q3)/3.0;
//	cout <<"ID NUMBER : " << (*Info).id << "    "<<" AVGT: "<<(*Info).avgt<<endl;
			Info++;
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
	//sort(stavg, stavg);
	//Pos = Bin_Search(ID, stavg, 85, 0, LIST-1);
	/*if (Pos = -1)
	{
		cout << " Sorry, didn't work";
	}
		else
			cout << "YES";
	*/
}

//==============================================================================================
/*
void sort(farray & x, farray & y)
{
float t = x;
x = y;
y = t;
}
*/
//==============================================================================================
/*
int Bin_Search(intarray const ID, farray const stavg,int Result_85, int LowerB, int UpperB)
{
	
int middle;

middle = (0 + UpperB)/2;
cout << "Middle is : " << middle;
if	(LowerB > UpperB)
		return -1;
else	
	
	while (LowerB <= UpperB)
		if (Result_85 == stavg[middle])
			return middle;
		else 
			if (Result_85 < stavg[middle])
				LowerB = middle-1;
		else
			if (Result_85 > stavg[middle])
				UpperB = middle-1;	
	
return 0;				
}
*/
