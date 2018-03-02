#include <iostream>
#include "Q6.h"

using namespace std;
int main()
{

	// a= 6  b=9
	cout << "Question 6-a:" << endl;
	cout << recurrence(6, 9, 0, 3, 5) << endl;
	cout << recurrence(16, 19, 5, 1, 2) << endl;

	// 6 = 0110
	vector<int> vector = { 0,1,1,0,1 };

	cout << endl << "Question 6-b:" << endl;
	LFSR(50, vector);		
	
	cout << endl;
	int agre = 1, dis = 1;

	cout << "    Unshifted" << "  " << "Shifted" << endl;
	cout << "Element " << 1 << ":  ";
	cout << vector[0] << "  " << vector[50];
	if (vector[0] == vector[50])
	{
		cout << "  Agree " << agre << endl;
		agre++;
	}
	else
	{
		cout << "  Disagree " << dis << endl;
		dis++;
	}

	for (int i = 1; i < 31; i++)
	{
		cout << "Element " << i+1 << ":  ";
		cout << vector[i] << "  " << vector[i - 1];
		if (vector[i] == vector[i - 1])
		{
			cout << "  Agree " << agre <<endl;
			agre++;
		}		
		else
		{
			cout << "  Disagree " << dis << endl;
			dis++;
		}
	}

	getchar();
	return 0;
 }