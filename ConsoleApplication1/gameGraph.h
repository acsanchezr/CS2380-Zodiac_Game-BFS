#include "directedGraph.h"
#include "randomFunc.h"
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

class gameGraph : public directedGraph
{
private:	
	vertex * playerL; //where player currently is
	int lives = 10;
public:

	void setPlayerLocation(string place)
	{
		playerL = findVertex(place);
	}

	string getPlayerLocation()
	{
		return playerL->data;
	}
	

	bool travelTo(string destination)
	{
		for (int i = 0; i < playerL->neighbors.size(); i++)
		{
			if (destination == playerL->neighbors[i]->data)
			{
				playerL = playerL->neighbors[i];
				return true;
			}
		}

		return false;
	}

	//tell player what the shortest path is
	void breadthFirstSearch(string location, string des)
	{
		queue <vertex*>q;

		vertex *s = findVertex(des);
		vertex *playerVertex1 = findVertex(location);
		//cout << "vertices to false begin" << endl;
		//sets all the vertices to not visited
		for (int i = 0; i < vertexList.size(); i++)
		{
			vertexList[i]->visited = false;
			for (int j = 0; j < vertexList[i]->neighbors.size(); j++)
			{
				vertexList[i]->neighbors[j]->visited = false;
			}
		}
		//cout << "vertices to false done" << endl;
		//set the current location as true & enqueue
		playerVertex1->visited = true;
		q.push(playerVertex1);

		//dequeue current location and enqueue its neighbors
		//cout << "empty while loop" << endl;
		while (!q.empty())
		{
			vertex* front = q.front();
			q.pop();
			//cout << "enqueing neighbors begin" << endl;
			for (int j = 0; j < front->neighbors.size(); j++)
			{
				if (!front->neighbors[j]->visited)
				{
					q.push(front->neighbors[j]);
					front->neighbors[j]->visited = true;
					front->neighbors[j]->pred = front;
				}
			}
		}
		//cout << "enqueing neighbors done" << endl;

		vertex * path = s;
		stack<vertex*>print;

		//cout << "pushing predecessors begin" << endl;
		while (path != playerVertex1)
		{
			print.push(path->pred);
			path = path->pred;
		}
		//cout << "pushing predecessors done" << endl;
		//cout << "printing predecessors begin" << endl;

		while (!print.empty())
		{
			vertex *p = print.top();
			cout << p->data << ", ";
			print.pop();
		}
		//cout << "printing predecessors done" << endl;
	}

	void reducePLives()
	{
		lives = lives - 1;
	}

	void displayPLives()
	{
		cout << "You currently have " << lives<< " lives" << endl;
	}



	// LET DA GAME BEGIIIIIIIIINNNNNNNNNNNNNNNN TEMPLESSSSSSSSSSSSSSSSS YAAAAAAAAASSSSSSSSSSSSSSSSSSSSS
	//♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡. ♡.

