#include <cmath>
#include <time.h>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void results(int numG, int x, bool &a, int &lives) 
{

		// If the user's guess is too high or too low, the program asks the user to try again
		if (numG == x) {
			cout << "Okay, you've won" << endl;
			a = false;
		}

		else if (numG > x) {
			cout << "You're too high" << endl;
			lives--;
			cout << "You currently have " << lives << " lives" << endl;
		}
		else {
			cout << "You're too low" << endl;
			lives--;
			cout << "You currently have " << lives << " lives" << endl;
		}
	}

void random(int num2, int num1, int &lives)
{
	bool tru = true;

	srand(time(NULL));
	int r = rand() % ((num2 - num1) + 1) + num1;

	while (tru != false && lives!= 0) {

		// Ask the user to guess the number
		int inputNum;
		cout << "Guess a number from " << num1 << " to " << num2 << endl;
		cin >> inputNum;

		// Check user's answer, if the user is right, the game ends
		results(inputNum, r, tru, lives);
	}
}