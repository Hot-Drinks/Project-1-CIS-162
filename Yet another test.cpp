/*********************************************
	Name: Keymer A. Botero and Zailuj Hernadez
	Class: CIS-161 ME1
	Date: October 27th, 2017
	Due Date: November 1st, 2017
	Program Name: Project 4 - Quiz Statistics
	(Vectors)
	Description: This program reads a list of
	Students, from their four-digit IDs. and 
	each of their three quizzes that they have 
	taken during the term. In addition, the 
	program will calculate an average based on 
	the three quizzes and all the data is kept
	on a text file name "pr2data"
***********************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef vector <int> Idreader;
typedef vector <int> value;
typedef vector <float> qzreader;
typedef vector <float> average; //Might need to add more vectors if needed


int getdata(Idreader &,qzreader &, qzreader &, qzreader &,qzreader&, ifstream&);
void printall(Idreader,qzreader, qzreader, const qzreader, value, value,
average stavg, average qzavg);
	void headings();
	void report(Idreader,qzreader, qzreader, qzreader, Idreader, Idreader, qzreader, qzreader);
	void hi_and_lo_avg(const qzreader &,const qzreader &, const qzreader &, value &, value &,
	average &, average &);
int findhigh(qzreader);
int findlow(qzreader);
float findqzavg(const qzreader &);
void findstavg(const qzreader &, const qzreader &, const qzreader &, average &);

int main()
{
	
	Idreader id;
	value hiqz, loqz;
	qzreader quiz, quiz1, quiz2, quiz3; //'quiz' is just a test variable, subject to change to qz1,qz2,qz3 
	average stavg, qzavg; 	
	ifstream fin("pr2data.txt");

	if (!fin)
       {
	   cout << "File does not exist or is not open " << endl;
       return 1;
   	   }
		else 
			{
				getdata(id,quiz1, quiz2, quiz3,quiz , fin);
				
				/*
				By overloading the functions findlow,findhigh,findqzavg, we can 
				make our function perform the same task needed without modifying any
				data in the given vectors. We overloaded the functions to display data
				for quiz1, quiz2, and quiz3.
				*/
				
				findhigh(quiz1);
				findhigh(quiz2);
				findhigh(quiz3);
				
				findlow(quiz1);
				findlow(quiz2);
				findlow(quiz3);

				findqzavg(quiz1);
				findqzavg(quiz2);
				findqzavg(quiz3);
				
				findstavg(quiz1,quiz2,quiz3,stavg);
				printall(id, quiz1, quiz2, quiz3, hiqz, loqz, stavg, qzavg);
				
				return 0;
			}			
}

/*
		READING DATA FROM SAMPLE INPUT FILE
		
	The purpose of function is to read data from the
	file known as "pr2data.txt", and place their values
	into their corresponding vector lists.
*/
int getdata( Idreader & ids,qzreader & quiz1, qzreader & quiz2, qzreader & quiz3,qzreader & quiz, ifstream &fin)
{		
	int idnum, i=0;
	float qz1, qz2, qz3; 
	while (fin >> idnum)
	{
		ids.push_back(idnum);
		fin >> qz1;
		quiz1.push_back(qz1);
		fin >> qz2;
		quiz2.push_back(qz2);
		fin >> qz3;
		quiz3.push_back(qz3);
	}
	fin.close();
}


/*
			FIND HIGH
		
		This function will take the students' test scores
		and pick out the value that is the highest. It can be
		reused to find highest score of multiple quizzes.

*/
int findhigh(qzreader quiz)
{
int large= 0;
for (int i=0; i < quiz.size(); i++)
{
	if (quiz[i] > large)
		{
		large= quiz[i];
		}
}
return large;
}

/*
			FIND LOW
	
		This function will take the students' test scores
		and pick out the value that is the lowest. It can be
		reused to find the lowest score of multiple quizzes.

*/

