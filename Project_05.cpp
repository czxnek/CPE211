//*******************************************
// Program Title: Project_05
// Project File: Project_05.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 02/19/2021
// program description: reads numbers from a file inputted and outputs the numbers, sum of the numbers, average, and average range (high medium or low) to an output file
//*******************************************

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<climits>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3) // command line argument test for running in unix terminal
	{
		cout << endl;
		cout << string(9, '*') << " Command Line Argument Error " << string(9, '*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==> ./Project_05 inputFileName  outputFileName\n";
		cout << string(47, '*') << endl << endl;
		return 1;
	}

	ifstream input; // file containing input data
	ofstream output; // file where output is written

	string infilename = argv[1]; // name of selected input file
	string outfilename = argv[2]; // name of selected output file
	
	float fnum; // first number in input file
	float snum; // second number in input file
	float tnum; // third number in input file
	float sum; // sum of numbers from input file
	float average; // average for numbers from input file

	
	cout << endl;

	cout << "Opening Input File: " << infilename << endl << endl;
	

	input.open(infilename.c_str()); // attempting to open input file
	if(input.fail()) // test to see if input file works
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << infilename << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl << endl;
	
		
		return 1;
	}

	cout << "Opening Output File: " << outfilename << endl << endl;

	output.open(outfilename.c_str()); // attempting to open output file
	if (output.fail()) // test to see if output file works
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outfilename << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl << endl;

		return 1;
	}

	input.ignore(INT_MAX, 'A'); // grabbing numbers after A from input file
	input >> fnum;

	input.ignore(INT_MAX, 'B'); // grabbing numbers after B from input file
	input >> snum;

	input.ignore(INT_MAX, 'C'); // grabbing numbers after C from input file
	input >> tnum;

	if (fnum < 0 || snum < 0 || tnum < 0) // testing to see if there are any negative numbers 
	{
		cout << string(15, '*') << " Negative Number " << string(15, '*') << endl;
		if(fnum < 0)
		{
			cout << "==> First number is less than 0" << endl;
		}
		if (snum < 0)
		{
			cout << "==> Second number is less than 0" << endl;
		}
		if (tnum < 0)
		{
			cout << "==> Third number is less than 0" << endl;
		}
		
		cout << "==> All numbers should be positive" << endl;
		cout << "==> Terminating program!!!" << endl;
		cout << string(47, '*') << endl << endl;

		return 0;
	}

	// beginning of output to outfile

		output << string(47, '*') << endl;
		output << left << setw(35) << "The numbers read are: " << fixed << setprecision(2) << fnum << " " << snum << " " << tnum << endl;
		
		(sum = (fnum + snum + tnum)); // sum of numbers from input file
		output << setw(35) << "The sum of the numbers is: " << fixed << setprecision(2) << sum << endl;

        (average = sum / 3); // average of the numbers from input file
		output << setw(35) << "The average of these numbers is: " << fixed << setprecision(2) << average << endl;

		// testing to see if average is high, medium, or low 

		if (average >= 75) 
		{
			output << setw(35) << "This average is:" << "High" << endl;
		}
		if (average < 75 && average >= 25)
		{
			output << setw(35) << "This average is:" << "Medium" << endl;
		}
		if (average < 25)
		{
		    output << setw(35) << "This average is:" << "Low" << endl;
		}

		output << setw(35) << string(47, '*') << endl;
	
		output.close(); // closing output file





	

	return 0;
}