#include "CommonHeader.h"


#ifdef AD_HOC_01_UVA_100_THE_3N_PROBLEM
READ_INPUT(AD_HOC_01_UVA_100_THE_3N_PROBLEM)

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int solveCase(int num)
{
	int count = 1;
	while (num != 1)
	{
		if (num % 2 == 0)
			num /= 2;
		else
			num = 3 * num + 1;
		count++;
	}
	return count;
}
int main()
{
	int a, b;
	while (scanf("%d %d\n", &a, &b) >= 0)
	{
		int count, m = 0;
		cout << a << " " << b << " ";
		if (a > b)
			swap(a, b);
		for (int i = a; i <= b; i++)
		{
			count = solveCase(i);
			m = max(count, m);
		}
		cout << m << endl;
	}
	return 0;
}

#endif