int findlow(qzreader quiz)
{
int small= quiz[0];
for (int i=0; i < quiz.size(); i++)
{
	while ((quiz[i] < small))
		{
		small= quiz[i];
		}				
}
return small;
}


/*
			FIND QUIZ AVERAGE
		
		This function will take a class's quiz values and find the
		total class average. It will do this by totaling up each student's 
		quiz result and then dividing it by the number of quiz results.
		This function is reusable and can be called to find multiple
		quiz averages.

*/
float findqzavg(const qzreader & quiz)
{
float sum=0, avg;
for (int i=0; i < quiz.size(); i++)
	{
		sum+=quiz[i];
	}
	

avg= (sum/quiz.size());
return avg;	
}

/*
			FIND STUDENT AVERAGE
		
		This function will take each student's test scores and calculate
		an average for each one of them, and then store it.
*/
void findstavg(const qzreader & quiz1, const qzreader & quiz2, const qzreader & quiz3, average & stavg)
{
	for (int i =0; i < quiz1.size(); i++)
	{
		stavg.push_back((quiz1[i]+quiz2[i]+quiz3[i])/3);		
	}


}

/*
			CALLING THREE SEPERATE SUB-FUNCTIONS FOR NEEDED TASKS 
			
		The purpose of this function will call three sub-functions
		that will perform three seperate tasks.No new data is 
		created
*/
void printall(Idreader ids,qzreader quiz1, qzreader quiz2, qzreader quiz3, value hiqz, value loqz,
average stavg, average qzavg)
{
		
headings();
hi_and_lo_avg(quiz1,quiz2,quiz3, hiqz, loqz, stavg, qzavg);
report(ids, quiz1, quiz2, quiz3, hiqz, loqz, stavg, qzavg);
}

/*			CREATES HEADINGS FOR DATA

		"headings()" will simply print needed headings for a 
		student's ID number and quiz scores. No New data is created
*/
void headings()
{		
	cout << "\t\tCIS Department - Fall 2017\n\t\t CIS 161 Class Statistics\n";
	cout << "\t\t==========================\n\n\n";
	cout << "Student"<<"       "<<"Quiz 1"<<"    "<<"Quiz 2" <<"    "<<"Quiz 3"<<"    "<<"Average"<<"     "<<"" <<endl;
	cout << "-------"<<"       "<<"------"<<"    "<<"------" <<"    "<<"------"<<"    "<< "------"<<"     "<<"" <<endl;
	
}