	void begin(string place)
	{
		if (lives == 0 || place == "Athena") {
			if (lives == 0)
			{
				cout << "Game over... too bad " << endl;
			}

			else if (place == "Athena")
			{
			}
		}
		else
		{
		//ARIES TEMPLE
			if (place == "Aries")
			{
				cout << "* * *" << " A R I E S "  << "* * *" << endl;
				cout << "This is the Aries temple.";
				cout << "I understand why you're here, so I'll let you through without fighting. " << endl;
				cout << "But before you go on, I'd like for you to know some basic things ";
				cout << "The shortest path you can follow to get to Athena is ";
				breadthFirstSearch(playerL->data, "Athena");
				cout << endl;
				cout << "Also, right now you have " << lives << " lives, but they will decrease whenever you lose to a guardian. ";
				cout << "You can get more lives at the Sagittarius temple. ";
				cout << endl;
				cout << "In order to defeat each guardian, you must answer what they ask you. ";
				cout << endl << "You may go to the Taurus temple, good luck! (Enter)" << endl;

				cin.ignore();
				setPlayerLocation("Taurus");
				begin(getPlayerLocation());
			}

		//TAURUS TEMPLE
			else if (place == "Taurus")
			{
				string enter;
				cout << "* * *" << " T A U R U S " << "* * *" << endl;
				char answer;
				cout << endl;
				cout << "Ooooh! what do we have here? an intruder? and you want to see Athena? ";
				cout << endl << "Ha! First you'll have to answer my questions! " << endl;
				cout << "Listen, in the Orpheus and Eurydice myth, what is the instrument that Orpheus plays? " << endl;
				cout << "a) lyre		b) harp		c) flute" << endl;
				cout << "Answer: ";
				cin >> answer;

				if (answer == 'a')
				{
					cout << "Wow! you passed the test on the first try! You may go to the Leo temple" << endl << endl;
					setPlayerLocation("Leo");
					begin(getPlayerLocation());
				}

				else
				{
					while (answer != 'a' && lives != 0)
					{
						cout << "oops, try again! ";
						reducePLives();
						displayPLives();
						cout << "Listen, in the Orpheus and Eurydice myth, what is the instrument that Orpheus plays? " << endl;
						cout << "a) lyre		b) harp		c) flute" << endl;
						cout << "Answer: ";
						cin >> answer;
					}

					if (lives == 0)
					{
						cout << "You died!";
						begin(getPlayerLocation());
					}

					else
					{
						cout << "You may go to the Gemini temple" << endl << endl;
						setPlayerLocation("Gemini");
						begin(getPlayerLocation());
					}
				}
			}

		//GEMINI TEMPLE
			else if (place == "Gemini")
			{

				cout << "* * *" << " G E M I N I " << "* * *" << endl;
				char ans;
				cout << "You've reached the third temple, if you wish to continue, you'll have to answer my questions" << endl;

				cout << "What's the big-Oh run time of binary search? " << endl;
				cout << "a) O(n log n)		b) O(log n)		c) O(n) " << endl << "Answer: ";
				cin >> ans;

				while (ans != 'b' && lives != 0)
				{
					cout << "Wrong, try again " << endl;
					reducePLives();
					displayPLives();
					cout << "What's the big-Oh run time of binary search? " << endl;
					cout << "a) O(n log n)		b) O(log n)		c) O(n) " << endl;
					cin >> ans;
				}
				if (lives == 0)
				{
					cout << "You died!";
					begin(getPlayerLocation());
				}

				else
				{
					cout << "You can leave to the Cancer temple " << endl << endl;
					setPlayerLocation("Cancer");
					//cin.ignore();
					begin(getPlayerLocation());
				}
			}

		//CANCER
			else if (place == "Cancer")
			{

				cout << "* * *" << " C A N C E R " << "* * *" << endl;
				char ans;
				cout << "Welcome to the 4th temple! if you want to keep going, then listen: " << endl;
				cout << "In a binary search tree, how do you call a node that has no children? " << endl;
				cout << "a) single		b) leaf		c) branch";
				cout << endl << "Answer: ";
				cin >> ans;
				
				while (ans != 'b' && lives != 0)
				{
					cout << "Wrong answer lol " << endl;
					reducePLives();
					displayPLives();
					cout << "In a binary search tree, how do you call a node that has no children? " << endl;
					cout << "a) single		b) leaf		c) branch";
					cout << endl << "Answer: ";
					cin >> ans;
				}
				if (lives == 0)
				{
					cout << "You died!";
					begin(getPlayerLocation());
				}

				else
				{
					cout << "You are free to go " << endl << endl;
					setPlayerLocation("Leo");
					begin(getPlayerLocation());
				}
			}
			
		//LEO 
			else if (place == "Leo")
			{
				char ans;
				cout << "* * *" << " L E O " << "* * *" << endl;

				cout << "Welcome to my temple, if you answer correctly to my question on the first try, ";
				cout << "I'll let you go to the Libra temple" << endl;
				cout << "Here's my question: ";
				cout << "what Greek hero is known for having his heel as a weakness? " << endl;
				cout << "a) Aristotle			b) Oedipus			c) Achilles" << endl;
				cout << "Answer: ";
				cin >> ans;

				if (ans == 'c')
				{
					cout << "You're good, I'll let you take the shortcut, you may go to Libra's temple " << endl << endl;
					setPlayerLocation("Libra");
					begin(getPlayerLocation());
				}
				else
				{
					while (ans != 'c' && lives != 0)
					{
						cout << "Not the right option ";
						reducePLives();
						displayPLives();
						cout << "what Greek hero is known for having his heel as a weakness? " << endl;
						cout << "a) Aristotle			b) Oedipus			c) Achilles" <<endl<< "Answer; ";
						cin >> ans;
					}

					if (lives == 0)
					{
						cout << "You died!" << endl;
						begin(getPlayerLocation());
					}

					else
					{
						cout << "Continue to the Virgo temple" << endl << endl;
						setPlayerLocation("Virgo");
						begin(getPlayerLocation());
					}
				}
			}

			
		//VIRGO 
			else if (place == "Virgo")
			{
				cout << "* * *" << " V I R G O " << "* * *" << endl;
				cout << "I'm surprised you've made it this far, but it won't be that easy going to the next temple " << endl;
				
				random(20,0,lives);

				if (lives == 0)
				{
					cout << "You died!" << endl;
					begin(getPlayerLocation());
				}

				else {
					cout << "Guess I'll have no other option but to let you continue, the next temple is ";
					cout << "the libra temple. " << endl << endl;
					setPlayerLocation("Libra");
					begin(getPlayerLocation());
				}
			}

		//LIBRA
			else if (place == "Libra")
			{
				char ans;
				cout << "* * *" << " L I B R A " << "* * *" << endl;
				cout << "..?! Huh!? Wow! I never thought someone would be able to get here! ";
				cout << "You're brave, if you can answer my question correctly in your first try, ";
				cout << "I'll let you go to the 10th temple! " << endl;
				cout << "Listen carefully: ";
				cout << "What is the Roman counterpart/equivalent of the Greek God Eros?" << endl;
				cout << "a) Cupid			b) Aphrodite		c) Dionysus" << endl << "Answer: ";
				cin >> ans;

				if (ans == 'a')
				{
					cout << "Incredible! You may take the shortcut to the Capricorn temple " << endl << endl;
					setPlayerLocation("Capricorn");
					begin(getPlayerLocation());
				}
				else
				{
					while (ans != 'a' && lives != 0)
					{
						cout << "Uh-uh, try again ";
						reducePLives();
						displayPLives();
						cout << "What is the Roman counterpart/equivalent of the Greek God Eros?" << endl;
						cout << "a) Cupid			b) Aphrodite		c) Dionysus" << endl << "Answer: ";
						cin >> ans;
					}

					if (lives == 0)
					{
						cout << "You died!" << endl;
						begin(getPlayerLocation());
					}

					else
					{
						cout << "Too bad you couldn't take the shortcut, but you can move on to ";
						cout << "the Scorpio temple! " << endl << endl;
						setPlayerLocation("Scorpio");
						begin(getPlayerLocation());
					}
				}
			}

		//SCORPIO
			else if (place == "Scorpio")
			{
				char ans;
				cout << "* * *" << " S C O R P I O " << "* * *" << endl;
				cout << "Congratulations for getting this far, I'm honestly not in the mood for dealing with you...";
				cout << "still, I have to ask you something. I really like puzzles, so here it goes: ";
				cout << "In a bouquet of flowers, all but two are roses, all but two are tulips, ";
				cout << "and all but two are daisies.How many flowers are in the bouquet ? " << endl;
				cout << "a) 6			b)3			c)9" << endl << "Answer: ";
				cin >> ans;

				while (ans != 'b' && lives != 0)
				{
					cout << "I'll let you try again... " << endl;
					reducePLives();
					displayPLives();
					cout << "In a bouquet of flowers, all but two are roses, all but two are tulips, ";
					cout << "and all but two are daisies.How many flowers are in the bouquet ? " << endl;
					cout << "a) 6			b)3			c)9" << endl << "Answer: ";
					cin >> ans;
				}
				if (lives == 0)
				{
					cout << "You died!";
					begin(getPlayerLocation());
				}

				else
				{
					cout << "Okay, you may continue" << endl << endl;
					setPlayerLocation("Sagittarius");
					begin(getPlayerLocation());
				}
					
			}

		//SAGITTARIUS
			else if (place == "Sagittarius")
			{
				cout << "* * *" << " S A G I T T A R I U S " << "* * *" << endl;
				cout << "...this temple is empty...";
				cin.ignore();
				cout << "Hey look! extra lives! ";
				lives = lives * 2;
				displayPLives();
				setPlayerLocation("Capricorn");
				cout << endl << "Next is the Capricorn temple " << endl << endl;
				begin("Capricorn");
			}

		//CAPRICORN
			else if (place == "Capricorn")
			{
				char ans;
				cout << "* * *" << " C A P R I C O R N " << "* * *" << endl;
				cout << "Oh, hello there, I was waiting for you. ";
				cout << "You're now on the 10th temple, and if you can answer whatever I ask you on the first try, ";
				cout << "You'll go directly to the last temple. " << endl;
				cout << "Not sure if you've noticed by now, but the guardians that allow you to take shortcuts, ";
				cout << "are the ones that ask questions about Greek mythology, and I won't be the exception. " << endl;
				cout << "Who killed Achilles? " << endl;
				cout << "a) His mother, Thetis		b) Paris, the son of the kings of Troja			c) God Zeus";
				cout << endl << "Answer: ";
				cin >> ans;

				if (ans == 'b')
				{
					cout << "Good, you have my permission to go to the last temple" << endl << endl;
					setPlayerLocation("Pisces");
					begin(getPlayerLocation());
				}

				else {
					while (ans != 'b' && lives != 0)
					{
						cout << "Are you sure? " << endl;
						reducePLives();
						displayPLives();
						cout << "Who killed Achilles? " << endl;
						cout << "a) His mother, Thetis		b) Paris, the son of the kings of Troja			c) God Zeus";
						cout << endl << "Answer: ";
						cin >> ans;

					}
					if (lives == 0)
					{
						cout << "You died!";
						begin(getPlayerLocation());
					}

					else
					{
						cout << "Go on" << endl << endl;
						setPlayerLocation("Aquarius");
						begin(getPlayerLocation());
					}

				}
			}

		//AQUARIUS
			else if (place == "Aquarius")
			{
				int ans;
				cout << "* * *" << " A Q U A R I U S " << "* * *" << endl;
				cout << "To get to the last temple, you'll have to answer another puzzle. " << endl;
				cout << "0, 1, 3, 6, 7, 9, 12, 13, 15, 18, ?" << endl;
				cout << "What numbers should replace the question mark? Think carefully..." << endl;
				cout << "Answer: ";
				cin >> ans;

				while (ans != 19 && lives != 0)
				{
					cout << "Think harder " << endl;
					reducePLives();
					displayPLives();
					cout << "0, 1, 3, 6, 7, 9, 12, 13, 15, 18, ?" << endl;
					cout << "What numbers should replace the question mark? Think carefully..." << endl;
					cout << "Answer: ";
					cin >> ans;

				}
				if (lives == 0)
				{
					cout << "You died!";
					begin(getPlayerLocation());
				}

				else
				{
					cout << "Off to the last temple you go" << endl << endl;
					setPlayerLocation("Pisces");
					begin(getPlayerLocation());
				}
			}

		//PISCES
			else if (place == "Pisces")
			{
				string enter;
				cout << "* * *" << " P I S C E S  " << "* * *" << endl;
				cout << "I honestly didn't think you'd get this far, but hopefully in this temple you'll lose ";
				cout << "what's left of your lives..." << endl;

				random(50, 0, lives);

				if (lives == 0)
				{
					cout << "You died!" << endl;
					begin(getPlayerLocation());
				}

				else {

					cout << "Wow, you really made it... ";
					cout << "Go with Athena, and may her grant your wish. " << endl << endl;
					setPlayerLocation("Athena");
					begin(getPlayerLocation());
				}
			}

			
		}
	}
};