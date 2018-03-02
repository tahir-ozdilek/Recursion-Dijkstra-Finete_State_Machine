#ifndef Q10_H
#define Q10_H

#include <vector>
using namespace std;


class FSA
{
 public:
	 FSA(int numstates, vector<bool> is_accepting, vector<int> next_on_0, vector<int> next_on_1) :
		 numstates(numstates),
		 is_accepting(is_accepting),
		 next_on_0(next_on_0),
		 next_on_1(next_on_1) {};
  bool accepts(vector<int> inputs);
 private:
	  int currentState=0;
	  int numstates; // the number of states in the machine
	  vector<bool> is_accepting; // is_accepting[i] is true if i is an accepting state
	  vector<int> next_on_0; // next_on_0[i] is the successor state to i if a 0 is input
	  vector<int> next_on_1; // next_on_1[i] is the successor state to i if a 1 is input
};

#endif
