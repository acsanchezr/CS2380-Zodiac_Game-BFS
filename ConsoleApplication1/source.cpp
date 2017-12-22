
#include <iostream>
#include <string>
#include "aDisplay.h"
#include "gameGraph.h"
using namespace std;

void buildWorld(gameGraph &world)
{
	world.addVertex("entrance");
	world.addVertex("Aries");
	world.addVertex("Taurus");
	world.addVertex("Gemini");
	world.addVertex("Cancer");
	world.addVertex("Leo");
	world.addVertex("Virgo");
	world.addVertex("Libra");
	world.addVertex("Scorpio");
	world.addVertex("Sagittarius");
	world.addVertex("Capricorn");
	world.addVertex("Aquarius");
	world.addVertex("Pisces");
	world.addVertex("Athena");

	//add a method to your directedGraph class that adds a bi-directional edge to your graph.
	world.addDirectedEdge("entrance", "Aries");
	world.addDirectedEdge("Aries","Taurus");
	world.addDirectedEdge("Taurus", "Gemini");
	world.addDirectedEdge("Taurus", "Leo");
	world.addDirectedEdge("Gemini", "Cancer");
	world.addDirectedEdge("Cancer", "Leo");
	world.addDirectedEdge("Leo", "Virgo");
	world.addDirectedEdge("Leo", "Libra");
	world.addDirectedEdge("Virgo", "Libra");
	world.addDirectedEdge("Libra", "Scorpio");
	world.addDirectedEdge("Libra", "Capricorn");
	world.addDirectedEdge("Scorpio", "Sagittarius");
	world.addDirectedEdge("Sagittarius", "Capricorn");
	world.addDirectedEdge("Capricorn", "Aquarius");
	world.addDirectedEdge("Capricorn", "Pisces");
	world.addDirectedEdge("Pisces", "Athena");
}

int main()
{
	//Create a class gameGraph that inherits from directedGraph
	gameGraph world;

	//add some locations and some connections between locations.
	buildWorld(world);

	//double check that the world is built as desired
	//world.testDisplay();

	//player starts at entrance
	world.setPlayerLocation("entrance");

	//Intro + current location
	cout << "You've come all the way from Texas to Greece just so that Goddess Athena can grant you a wish.";
	cout << "However, getting to her won't be easy. " << endl;
	cout << "In order to meet her, you'll need to fight against 12 guardians that protect her. ";
	cout << "Each guardian lives in a temple that represents a zodiac sign, and ";
	cout << "you'll have to defeat them to reach your goal, good luck! and may Zeus bless you " << endl << endl;

	cout << "* + * + * + * + * + * + * + * + * + * + * + * + * + * + * +" << endl << endl;

	cout << "You are at the " << world.getPlayerLocation() << endl;
	cout << "Press 'Enter' to go to the first temple and begin your quest ";
	cin.ignore(); 
	cout << endl;
	//move player to aries
	world.setPlayerLocation("Aries");
	world.begin(world.getPlayerLocation());

	if (world.getPlayerLocation() == "Athena")
	{
		Athena();
	}

	//tell the player where they may travel to
	system("pause");
}
