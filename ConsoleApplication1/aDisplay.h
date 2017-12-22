#include <iostream>
#include <string>
using namespace std;

void lineOfStars(int x)
{
	if (x == 1)
	{
		cout << "*";
	}

	else
	{
		cout << "*";
		lineOfStars(x - 1);
	}
}

void stars(int n)
{
	if (n == 0)
	{
	}

	else
	{
		lineOfStars(n);
		cout << endl;

		stars(n - 1);
		lineOfStars(n);
		cout << endl;
	}
}




void display()
{
	cout << "*magical sounds*" << endl;


	for (int a = 0; a < 2; a++) {
		cout << "* + * + * + * + * + * + * + * + * + * + *" << endl;
		cout << "			* + * + * + * + * + * + * + * + * + * + * " << endl;
	}

	stars(3);
	stars(2);
	stars(1);

	for (int a = 0; a < 2; a++) {
		cout << "* + * + * + * + * + * + * + * + * + * + *" << endl;
		cout << "			 * + * + * + * + * + * + * + * + * + * + * " << endl;
	}

	cout << endl << "*wish granted* " << endl << endl << endl;

	cout << "you can go back to texas now" << endl;
}

void Athena()
{
	cout << endl << endl << endl << endl;
	cout << "* + * + * + * + * + * + * + * + A T H E N A ' S   T E M P L E * + * + * + * + * + * + * +" << endl << endl;

	string wish;
	cout << "I've heard you've come all the way here just to see me...";
	cout << "you have a wish you want to make that only I can grant, so tell me ";
	cout << "what's your wish? " << endl;
	cout << "wish: ";
	cin >> wish;
	cout << endl;
	cout << "That's a lovely wish, I shall make it come true! " << endl << endl;

	display();
}