#include "Q8.h"
#include <iostream>
#include <fstream>
using namespace std;
#define V 50

void Graph::read(const char* filename)
{
	fstream fs;
	fs.open(filename); // , fstream::in | fstream::out | fstream::app);

	fs >> size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fs >> distance[i][j];
		}
	}

	fs.close();
}

vector<int> vec__ = { 0,1,2,3 };		//	!!Content of default path is not indicated in the courseworksheet, so i have just entered this one
void Graph::print(ostream& out)
{
	out << "Number of nodes of graph: " << size << endl;
	out << "Distances among nodes of graph: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			out << distance[i][j] << "\t";
		}
		out << endl;
	}
	out << "Shortest path between node 0 and 3 is equal to: " << shortest(0, 3, vec__) << endl;
}

int Graph::shortest(int v1, int v2, vector<int> &path)
{
	eliminateNodesNotExistInVector(path);			// Fullfills the distances between all nodes and nodes not existing in the path vector with zeros.

	int outputDistances[V];
	bool listOfBools[V];

	for (int i = 0; i < size; i++)
	{
		outputDistances[i] = 100;
		listOfBools[i] = false;
	}
	outputDistances[v1] = 0;
	for (int count = 0; count < size - 1; count++)
	{
		int u = minDistance(outputDistances, listOfBools);

		listOfBools[u] = true;

		for (int v = 0; v < size; v++)
		{
			if (!listOfBools[v] && distance[u][v] && outputDistances[u] != 100 && outputDistances[u] + distance[u][v] < outputDistances[v])
			{
				outputDistances[v] = outputDistances[u] + distance[u][v];
			}
		}
	}
	return outputDistances[v2];
}

void Graph::eliminateNodesNotExistInVector(vector<int> &path)
{
	for (int i = 0; i < path.size(); i++)
	{
		fillZero(path[i]);
	}
}

void Graph::fillZero(int fillZero)
{
	for (int i = 0; i < size; i++)
	{
		distance[i][fillZero] = 0;
	}

	for (int j = 0; j < size; j++)
	{
		distance[fillZero][j] = 0;
	}
}

int Graph::minDistance(int dist[], bool boolSet[])
{
	int min = 100;
	int indexOfMin;

	for (int v = 0; v < size; v++)
	{
		if (boolSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			indexOfMin = v;
		}
	}
	return indexOfMin;
}
