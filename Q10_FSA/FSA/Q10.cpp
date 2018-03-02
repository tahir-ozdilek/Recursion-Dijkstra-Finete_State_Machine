#include "Q10.h"



bool FSA::accepts(vector<int> inputs)
{
	for (int i = 0; i < inputs.size(); i++)
	{
		if (inputs[i] == 0)
			currentState = next_on_0[currentState];	// currentState declared as int in class.
		else if(inputs[i] == 1)
			currentState= next_on_1[currentState];
	}
	if (currentState == 0)
		return true;
	else
	{
		currentState = 0;	//for reseting state of machine
		return false;
	}	
}