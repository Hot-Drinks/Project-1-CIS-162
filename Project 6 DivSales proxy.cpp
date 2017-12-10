/******************************************************************
		Names : Keymer A. Botero, Zailuj Hernadez
		Class : CIS-161 ME1
		Date  : December 8th, 2017
		Due Date : December 13th, 2017
		Program Name : Project 6 Division of Sales
		Description: The program should ask the user to enter the region's name, 
		and sales for four quarters for each region.
		After the data is entered, the program should display
		a table showing each region's name followed by the sales
		for each quarter, and then followed by the total
		sale for the region. At the end, the program will 
		display the total corporate sales for the year.
*******************************************************************/


#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class region
{
	 private:
        string enterReg; //holds "East", "West", etc..
		int * arr_Sales; /*a pointer that points to an array of 4
        						elements for holding 4 quarters of sales
        						figures for the sales
        					*/       	
		int qtr1,qtr2,qtr3,qtr4;
		
		//static int all_RegSales;        		
        
    
		//void getAllSales() const; 
									/*holds four quarters of sales
									for all divisions*/
        
        
    public:
        ~region();
    	region();
		      	      
        void setRegion();
    	void setRegSales();
};

region::region()
{
	enterReg = "";
	qtr1 = 0;
	qtr2 = 0;
	qtr3 = 0;
	qtr4 = 0;
	arr_Sales = new int[4]; //starts the pointer to 4 elements
}

/*Destructor makes sure array properly release memory from array to
prevent leaks.*/
region::~region()
{
	if(arr_Sales) //If arr_Sales is not a null pointer
		delete [] arr_Sales;
}

//int region::all_RegSales = 0;
/*****************************************************************/

int main()
{
		region money;
		
	money.setRegion();
	
	return 0;	
}


/*
			SIMPLE VERSION : SETS REGION NAME
		
		Function allows user to input Region name, one at a time.
		In addition, a seperate function is called to set quarterly
		sales data. Afterwards, Function loops back and begins naming
		process again, however, that process is not stored at the moment.
*/
void region::setRegion()
{
	for(int i = 0; i < 3; i++)
		{
		cout << "\nPlease enter Region name : "; getline(cin, enterReg);	
			for (int j = 0; j < 3; j++)
				{
					setRegSales();
				}	
		cout << "\nRegion "<< enterReg /*<< " has " << all_RegSales<< " in total sales"*/ <<endl; 
		}
}


/*
			SIMPLE VERSION : SETS QUARTER IN REGION
			
		Function allows user to input quarterly sales data
		and displays that data back to the user to check. However,
		this data can only account for one region at a time. 
*/
void region::setRegSales()
{
	cout << "\nPlease enter Quarter 1 : "; cin >> qtr1;
	cout << "\nPlease enter Quarter 2 : "; cin >> qtr2;			
	cout << "\nPlease enter Quarter 3 : "; cin >> qtr3;	
	cout << "\nPlease enter Quarter 4 : "; cin >> qtr4;
	//all_RegSales = qtr1+qtr2+qtr3+qtr4; Causes error
	cout << qtr1 <<"\n"<< qtr2 <<"\n"<< qtr3 << "\n"<<qtr4;	
}
