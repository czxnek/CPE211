//*******************************************
// Program Title: Project_09
// Project File: Project_09.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 04/11/2021
// program description: Computes Boolean algebra results of OR, AND. and XOR of 2 two-dimensional arrays of binary digits
//*******************************************


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

struct logic // structure to hold AND, OR, and XOR values
{
	float OR;
	float AND;
	float XOR;
};

const int ROW = 10; 
const int COL = 10;
typedef int array1[ROW][COL];
typedef int array2[ROW][COL]; // typedef for both arrays 
// AND OR XOR ARRAYS
typedef int arrayAND[ROW][COL];
typedef int arrayOR[ROW][COL];
typedef int arrayXOR[ROW][COL];

// FUNCTIONS
void openInfile(ifstream&, string&);
void readData1(ifstream&, array1 arrayA, int rowNUM, int colNUM);
void readData2(ifstream& infile, array2 arrayB, int rowNUM, int colNUM);
void printInput(array1 arrayA, array2 arrayB, int rowNUM, int colNUM);

void calcAND( array1 arrayA, array2 arrayB, arrayAND arrayAND2, int rowNUM, int colNUM);
void calcOR(array1 arrayA, array2 arrayB, arrayOR arrayOR2, int rowNUM, int colNUM);
void calcXOR(array1 arrayA, array2 arrayB, arrayXOR arrayXOR2, int rowNUM, int colNUM);

int calcIntOR(int row, arrayAND arrayAND2, int rowNUM, int colNUM);
int calcIntAND(int row, arrayAND arrayAND2, int rowNUM, int colNUM);
int calcIntXOR( int row, arrayXOR arrayXOR2, int rowNUM, int colNUM);

void printGATES(arrayAND arrayAND2, arrayOR arrayOR2, arrayXOR arrayXOR2, int rowNUM, int colNUM);
//void printDecimalValues(arrayAND arrayAND2, arrayOR arrayOR2, arrayXOR arrayXOR2, int rowNUM, int colNUM);




int main()
{
	ifstream infile;
	ofstream outfile;
	string infilename, outfilename;
	logic gatetype; // struct object to act upon
	array1 ARRAY1; // relating array1 to inside of main for function use
	array2 ARRAY2;  // relating array2 to inside of main for function use
	
	//relating AND OR XOR arrays for function use
	arrayAND ANDarr;
	arrayOR ORarr;
	arrayXOR XORarr;

	int rowNUM; // number of rows from input file
	int colNUM; // number of columns from input file
	string space;


	openInfile(infile, infilename); // prompts for function to open input file

	infile >> rowNUM; // getting first integer from file  which is the row amount

	infile.ignore(INT_MAX, '\n'); // ignores the words and new line

	infile >> colNUM; // getting second integer from file which is the column value

	infile.ignore(INT_MAX, '\n'); // this ignores the spaces between the function

	getline(infile, space); // gets the line of empty space

	readData1(infile, ARRAY1, rowNUM, colNUM); // prompts for reading function to get matrixes from file
	
	getline(infile, space); // gets the line of empty space

	readData2(infile, ARRAY2, rowNUM, colNUM); // prompts for reading function to get matrixes from file

	// beginning of cout

	printInput(ARRAY1, ARRAY2, rowNUM,colNUM); // print to the terminal
	
	calcOR(ARRAY1, ARRAY2 , ORarr, rowNUM, colNUM);
	calcAND(ARRAY1, ARRAY2,ANDarr,rowNUM,colNUM);
	calcXOR(ARRAY1, ARRAY2, XORarr, rowNUM, colNUM);
	printGATES(ANDarr, ORarr, XORarr, rowNUM, colNUM);

	int resOR, resAND, resXOR;

	//use a loop calling these functions that print 1 line at a time to get all the results
	
	// field width set to 14
	cout << "Integer Equivalents for the rows" << endl << "of the OR, AND and XOR arrays" << endl;
	cout << string(32, '-') << endl;
	cout << setw(8) << left << "OR" << setw(8) << "AND" << setw(8) << "XOR" << endl;
	cout << setw(8) << left << "--" << setw(8) << "---" << setw(8) << "---" << endl;
	

	for(int row=0;row<rowNUM;row++)
	{
		resOR = calcIntOR(row, ORarr, rowNUM, colNUM); // how do i increment these?
		resAND = calcIntAND(row, ANDarr, rowNUM, colNUM);
		resXOR = calcIntXOR(row, XORarr, rowNUM, colNUM);


			// print out a row from arrayAND2
			cout << setw(8) << left << resOR;

		

			// print out a row from arrayOR2

			cout << setw(8) << left << resAND;
	

			// print out a row from arrayXOR2
			cout << setw(8) << left << resXOR;


			// terminate the current row
			cout << endl;
			

	}
	
}

