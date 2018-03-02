#include "Q6.h"

int recurrence(int a, int b, int k, int u0, int u1)
{
	int result;
	if (k == 0)
		return u0;
	else if (k == 1)
		return u1;
	else
	{
		int k1stPreu1 = recurrence(a, b, k - 1, u0, u1);
		int k2ndPreu0 = recurrence(a, b, k - 2, u0, u1);
		result = k1stPreu1*a + b*k2ndPreu0;
		return result;
	}
}

void LFSR(int k, vector<int> &u)
{
	if (u.size() > k)
	{
		return;
	}
	else
	{
		LFSR(k - 1, u);
		u.push_back((u[u.size() - 3] + u[u.size() - 5]) % 2);
	}
}