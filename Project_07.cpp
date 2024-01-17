//*******************************************
// Program Title: Project_07
// Project File: Project_07.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 03/16/2021
// program description: menu prompts the user to compress/decompress a file
//*******************************************

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<climits>

using namespace std;

void menu(); // prototype for the menu function
bool choice(int& c); // function for menu choice
void OPinfile(ifstream& infile, string& infilename); // function for opening input file
void OPoutfile(ofstream& outfile, string& outfilename); // function for opening output file
void compress(ifstream& infile, ofstream& outfile); // function for compression
void decompress(ifstream& infile, ofstream& outfile); // function for decompression

int main()
{
	int c=0; // selection from menu
	ifstream infile; // declaration for input file
	ofstream outfile; // declaration for output file
	string infilename; // name of input file 
	string outfilename; // name of output file
	bool endLoop; 
	endLoop = false;



	while (!endLoop)
	{
		menu(); // prompts menu
		bool validchoice = choice(c); //catches return boolean value

		if (c == 1)
		{
			OPinfile(infile, infilename); // calling input file function
			OPoutfile(outfile, outfilename); // calling output file function

			while (infile.fail())
			{
				cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
				cout << "==> Input file failed to open  properly!!" << endl;
				cout << "==> Attempted to open file: " << infilename << endl;
				cout << "==> Selected operation has been canceled" << endl;
				cout << string(47, '*') << endl << endl;

				menu(); // prompts for menu again
				break;
			}

			compress(infile, outfile); // begins compression
			menu();
			choice(c);
		}
		else if (c == 2)
		{
			OPinfile(infile, infilename); // calling input file function
			OPoutfile(outfile, outfilename); // calling output file function

			while (infile.fail())
			{
				cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
				cout << "==> Input file failed to open  properly!!" << endl;
				cout << "==> Attempted to open file: " << infilename << endl;
				cout << "==> Selected operation has been canceled" << endl;
				cout << string(47, '*') << endl << endl;

				menu(); // prompts for menu again
				break;
			}

			decompress(infile, outfile); // begins decompression
			menu();
			choice(c);
		}
		return 0;
	}

	infile.close(); // closing filestreams
	outfile.close();

	

}

// function for menu prompt
void menu() // prompts a menu for user to select between 3 options
{
	cout << string(10, '*') << "  Compression Menu  " << string(10, '*') << endl;
	cout << "0. Exit Program" << endl;
	cout << "1. Compress File" << endl;
	cout << "2. Uncompress File" << endl;
	cout << string(40, '*') << endl << endl;
}

// function for menu choice
bool choice(int& c) // user enters in their choice 0, 1, or 2
{
	bool validc; // flag value to be returned indicating read status
	char ch; // test for invald input 

	validc = false; // initialize flag for an invalid value entered
	do {
		cout << "Input your selection now: ";
		cin >> c; 

		if (cin.fail()) //an integer is not entered
		{
			cin.clear(); // clear input stream
			cin >> ch; // read incorrect character
			cout << ch << endl; // echo printing the invalid character 


			cout << string(14, '*') << " Invalid Selection " << string(14, '*') << endl;
			cout << "==> Invalid character entered!!" << endl;
			cout << "==> Please enter 0, 1  or 2" << endl;
			cout << string(47, '*') << endl << endl;

			cout << string(10, '*') << "  Compression Menu  " << string(10, '*') << endl;
			cout << "0. Exit Program" << endl;
			cout << "1. Compress File" << endl;
			cout << "2. Uncompress File" << endl;
			cout << string(40, '*') << endl << endl;

		}
		else if (c == 0 || c == 1 || c == 2) // if correct choice is entered
		{
			validc = true; // changes to true
			cout << c << endl << endl; // echo print
			
			if (c == 0)
			{
				cout << "Quit Selected.  Terminating program now..." << endl << endl;
				exit(1);
			}
		}
		else
		{
			// error for any integer value beside 0, 1, or 2 entered
			cout << c << endl;
			cout << string(14, '*') << " Invalid Selection " << string(14, '*') << endl;
			cout << "==> Invalid integer value entered" << endl;
			cout << "==> Please enter 0, 1  or 2" << endl;
			cout << string(47, '*') << endl << endl;

			cout << string(10, '*') << "  Compression Menu  " << string(10, '*') << endl;
			cout << "0. Exit Program" << endl;
			cout << "1. Compress File" << endl;
			cout << "2. Uncompress File" << endl;
			cout << string(40, '*') << endl << endl;
		}
	} while (validc == false);
	cin.ignore(INT_MAX, '\n'); //ignores everything until a new-line character is reached
	return validc;
}

// function for opening input file
void OPinfile(ifstream& infile, string& infilename)
{
	cout << "Enter the name of the input file: ";
	cin >> infilename;
	cout << infilename << endl << endl;

	infile.open(infilename.c_str());

}

// function for opening output file
void OPoutfile(ofstream& outfile, string& outfilename)
{
	cout << "Enter in the name of the output file: ";
	cin >> outfilename;
	cout << outfilename << endl << endl;

	outfile.open(outfilename.c_str());
}

// function for compression

void compress(ifstream& infile, ofstream& outfile)
{
	char ch,temp; // characters read from input file
	

	infile.get(ch); //priming read in first character of the file
  
	while (!infile.eof())  // until end of file
	{


		if (infile.fail())
		{
			cout << string(15, '*') << " Empty Input File " << string(15, '*') << endl;
			cout << "==> Empty file for Compression" << endl;
			cout << "==> Nothing written to the output file" << endl << endl;

			infile.clear(); // clearing for next use

		}
		else
		{

			int counter = 1; // counts amount of times letter appears

			temp = ch; //assign first character to previous character

			infile >> ch;

			while (ch == temp && infile.good())
			{

				counter++;
				infile.get(ch);

			}
			if (counter == 1) //if no duplicates are found we know we need to add a newline 
			{
				outfile << "\n";
			}
			else
			{
				outfile << counter << temp;
			}

			
		}

	
	}

	cout << "==> File has been Compressed" << endl << endl;
	//close I / O files
	infile.close();
	outfile.close();
}

// function for decompress
void decompress(ifstream& infile, ofstream& outfile)
{
	char ch, temp; // characters read from input file and temporary variable
	int counter; // counts amount of times letter appears
	int num=0; // amount of each letter from compressed file

	
	infile >> num; //reads in number until it encounters something that is not an integer

	while (!infile.eof())
	{
		if (infile.fail())
		{
			cout << string(15, '*') << " Empty Input File " << string(15, '*') << endl;
			cout << "==> Empty file for Decompression" << endl;
			cout << "==> Nothing written to the output file" << endl << endl;
			infile.clear(); // clearing for next use
			outfile.clear();
		}
		else
		{

			infile.get(ch);

			outfile << string(num, ch);

			infile >> num;

		}

	}

	cout << "==> File has been Decompressed" << endl << endl;
}