// Final exam part 2
// Caleb Keller

float ReadIntValues()
{
	
int num = 0, count = 0;
float sum = 0, average = 0;

cout << "Please enter an integer" << endl;
cin >> num;
count ++;
sum += num;

while (num !=0)
{
	cout << "Please enter an integer" << endl;
	cin >> num; 
	count++;
	sum += num;
}

average = sum/count;
cout << "Sum is " << sum << endl;
cout << "The number of integers entered " << count << endl;
cout << "Average is " << average << endl;

return average;

}
