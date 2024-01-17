//*******************************************
// Program Title: Project_08
// Project File: Project_08.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 03/28/2021
// program description: finds expired subscribers from an input file
//*******************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>

using namespace std;

//structures
struct subname // subscriber name 
{
	string fname; // first name
	string lname; // last name
	int custid; // customer id
};
struct address // subscriber's address
{
	string snn; // street number and name
	string city; // city
	string state; // state
	int zip; // zipcode
};
struct date 
{
	string month;  // month
	int day; // day
	int year; // year
};
struct rinfo // renewal info
{
	int mnum; // number of months left
	date notice; // date of last renewal notice sent using data structure
};
struct maininfo
{
	subname mubname; // subscriber name using subname structure
	address maddress; // address using address structure
	rinfo mrinfo; // renewal info using rinfo structure
};



void OPinfile(ifstream& infile, string& infilename); // function for opening input file
void OPoutfile(ofstream& outfile, string& outfilename); // function for opening output file
bool Readinfo(ifstream& infile, maininfo& m); // function for reading info from input file to the allocated structures
void Outinfo(ofstream& outfile, maininfo& m); // function for outputting info into output file


int main()
{
	ifstream infile;
	ofstream outfile;
	string infilename, outfilename;
    maininfo custinfo; // creating an object to act upon
	int subscribers=0; // number of subscribers
	int expired=0; // number of expired subscribers
	OPinfile(infile, infilename); // prompt user to enter input file name
	OPoutfile(outfile, outfilename); // prompt user to enter output file name
		
	if (infile.peek() == EOF)
	{
		cout << "===> Input file is empty.  Program terminated" << endl << endl;
		outfile << string(52, '-') << endl;
		outfile << "==> The input file does not contain any information." << endl;
		outfile << string(52, '-') << endl;
		infile.close(); // closes file for safe termination
		exit(1); // terminates program
	}
		

	while (!infile.eof())
	{


		while (Readinfo(infile, custinfo)) // read before testing for expired subscribers
		{
			subscribers++; // incrementing to count number of subscribers in a file


			if (custinfo.mrinfo.mnum == 0) // if subscription has 0 months left
			{

				Outinfo(outfile, custinfo); // print ONLY the expired subscriber ot output file

				expired++; // incrementing to count number of expired subscribers in a file
			}


		}
		
	}



	// indicate how many subscribers were in the file and how many are expired

	    cout << endl << string(47, '-') << endl;
		cout << "Number of subscribers processed: " << subscribers << endl;
		cout << "The number of expired subscriptions is: " << expired << endl;
		cout << string(47, '-') << endl << endl;


		infile.close(); // close the infile
		outfile.close(); // close the outfile
		infile.clear(); // clear the buffer 
}

// function for opening input file
void OPinfile(ifstream& infile, string& infilename)
{


	while (infile.good())
	{
		cout << endl << "Enter name of input file or Control-C to quit program: ";
		cin >> infilename;
		cout << infilename << endl << endl;

		infile.open(infilename.c_str());

		if (infile.fail())
		{
			cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
			cout << "==> Input file failed to open properly!!" << endl;
			cout << "==> Attempted to open file: " << infilename << endl;
			cout << "==> Please try again..." << endl;
			cout << string(47, '*') << endl;

			infile.clear();
		}
		else
		{
			break;
		}
	
	

	}

}

// function for opening output file
void OPoutfile(ofstream& outfile, string& outfilename)
{
	while (outfile.good())
	{

	cout << "Enter name of output file or Control-C to quit program: ";
	cin >> outfilename;
	cout << outfilename << endl << endl;

	outfile.open(outfilename.c_str());
	

	
		if (outfile.fail())
		{
			cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
			cout << "==> Output file failed to open properly!!" << endl;
			cout << "==> Attempted to open file: " << outfilename << endl;
			cout << "==> Please try again..." << endl;
			cout << string(47, '*') << endl << endl;

			outfile.clear();
		}
		else
		{
			break; // leaves while loop
		}

	}
}

bool Readinfo(ifstream& infile, maininfo& m) // function for pulling subscriber info from file
{
		infile.clear(); //clear buffer
		
	    // reading in subscriber info to subscriber structure 
		infile >> m.mubname.fname; // prime reading in the first name
		
	    if (infile.fail()) // testing file stream state
		{
			return false;
		}
		else
		{
			infile >> m.mubname.lname >> m.mubname.custid;
			infile.ignore(INT_MAX, '\n');

			// reading in address to address structure
			getline(infile, m.maddress.snn, '\n'); // gets street number and name
			
			getline(infile, m.maddress.city, '\n'); // gets city name
			
			getline(infile, m.maddress.state, '\n'); // gets state
			
			infile >> m.maddress.zip; // reads in zip code

			// reading in renewal info to rinfo structure
			infile.ignore(INT_MAX, '\n');
			infile >> m.mrinfo.mnum; // months left in subscription

			//reading in date to date structure
			infile.ignore(INT_MAX, '\n'); //ignore the new line and get next data from file
			getline(infile, m.mrinfo.notice.month, '\n');
			infile >> m.mrinfo.notice.day;
			infile.ignore(INT_MAX, '\n');
			infile >> m.mrinfo.notice.year;
			cout << "====> Processing Customer ID: " << m.mubname.custid << endl;

			return true;
		}			
			
			
}

void Outinfo(ofstream& outfile, maininfo& m)
{

	outfile << string(55, '*') << endl;
	outfile << m.mubname.fname << " " << m.mubname.lname << "(" << m.mubname.custid << ")" << endl;
	outfile << m.maddress.snn << endl;
	outfile << m.maddress.city << ", " << m.maddress.state << " " << m.maddress.zip << endl;
	outfile << "The last renewal notice was sent on " << m.mrinfo.notice.month << " " << m.mrinfo.notice.day << ", " << m.mrinfo.notice.year << endl;
	outfile << string(55, '*') << endl << endl;
}
