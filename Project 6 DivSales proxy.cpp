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
		int qtr1,qtr2,qtr3,qtr4, regionTotal;
		static int all_RegSales;  
		
		void setName(string & reg);
		void setRegSales();
        void setSale();
        void setAllReg();
              		
        
    
		//void getAllSales() const; 
									/*holds four quarters of sales
									for all divisions*/
        
        
    public:
    	region();
		      	      
        void setRegion();
        string getName(){return enterReg;};
        int getAllReg();
    	int getSale();
    	friend printSales(region, const int, const int j);
    	~region();
};

int printSales(region, const int i,const int j);

region::region()
{
	enterReg = "";
	qtr1 = 0;
	qtr2 = 0;
	qtr3 = 0;
	qtr4 = 0;
	// all_RegSales=0;
	arr_Sales = new int[3]; //starts the pointer to 4 elements
}

/*Destructor makes sure array properly release memory from array to
prevent leaks.*/
region::~region()
{
	if(arr_Sales) //If arr_Sales is not a null pointer
		delete [] arr_Sales;
}

int region::all_RegSales = 0;
/*****************************************************************/

int main()
{
		region money[4];
		char yesno, ans;
		int i=0, j=0, reg, value;
		
		//int i, j;
	for (int k=0; k<4; k++)	
	{cout << "REGION # " << (k+1) << endl;
	money[k].setRegion();
	}
	
/*	cout << "Would you like to search for a value?"; cin >> yesno;
	ans=toupper(yesno);
	if (ans='Y')
		{
		cout <<  "What Region are you looking for?\n" <<
			"Enter 1 for " << money[0].getName() << " 2 for " << money[1].getName() << 
			"\n 3 for " << money[2].getName() <<  " or 4 for " << money[3].getName() << 
			"\nfollowed by the quarter you wish to search for"<< endl; 
		cin >> i; cin >> j;
		printSales(money[i],i, j);		
		cout << "Would you like to search for a value?"; cin >> yesno;
		ans=toupper(yesno);
		}
		else
			cout << "Thank you for using the program." << endl;*/
	
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
		{
		string reg;			
					setName(reg);
					setRegSales();
					
		cin.get();
		cin.ignore();			
		}
}

void region::setName(string & reg)
{
	cout << "\nPlease enter Region name : "; getline(cin, reg);
	enterReg=reg;
}


/*
			SIMPLE VERSION : SETS QUARTER IN REGION
			
		Function allows user to input quarterly sales data
		and displays that data back to the user to check. However,
		this data can only account for one region at a time. 
*/
void region::setRegSales()
{
	region sales;
	regionTotal=0;
	for (int i=0; i<4; i++)
	{
	cout << "\nPlease enter Quarter " << (i+1) << ": "; cin >> *(arr_Sales+i);
	//cout << "Arr Sales: " << *(arr_Sales+i) << endl;
	regionTotal+= *(arr_Sales+i);
	}
	//setSale();
	//setAllReg();
	all_RegSales+= regionTotal;
	cout << "\nRegion "<< getName() << " has " << getSale() << " in total sales" <<endl; 
	cout << "Overall Total: " << getAllReg() << endl;	
	}
	
/* 
	SET AND GET FUNCTIONS
	These set and get functions are used to get a region's
	total quarterly sales as well as calculate the overall
	total sales for all regions
*/	
/*void region::setSale()
{
	for (int i=0; i<3; i++)
		regionTotal+= *(arr_Sales+i);
}	

void region::setAllReg()
{
	all_RegSales+= getSale();
}*/

int region::getSale()
{
return regionTotal;	
}

int region::getAllReg()
{
	return all_RegSales;
}

int printSales(region sales, const int i,const int j)
//int region::printSales(const region sales, const int i,const int j)
{
	cout << sales.getName() << "'s " << (j) << "quarter had " << endl; //<< sales.*(arr_Sales+(j-1));
	return 0;	
}
	