void openInfile(ifstream& infile, string& infilename) // function for opening input file
{
	while (infile.good())
	{
		cout << endl << "Enter the name of the input file: ";
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

void readData1(ifstream& infile, array1 arrayA, int rowNUM, int colNUM) // fill in the 10 with the 2 numbers that tells you the size
{
	int row, col; // loop index values used to pull binary from input file

    for (row = 0; row < rowNUM; row++) // for loop to grab binary values 
	{
		for (col = 0; col < colNUM; col++)
		{
			infile >> arrayA[row][col]; // read in data from file
		}
	}

}
void readData2(ifstream& infile, array2 arrayB, int rowNUM, int colNUM) // fill in the 10 with the 2 numbers that tells you the size
{
	int row, col; // loop index values used to pull binary from input file

	for (row = 0; row < rowNUM; row++) // for loop to grab binary values 
	{
		for (col = 0; col < colNUM; col++)
		{
			infile >> arrayB[row][col]; // read in data from file
		}
	}
}

void calcAND( array1 arrayA, array2 arrayB, arrayAND arrayAND2, int rowNUM, int colNUM)
{ 
	int row, col;
	for (row = 0; row < rowNUM; row++)
	{
		for (col = 0; col < colNUM; col++)
		{
		
			if (arrayA[row][col] == 1 && arrayB[row][col] == 1)
			{
				arrayAND2[row][col] = 1;

			}
			else
			{
				arrayAND2[row][col] = 0;
			}
		}
	}
}

void calcOR( array1 arrayA, array2 arrayB, arrayOR arrayOR2, int rowNUM, int colNUM)
{
	int row, col;

	for (row = 0; row < rowNUM; row++)
	{
		for (col = 0; col < colNUM; col++)
		{
			if (!(arrayA[row][col] == 0 && arrayB[row][col] == 0)) // they both cannot be 0
			{
				arrayOR2[row][col] = 1;
			}
			else // they are both 0
			{
				arrayOR2[row][col] = 0;
			}
		}
	}

}

void calcXOR( array1 arrayA, array2 arrayB, arrayXOR arrayXOR2, int rowNUM, int colNUM)
{
	int row, col;

	for (row = 0; row < rowNUM; row++)
	{
		for (col = 0; col < colNUM; col++)
		{
			if ((arrayA[row][col] == 0 && arrayB[row][col] == 1)|| (arrayA[row][col] == 1 && arrayB[row][col] == 0)) // they both cannot be 0
			{
				arrayXOR2[row][col] = 1;
			}
			else // they are both 0
			{
				arrayXOR2[row][col] = 0;
			}
		}
	}
}

void printInput(array1 arrayA, array2 arrayB, int rowNUM, int colNUM) // at this point we have all our data read into our arrays
{
	// field width set to 14
	cout << "Initial values of the arrays processed" << endl;
	cout << string(38, '-') << endl;
	cout << setw(2 * colNUM) << left << "Array 1" << "    " << setw(2 * colNUM) << "Array 2" << endl;
	cout << setw(2 * colNUM) << left << "-------" << "    " << setw(2 * colNUM) << "-------" << endl;

	int row, col; // loop index values used to pull binary from input file
	for (row = 0; row < rowNUM; row++)
	{
		// print out a row from arrayA
		for (col = 0; col < colNUM; col++)
			cout << setw(2) << left << arrayA[row][col];

		// print out 4 spaces betwwen the two grids
		cout << setw(4) << left << " ";

		// print out a row from arrayB
		for (col = 0; col < colNUM; col++)
			cout << setw(2) << left << arrayB[row][col];

		// terminate the current row
		cout << endl;
	}
	cout << endl;
}

void printGATES(arrayAND arrayAND2, arrayOR arrayOR2, arrayXOR arrayXOR2, int rowNUM, int colNUM)
{
	// field width set to 14
	cout << "OR, AND and XOR results" << endl;
	cout << string(23, '-') << endl;
	cout << setw(2 * colNUM) << left << "OR" << "    " << setw(2 * colNUM) << "AND" << "    " << setw(2 * colNUM) << "XOR" << endl;
	cout << setw(2 * colNUM) << left << "--" << "    " << setw(2 * colNUM) << "---" << "    " << setw(2 * colNUM) << "---" << endl;

	int row, col; // loop index values used to pull binary from input file
	for (row = 0; row < rowNUM; row++)
	{
		// print out a row from arrayAND2
		for (col = 0; col < colNUM; col++)
			cout << setw(2) << left << arrayOR2[row][col];

		// print out 4 spaces betwwen the two grids
		cout << setw(4) << left << " ";

		// print out a row from arrayOR2
		for (col = 0; col < colNUM; col++)
			cout << setw(2) << left << arrayAND2[row][col];

		// print out 4 spaces betwwen the two grids
		cout << setw(4) << left << " ";

		// print out a row from arrayXOR2
		for (col = 0; col < colNUM; col++)
			cout << setw(2) << left << arrayXOR2[row][col];


		// terminate the current row
		cout << endl;
	}
	cout << endl << endl;
}
//void printDecimalValues(arrayAND arrayAND2, arrayOR arrayOR2, arrayXOR arrayXOR2, int rowNUM, int colNUM) // this overrides the values in the previous array
//{
//
//	// field width set to 14
//	cout << "Integer Equivalents for the rows" << endl << "of the OR, AND and XOR arrays" << endl;
//	cout << string(23, '-') << endl;
//	cout << setw(2 * colNUM) << left << "OR" << "    " << setw(2 * colNUM) << "AND" << "    " << setw(2 * colNUM) << "XOR" << endl;
//	cout << setw(2 * colNUM) << left << "--" << "    " << setw(2 * colNUM) << "---" << "    " << setw(2 * colNUM) << "---" << endl;
//
//	int row, col; // loop index values used to pull binary from input file
//	for (row = 0; row < rowNUM; row++)
//	{
//		// print out a row from arrayAND2
//		for (col = 0; col < colNUM; col++)
//			cout << left << arrayOR2[row][col];
//
//		// print out 4 spaces betwwen the two grids
//		cout << setw() << left << " ";
//
//		// print out a row from arrayOR2
//		for (col = 0; col < colNUM; col++)
//			cout << setw(2) << left << arrayAND2[row][col];
//
//		// print out 4 spaces betwwen the two grids
//		cout << setw(4) << left << " ";
//
//		// print out a row from arrayXOR2
//		for (col = 0; col < colNUM; col++)
//			cout << setw(2) << left << arrayXOR2[row][col];
//
//
//		// terminate the current row
//		cout << endl;
//	}
//	cout << endl << endl;
//}
// [4] = 2^0, [3]=2^1, [2]=2^2, [1]=2^3, [0]=2^4





int calcIntOR(int row, arrayOR arrayOR2, int rowNUM, int colNUM)
{
	int  col; // loop index values used to pull binary from input file
	int base = 1;
	int result=0;
	
	for (col = colNUM - 1; col >= 0; col--)
	{
		result += base * arrayOR2[row][col];
		base *= 2;
	}
	return result;
	
}

int calcIntAND(int row , arrayAND arrayAND2, int rowNUM, int colNUM)
{
	int col; // loop index values used to pull binary from input file
	int base = 1;
	int result = 0;
	
	for (col = colNUM - 1; col >= 0; col--)
	{
		result += base * arrayAND2[row][col];
		base *= 2;
		
	}
	return result;
     
	

}
int calcIntXOR(int row, arrayXOR arrayXOR2, int rowNUM, int colNUM)
{
	int  col; // loop index values used to pull binary from input file
	int base = 1;
	int result = 0;
	
	for (col = colNUM - 1; col >= 0; col--)
	{
		result += base * arrayXOR2[row][col];
		base *= 2;
		
	}
	return result;
	
}
//make sure these comparisons are in a double for loop to read the values




		// ADDING
/*
if ((arrayA[row][col] + arrayB[row][col]) = 0)
{
	arrayAND[row][col] = 0;
	arrayOR[row][col] = 0;
	arrayXOR[row][col] = 0;
}
if ((arrayA[row][col] + arrayB[row][col]) = 1)
{
	arrayAND[row][col] = 0;
	arrayOR[row][col] = 1;
	arrayXOR[row][col] = 1;
}
if ((arrayA[row][col] + arrayB[row][col]) = 2)
{
	arrayAND[row][col] = 1;
	arrayOR[row][col] = 1;
	arrayXOR[row][col] = 0
}
*/
