#include <iostream>
#include <vector>

using namespace std;

int recurrence(int a, int b, int k, int u0)
{
	int result;
	if (k == 0)
		return u0;
	else
	{
		int kPre = recurrence(a, b, k - 1, u0);
		result = kPre*a + b;
		return result;
	}
}

void LFSR(int k, vector<int> &u)
{
	if (u.size() == k || k < 4)
	{
		return;
	}
	else
	{
		LFSR(k - 1, u);
		u.push_back((u[u.size() - 3] + u[u.size() - 4]) % 2);
		cout << (u[u.size() - 3] + u[u.size() - 4]) % 2 << " ";
	}
}

//My first solution, the one above is much better, 
//'limit' and 'forOnce' variables and if (forOnce) control each time make this solution kind of bad though,
//But i still didnt want to delete it.
int limit;
bool forOnce = true;
void LFSR_FirstSol(int k, vector<int> &u)
{
	if (forOnce)
	{
		limit = k;
		forOnce = false;
	}
	if (u.size() == limit || k < 4)
	{
		return;
	}
	else
	{
		u.push_back((u[u.size() - 3] + u[u.size() - 4]) % 2);
		cout << (u[u.size() - 3] + u[u.size() - 4]) % 2 << " ";
		LFSR_FirstSol(u.size() + 1, u);
	}
}

int main()
{


	// a= 6  b=9
	cout << "Question 2-a:" << endl;
	cout << recurrence(6, 9, 0, 3) << endl;
	cout << recurrence(16, 19, 5, 2) << endl;

	// 6 = 0110
	vector<int> vector_ = { 0,1,1,0 };
	cout << endl << "Question 2-b:" << endl;
	LFSR(50, vector_);		//Main solution

									// First/old solution
	cout << endl << endl << "Different function same result:" << endl;
	vector<int> vectorForFirst = { 0,1,1,0 };
	LFSR_FirstSol(50, vectorForFirst);

	cout << endl;
	system("pause");
	return 0;
}

