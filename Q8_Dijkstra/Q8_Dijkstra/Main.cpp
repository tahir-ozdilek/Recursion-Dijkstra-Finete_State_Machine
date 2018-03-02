#include <iostream>
#include <fstream>
#include <vector>
#include "Q8.h"

using namespace std;

int main()
{
	Graph g1;

	g1.read("Q8_graphdata.txt");

	ofstream outfile;
	outfile.open("Q8_out.txt");
	if (outfile.fail())
	{
		cerr << "Can't open output file";
		exit(1);
	}

	g1.print(cout);
	g1.print(outfile);
	outfile.close();

	system("pause");
	return 0;
}
