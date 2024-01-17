//*******************************************
// Program Title: Project_06
// Project File: Project_06.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 03/02/2021
// program description: Information regarding a set of test scores from a class is stored in an input file.
//*******************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

int main( int argc, char *argv[] )
{
	if (argc != 3) // command line argument test for running in unix terminal
	{
		cout << endl;
		cout << string(9, '*') << " Command Line Argument Error " << string(9, '*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==> ./Project_06 inputFileName outputFileName\n";
		cout << string(47, '*') << endl << endl;

		return 1;
	}

	// integer grades from input file
	int grade1; // first grade
	int grade2; // second grade 
	int grade3; // third grade
	int grade4; // fourth grade
	string section; // string from last line of input file
	float sum; // sum of grades
	float average; // average of grades
	
	// declarations to use input and output files
	ifstream input; // file containing input data
	ofstream output; // file where output is written

	// names of files
	string infilename = argv[1]; // name of selected input file
	string outfilename = argv[2]; // name of selected output file

	cout << endl;

	cout << "Opening input file: " << infilename << endl << endl;
    input.open(infilename.c_str()); // attempting to open input file

	while (input.fail()) // loop in case input fails allowing to enter another input file
	{
		input.clear(); // clearing before entering again
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!" << endl;
		cout << "==> Attempted to open file: " << infilename << endl;
		cout << "==> Try Again" << endl;
		cout << string(47, '*');

		cout << endl << endl << "Enter in the name of the input file: ";

		cin >> infilename; // user enters in infilename
		cout << infilename << endl << endl; // echo print
		input.ignore(INT_MAX, '\n'); // ignoring excess characters
		input.open(infilename.c_str()); // trying to open again
    }

	cout << "Opening output file: " << outfilename << endl << endl;
    output.open(outfilename.c_str()); // attempting to open output file

	while (output.fail()) // loop in case output fails allowing to enter another file name
	{
		output.clear(); // clearing before entering again
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Output file failed to open properly!!" << endl;
		cout << "==> Attempted to open file: " << outfilename << endl;
		cout << "==> Try Again" << endl;
		cout << string(47, '*');

		cout << endl << endl << "Enter in the name of the output file: ";
		cin >> outfilename; // user enters in outfilename
		cout << outfilename << endl << endl; // echo print
		cin.ignore(INT_MAX, '\n'); // ignoring excess characters
		output.open(outfilename.c_str()); // trying to open again
	}

	// getting scores from input file
	input.ignore(INT_MAX, '\n');
	input >> grade1;
	input >> grade2;
	input >> grade3;
	input >> grade4;
	
    if (input.fail()) // if statement in case of error in input file
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << "==> Reading of the 4 test scores failed." << endl;
		cout << "==> The input stream is in the fail state mode." << endl;
		cout << "==> There is an error in the input file." << endl;
		cout << "==> Program Terminated." << endl;
		cout << string(47, '*') << endl;


		output << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		output << "==> Reading of the 4 test scores failed." << endl;
		output << "==> The input stream is in the fail state mode." << endl;
		output << "==> There is an error in the input file." << endl;
		output << "==> Program Terminated." << endl;
		output << string(47, '*') << endl;
		
		input.close();
		output.close();

		return 1;
	}
	if (grade1 < 0 || grade2 < 0 || grade3 < 0 || grade4 < 0) // if statement in case scores are negative
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << left << "==> Test scores read are: " << setw(6) << grade1 << setw(6) << grade2 << setw(6) << grade3 << setw(6) << grade4 << endl;
		cout << "==> One or more of the scores is negative!" << endl;
		cout << "==> Program Terminated." << endl;
		cout << string(47, '*') << endl;

		output << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		output << left << "==> Test scores read are: " << setw(6) << grade1 << setw(6) << grade2 << setw(6) << grade3 << setw(6) << grade4 << endl;
		output << "==> One or more of the scores is negative!" << endl;
		output << "==> Program Terminated." << endl;
		output << string(47, '*') << endl;

		input.close();
		output.close();

		return 1;
	}

	// declaring equation variables for output
	sum = (grade1 + grade2 + grade3 + grade4);
	average = (sum / 4.0);
	// variables being declared to be used in finding the variance
	float vari;
	float vari1;
	float vari2;
	float vari3;
	float vari4;

	vari1 = pow((grade1 - average), 2.0);
	vari2 = pow((grade2 - average), 2.0);
	vari3 = pow((grade3 - average), 2.0);
	vari4 = pow((grade4 - average), 2.0);
	vari = ((0.25) * (vari1 + vari2 + vari3 + vari4)); // variance

	float devi; // declaring deviation variable
	devi = sqrt(vari); // deviation

	// reading information line
	input.ignore();
	getline(input, section, '\n');

	if (input.fail()) // if statement in case the information line fails
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << "==> Reading of the information line failed." << endl;
		cout << "==> Input stream is in the fail state mode." << endl;
		cout << "==> There is an error in the input file." << endl;
		cout << "==> Program Terminated." << endl;
		cout << string(47, '*') << endl;

		output << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		output << "==> Reading of the information line failed." << endl;
		output << "==> Input stream is in the fail state mode." << endl;
		output << "==> There is an error in the input file." << endl;
		output << "==> Program Terminated." << endl;
		output << string(47, '*') << endl;

		return 1;

	}

	// beginning of output 

	output << string(17, '*') << "   Statistics   " << string(17, '*') << endl;
	output << left << setw(32) << section;
	output << setw(6) << grade1;
	output << setw(6) << grade2;
	output << setw(6) << grade3;
	output << setw(6) << grade4;


	output << endl << left << setw(32) << "The sum of the scores is:" << fixed << setprecision(2) << sum << endl;
	output << left << setw(32) << "The average of the scores is:" << fixed << setprecision(2) << average << endl;

	// testing for grade range below

	if (average >= 90)
	{
		output << left << setw(32) <<  "Letter grade equivalent:" << "A" << endl;
	}
	if (average >= 80 && average < 90)
	{
		output << left << setw(32) << "Letter grade equivalent:" << "B" << endl;
	}
	if (average >= 70 && average < 80)
	{
		output << left << setw(32) << "Letter grade equivalent:" << "C" << endl;
	}
	if (average >= 60 && average < 70)
	{
		output << left << setw(32) << "Letter grade equivalent:" << "D" << endl;
	}
	if (average < 60)
	{
		output << left << setw(32) << "Letter grade equivalent:" << "F" << endl;
	}

	// continuing output

	output << left << setw(32) << "The variance of the scores is:" << fixed << setprecision(2) << vari << endl;
	output << left << setw(32) << "The standard deviation is:" << fixed << setprecision(2) << devi << endl;
	output << string(50, '*') << endl;

	// closing files for safe data transfer
	input.close();
	output.close();
    //terminating program
	return 0;
	
 }