/*			PRINTS DATA FOR USER TO READ

 		"report()" will print all student ID's given from 
		the "pr2data.txt" file, each of their quiz scores, 
		and each average that each student ended with.
		No new data is created
*/
void report(Idreader ids,qzreader quiz1, qzreader quiz2, qzreader quiz3,value hiqz, value loqz,
average stavg, average qzavg)
{
	ofstream fout ("PR4OUTPUT.txt");
	for(int i = 0; i < ids.size()-1; i++)
		{
			cout << left<<setw(6)<<ids[i]<<right<<setw(12) <<quiz1[i]<<right<<setw(12) <<quiz2[i];
			cout << right<<setw(10) <<quiz3[i]<<right<<setw(12);
			cout << fixed<<showpoint<<setprecision(2);
			cout << right<<setw(10) << stavg[i]<<right<<setw(12) << endl;
			cout << noshowpoint << setprecision(0);
		}
		
		cout << left<<setw(6) << "\nHigh Score" << right << setw(8) << hiqz[0] << right << setw(12) << hiqz[1];
		cout << right << setw(10) << hiqz[2]<<endl;
		cout << left<<setw(6) << "Low Score" << right << setw(9) << loqz[0] << right << setw(12) << loqz[1];
		cout << right << setw(10) << loqz[2]<<endl;
		cout << fixed<<showpoint<<setprecision(2);
		cout << left<<setw(6) << "Quiz Average" << right << setw(8) << qzavg[0] << right << setw(12) << qzavg[1];
		cout << right << setw(10) << qzavg[2]<<endl;
		cout << noshowpoint << setprecision(0);
		
		
	fout << "\t\tCIS Department - Fall 2017\n\t\t CIS 161 Class Statistics\n";
	fout << "\t\t==========================\n\n\n";
	fout << "Student"<<"       "<<"Quiz 1"<<"    "<<"Quiz 2" <<"    "<<"Quiz 3"<<"    "<<"Average"<<"     "<<"" <<endl;
	fout << "-------"<<"       "<<"------"<<"    "<<"------" <<"    "<<"------"<<"    "<< "------"<<"     "<<"" <<endl;
	for(int i = 0; i < ids.size()-1; i++)
		{
			fout << left<<setw(6)<<ids[i]<<right<<setw(12) <<quiz1[i]<<right<<setw(12) <<quiz2[i];
			fout << right<<setw(10) <<quiz3[i]<<right<<setw(12);
			fout << fixed<<showpoint<<setprecision(2);
			fout << right<<setw(10) << stavg[i]<<right<<setw(12) << endl;
			fout << noshowpoint << setprecision(0);
		}
		
		fout << left<<setw(6) << "\nHigh Score" << right << setw(8) << hiqz[0] << right << setw(12) << hiqz[1];
		fout << right << setw(10) << hiqz[2]<<endl;
		fout << left<<setw(6) << "Low Score" << right << setw(9) << loqz[0] << right << setw(12) << loqz[1];
		fout << right << setw(10) << loqz[2]<<endl;
		fout << fixed<<showpoint<<setprecision(2);
		fout << left<<setw(6) << "Quiz Average" << right << setw(8) << qzavg[0] << right << setw(12) << qzavg[1];
		fout << right << setw(10) << qzavg[2]<<endl;
		fout << noshowpoint << setprecision(0);
}


/*			
			FINDS HIGHEST AND LOWEST SCORES AND THEIR AVERAGE

		"hi_and_lo_avg()" will simply find the highest and 
		lowest scores of each quiz and find average of those 
		seperate quiz scores.
*/

void hi_and_lo_avg(const qzreader & quiz1,const qzreader & quiz2, const qzreader & quiz3, value & hiqz, value & loqz,
average & stavg, average & qzavg) 
{


hiqz.push_back(findhigh(quiz1));
hiqz.push_back(findhigh(quiz2));
hiqz.push_back(findhigh(quiz3));

loqz.push_back(findlow(quiz1));
loqz.push_back(findlow(quiz2));
loqz.push_back(findlow(quiz3));

qzavg.push_back(findqzavg(quiz1));
qzavg.push_back(findqzavg(quiz2));
qzavg.push_back(findqzavg(quiz3));

findstavg(quiz1,quiz2,quiz3, stavg);
}


/*
                CIS Department - Fall 2017
                 CIS 161 Class Statistics
                ==========================


Student       Quiz 1    Quiz 2    Quiz 3    Average
-------       ------    ------    ------    ------
1234            52          70        75     65.67
2134            90          76        90     85.33
3124            90          95        98     94.33
4532            21          17        81     39.67
5678            20          22        45     29.00
6134            34          45        55     44.67
7874            60          99        56     71.67
8026            70          10        66     48.67
9893            34           9        77     40.00
2233            78          20        78     58.67
1947            45          40        88     57.67
3456            78          55        78     70.33
2877            55          50        95     66.67
3189            70          98        78     82.00
2132            77          97        80     84.67
4602            89          50        91     76.67
3445            78          60        78     72.00
5405            35          33        15     27.67
4556            78          20        18     38.67
6999            88          98        89     91.67
9898            48          78        68     64.67
2323            78          20        78     58.67

High Score      90          99        98
Low Score       20           9        15
Quiz Average   62.87       51.39     71.96

--------------------------------
Process exited after 0.05926 seconds with return value 0
Press any key to continue . . .
*/
