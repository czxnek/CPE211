/*
Program Title: Project_03
Project File: Project_03.cpp
Name: Caleb Keller
Course Section: CPE-211-01
Lab Section: 03R
Due Date: 02/05/21
Program Description: Calculates stock commission for buying/selling, the total cost,
the total return, the net profit or loss, and the profit tax/profit loss tax credit
for stock info entered.
************************************************************************************
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int numsh; // number of shares
	float buypr; // buy price per share
	float sellpr; // sell price per share
	string nstock; // name of stock

	cout << fixed << showpoint << setprecision(2);

	cout << endl; // extra space from top
	cout << string(25, '*') << endl; // header decor(*)
	cout << "Stock Calculations" << endl; // header title
	cout << string(25, '*') << endl << endl; //header decor(*)

	cout << "Enter the name of the stock: ";
	cin >> nstock; // user input
	cout << nstock << endl; // echo print

	cout << "Enter the number of shares purchased: ";
	cin >> numsh; // user input
	cout << numsh << endl; //echo print

	cout << "Enter the buy price per share: ";
	cin >> buypr; // user input
	cout << buypr << endl; // echo print

	cout << "Enter the sell price per share: ";
	cin >> sellpr; // user input
	cout << sellpr << endl << endl; // echo print

	cout << "Results for " << numsh << " shares of " << nstock << ":" << endl; // secondary header title
	cout << string(35, '-') << endl; // secondary header decor(*)

	cout << "Buy Commission......$" << numsh * buypr * 0.02 << endl; // broker commission for purchasing stock is (0.02 or 2%)
	cout << "Total Cost..........$" << numsh * buypr * 1.02 << endl; // multiplying by 1.02 to include the broker commission WITH the result, instead of adding 2% to the result 
	cout << "Sell Commission.....$" << sellpr * numsh * 0.015 << endl; // broker commission for selling stock is 1.5% or 0.015 of the return amount from selling the stock
	cout << "Total Return........$" << (sellpr * numsh) - (sellpr * numsh * 0.015) << endl; // total return is the return from the sale of the stock minus the sale commission paid
	cout << "Net Profit/Loss.....$" << (sellpr * numsh) - (sellpr * numsh * 0.015) - (numsh * buypr * 1.02) << endl; // total return minus the total cost of the purchase (if negative, it's a loss)
	cout << "Tax/Credit..........$" << ((sellpr * numsh) - (sellpr * numsh * 0.015) - (numsh * buypr * 1.02)) * 0.25 << endl; // 25% of net profit or loss
	cout << endl; // extra space from bottom 

	return 0;

}
