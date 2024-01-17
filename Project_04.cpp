//*******************************************
// Program Title: Project_04
// Project File: Project_04.cpp
// Name: Caleb Keller
// Course Section: CPE-211-01
// Lab Section: 03R
// Due Date: 02/12/21
// program description: Generates a custom password based on the user's inputs
// 
//*******************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string name; // first and last name
	string word1; // first word
	string word2; // second word
	string word3; // third word
	string Finit; // first initial of first name
	int place; // location of space between first and last name used to find first initial of last name
	string Linit; // last initial of last name
	string word1A; // word 1 first letter
	string word2A; // word 2 first letter
	string word3A; // word 3 first letter
	string word1B; // word 1 last letter
	string word2B; // word 2 last letter
	string word3B; // word 3 last letter
	int nlength; // length of first and last name including space
	float length1; // length of word 1
	float length2; // length of word 2
	float length3; // length of word 3
	float average; // average word length

	cout << endl;
	cout << string(60, '*') << endl; // title decor
	cout << setw(40) << "Password Generator" << endl; // title
	cout << string(60, '*') << endl; // title decor

	cout << "Enter user's first and last names separated by a space: ";
	getline(cin, name);
	cout << endl << "name = " << name << endl;

	cout << endl << "Enter the first word: ";
	cin >> word1; 
	cout << endl << "first word = " << word1 << endl;

	cout << endl << "Enter the second word: ";
	cin >> word2;
	cout << endl << "second word = " << word2 << endl;

	cout << endl << "Enter the third word: ";
	cin >> word3;
	cout << endl << "third word = " << word3 << endl;

	cout << endl << string(60,'*') << endl;
	
	nlength = name.length();
	
	Finit = name.substr(0, 1); // getting 1st initial of FIRST name and assigning to its own string
	place = name.find(' '); // finding the space between first and last name (allows us to find last name initial)
	Linit = name.substr(place + 1, 1); // getting 1st initial of LAST name and assigning it to its own string

	word1A = word1.substr(0, 1); // assigning first letter of word 1 to a string
	word2A = word2.substr(0, 1); // assigning first letter of word 2 to a string
	word3A = word3.substr(0, 1); // assigning first letter of word 3 to a string

	length1 = word1.length(); // finding length of word 1
	length2 = word2.length(); // finding length of word 2
	length3 = word3.length(); // finding length of word 3

	
	word1B = word1.substr(length1 - 1, 1);
	word2B = word2.substr(length2 - 1, 1);
	word3B = word3.substr(length3 - 1, 1);


	
	cout << setw(8) << left << "Word#"; // first column
	cout << setw(10) << left << "Length"; // second column
	cout << setw(20) << left << "Word" << endl; // third column

	cout << setw(8) << left << "-----"; // column decor
	cout << setw(10) << left << "------"; // column decor
	cout << setw(20) << left << "----" << endl; // column decor

	cout << setw(8) << left << "1"; // first row
	cout << setw(10) << left << length1;
	cout << word1 << endl;

	cout << setw(8) << left << "2"; // second row
	cout << setw(10) << left <<length2;
	cout << word2 << endl;

	cout << setw(8) << left << "3"; // third row
	cout << setw(10) << left << length3;
	cout << word3 << endl;

	cout << setw(8) << left << "-----"; // column decor
	cout << setw(10) << left << "------"; // column decor
	cout << setw(20) << left << "----" << endl << endl; // column decor


	average = ((length1 + length2 + length3) / 3);
	cout << "Average word length = " << fixed << showpoint << setprecision(2) << average << endl << endl;

	// ~~~~~password output below~~~~~~

	cout << "password = ";
	cout << Finit;
	cout << Linit;
	cout << nlength;
	cout << word1A;
	cout << word1B;
	cout << (int)length1; // type casting from float to int to remove decimal
	cout << word2A;
	cout << word2B;
	cout << (int)length2; // type casting from float to int to remove decimal
	cout << word3A;
	cout << word3B;
	cout << (int)length3 << endl; // type casting from float to int to remove decimal

	cout << string(60, '*') << endl << endl; // end of program decor



	
	
	system("PAUSE");
	





	





}
