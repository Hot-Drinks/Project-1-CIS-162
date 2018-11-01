/******************************************************************
		Names : Keymer A. Botero, Zailuj Hernadez
		Class : CIS-161 ME1
		Date  : December 8th, 2017
		Due Date : December 13th, 2017
		Program Name : Project 6 Division of Sales
		Description: The program should ask the user to enter the DivSales's name, 
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
#include <iomanip>

using namespace std;

class DivSales
{
	 private:
        string enterReg; //holds "East", "West", etc..
    	
		int qtr[4]; //holds 4 quarters for the four regions.
		int regionTotal; //holds 4 totals of each regions 
		
		static int totalCorpSales;
		static int totalQtr[4];
		  
		
		void setName();
		void setRegSales();

    public:
    	DivSales();
		      	      
        void setRegion();
        const string getName();     		
        const int getAllSales();
    	const int getSale();       
		int getTotalQtr(int);
    	void print();
    	
		int search(int,int);
		
		
    	
    	~DivSales(){};
		
    	
};

DivSales::DivSales()
{
	for(int a = 0; a < 4; a++)
	{
		enterReg = "";
		qtr[a] = 0;
	}
			regionTotal = 0;	
}

int DivSales::totalCorpSales = 0;
int DivSales::totalQtr[4];
//================================================================================


int main()
{
	DivSales regsales[4];
	char yesno, ans;
	int i, j;		
//		cout << "REGION # " << i+1 << endl;
	for (int c = 0; c < 4; c++)
		{
			regsales[c].setRegion(); 
		}
system("CLS");
		for (int d= 0; d< 4; d++)
			{
				regsales[d].print();
			}
	cout << "All Regions Total : "<< regsales[4].getAllSales();


	cout << "Search for a value? "; cin >> yesno;
	ans=toupper(yesno);
	if (ans='Y')
	{
		cout << "What region and quarter?"; cin >> i; cin >> j;
		cout << "The " << regsales[i-1].getName() << " region's Quarter " << j << "'s  sales is " << regsales[i-1].search(i,j) << endl;
	}

	for (int j=0; j<4; j++)
						{
							cout << "Total Qtr " << j+1 << ": " << getTotalQtr(j) << endl;
						}
		//	cout << "All Quarters "
return 0;
}
//=================================================================================

/*
			SETS REGION NAME
		
		Function allows user to input Region name, one at a time.
		In addition, a seperate function is called to set quarterly
		sales data. Afterwards, Function loops back and begins naming
		process again
*/
void DivSales::setRegion()
{
	
		setName();
		setRegSales();
		cin.get();
		cin.ignore();	
	
}


//=================================================================================

void DivSales::setName()
{
	cout << "\nPlease enter Region name : "; getline(cin, enterReg);

}

const string DivSales::getName()

{return enterReg;};  
//=================================================================================
/*
			SETS QUARTER IN REGION
			
		Function allows user to input quarterly sales data
		and displays that data back to the user to check.
		
		*In the meantime, Function will accumulate qtr values 
		to create the Region's total sales, "regionTotal"
		
		*In addition, Function will accumulate values from 
		multiple instances of regionTotal to form TotalCorpSales
		
*/
void DivSales::setRegSales()
{

			for (int i=0; i<4; i++)
				{
					cout << "\nPlease enter Quarter " << (i+1) << ": "; cin >> qtr[i];
					regionTotal+=qtr[i];
					totalQtr[i]+=qtr[i];
					cout << "TTL QTR: " << totalQtr[i]<< endl;
				}
			totalCorpSales+= regionTotal;
		
			
		 
	cout << "\nRegion "<< getName() << " has " << getSale() << " in total sales" <<endl; 
	cout << "Overall Total: " << getAllSales() << endl;	
}
	
//=================================================================================

const int DivSales::getSale()
{
	return regionTotal;	
}
//=================================================================================
const int DivSales::getAllSales()
{
	return totalCorpSales;
}
//=================================================================================
void DivSales::print()
{
			cout << getName() <<endl;
				for(int j = 0; j< 4; j++)
				{
				cout << "\tQuarter " << (j+1) <<" "<< qtr[j]<<endl;
				}
			cout <<"\t\tRegion's Total : "<< getSale() <<endl;
}

int DivSales::search(int i, int j)
{
	float position=0;
	
	cout << "Positions:" << i << ", " << j << endl;
	
	position = qtr[j-1];	
	return position;
	
}

int DivSales::getTotalQtr(int i)
{
	return totalQtr[i];
}

