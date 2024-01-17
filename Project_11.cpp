//*******************************************
// Program Title: Project_11
// Project File: Project_11.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 04/25/2021
// program description: reads input file, counts each character, and prints out a grid with the totals of each character
//*******************************************

#include<iomanip>
#include<string>
#include<iostream>
#include<fstream>
#include<climits>
#include<cstdlib>
#include<cctype>

using namespace std;
void infiletest(ifstream& infile, string& infilename);
void printHeading(int lower, int upper, int digits, int punct, int spaces, int other, int i, int total);



int main()
{
	ifstream infile;
	ofstream outfile;

	string infilename;

	infiletest(infile, infilename); // calls for file test function
	//infile.open(infilename.c_str());

	if (infile.peek() == infile.eof())
	{
		cout << string(13, '*') << " Input File is Empty " << string(13, '*') << endl;
		cout<< "==> The input file is empty." << endl;
		cout << "==> Terminating the program." << endl;
		cout << string(47, '*') << endl;
		infile.close(); // closes file for safe termination
		exit(1); // terminates program
	}                      
	
	char ch; // used to store the character read from file
	infile.get(ch); // priming read
	int lower = 0, upper = 0, character = 0, integer = 0, space = 0, punct = 0, other = 0, total = 0, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0, total7 = 0, i = 1, percent = 0;
	int percent2 = 0, percent3 =0,percent4 =0, percent5 =0, percent6 =0,percent7 = 0;
	string data;
	cout << left << setw(15) << "Line number" << setw(10) << "Upper" << setw(10) << "Lower" << setw(10) << "Digits" << setw(10) << "Punct" << setw(10) << "Spaces" << setw(10)
		<< "Other" << setw(10) << "Total" << endl;
	cout << setw(15) << "-----------" << setw(10) << "-----" << setw(10) << "-----" << setw(10) << "------" << setw(10) << "-----" << setw(10) << "------" << setw(10) << "-----"
		<< setw(10) << "-----" << endl;
	while (!infile.eof())
	{
		while(getline(infile, data)) // read data line by line
		
		{
			data.substr(1,ch);
			infile.get(ch);

			if (ch >= 65 && ch <= 90)  // using ASCII values
			{
				upper++;
				total1++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total1);

			}
			else if (ch >= 97 && ch <= 122) // using ASCII values
			{
				lower++;
				total2++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total2);

			}
			else if (ch >= 48 && ch <= 57)// using ASCII values
			{
				integer++;
				total3++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total3);

			}
			else if (ch == ' ') // using ASCII values
			{
				space++;
				total4++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total4);
			}
			else if (ispunct(ch))
			{
				punct++;
				total5++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total5);
			}
			else if(ch == '\n') // count the new line character
			{
				other++;
				total6++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total6);
			}	
			else
			{
				other++;
				total6++;
				i++;
				printHeading(lower, upper, integer, punct, space, other, i, total6);
			
			}

			total = total1 + total2 + total3 + total4 + total5 + total6;

					


			
		}			
		percent = ((total1 / total) * 100);

		percent2 = ((total2 / total) * 100);

		percent3 = ((total3 / total) * 100);

		percent4 = ((total4 / total) * 100);

		percent5 = ((total5 / total) * 100);

          percent6 = ((total6 / total) * 100);
	}		
        	cout << string(80, '-') << endl; // prints 80 dashes

            cout << setw(15) << "Totals"  << setw(10) << total1 << setw(10) << total2 << setw(10) << total3 << setw(10) << total4 << setw(10) << total5 << setw(10) << total6 << setw(10) << total << endl;
			cout << setw(15) << "Percent" << setw(10) <<  percent << setw(10) << percent2 << setw(10) << percent3 << setw(10) << percent4 << setw(10) << percent5 << setw(10) << percent6 << endl;
		
	
	infile.close();

}

void infiletest(ifstream& infile, string& infilename) // testing to make sure file is opened correctly
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

void printHeading(int lower, int upper, int digits, int punct, int spaces, int other, int i, int total)
{
	
		
		
		cout << left << setw(15) << i << setw(10) << upper << setw(10) << lower << setw(10) << digits << setw(10) << punct << setw(10) << spaces << setw(10) << other << setw(10) << total << endl;
	
}
