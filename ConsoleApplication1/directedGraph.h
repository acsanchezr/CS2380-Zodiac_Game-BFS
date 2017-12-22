#include <string>
#include <iostream>
#include <vector>
using namespace std;

class directedGraph
{
protected:
	class vertex
	{
	public:
		string data;
		bool visited = false;
		//list of neighbors...
		vector<vertex*> neighbors;
		vertex* pred;

		vertex(string x)
		{
			data = x;
		}
	};

	//list of all the vertices in the graph.
	//Could change this to a cooler data structure,
	//like a binary search tree, to get faster
	//"finds" of target values.
	vector<vertex*> vertexList;

	//find and return vertex containing value x
	//return NULL if item is not in any vertex
	vertex * findVertex(string x)
	{
		for (int i = 0; i<vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return NULL;
	}

public:

	void addVertex(string x)
	{
		vertexList.push_back(new vertex(x));
	}

	void addDirectedEdge(string x, string y)
	{
		vertex * a = findVertex(x);
		vertex * b = findVertex(y);

		if (a == NULL || b == NULL)
			cout << "whoa, you messed something upp...." << endl;
		else
			a->neighbors.push_back(b);
	}

	//test to see if graph is set up correctly
	void testDisplay()
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			cout << "From ";
			cout << vertexList[i]->data << " you can go to: ";
			for (int j = 0; j<vertexList[i]->neighbors.size(); j++)
			{
				cout << vertexList[i]->neighbors[j]->data << " ";
			}
			cout << endl;
		}
	}

	void addEdgeBW(string x, string y)
	{
		vertex * a = findVertex(x);
		vertex * b = findVertex(y);

		//in case it gives you and error/vertex is empty
		if (a == NULL || b == NULL)
		{
			cout << "wrong " << endl;
		}

		else
		{
			a->neighbors.push_back(b);
			b->neighbors.push_back(a);
		}
	}
};
