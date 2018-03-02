#include <iostream>
#include "Q10.h"

int main()
{
	int numstates = 2;
	vector<bool> is_accepting = {true, false};
	vector<int> next_on_0 = {0,1};
	vector<int> next_on_1 = {1,0};

	FSA fsa1 = FSA(numstates, is_accepting,  next_on_0,  next_on_1);

	vector<int> inputs = { 1,0,1,1,0,1};
	cout << fsa1.accepts(inputs) << endl << endl <<"Other tests: "<< endl;

	vector<int> inputs2 = { 1,0,1,1,0,1,1};
	cout << fsa1.accepts(inputs2) << endl;

	vector<int> inputs3 = { 0,1,1,0,1,1 };
	cout << fsa1.accepts(inputs3) << endl;

	getchar();
	return 0;
}