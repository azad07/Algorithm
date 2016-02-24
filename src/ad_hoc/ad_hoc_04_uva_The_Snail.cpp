#include "CommonHeader.h"


#ifdef AD_HOC_04_UVA_573_THE_SNAIL
READ_INPUT(AD_HOC_04_UVA_573_THE_SNAIL)

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define FORI(i,a,b) for(int i=(int)a; i<=(int)b; i++)
#define RFORI(i,a,b) for(int i=(int)a; i>=(int)b; i--)
using namespace std;

int main()
{
	float H, U, D, F;
	int day;
	float currentHeight;
	while (scanf("%f %f %f %f", &H, &U, &D, &F) >= 0)
	{
		if (H == 0)
			break;
		currentHeight = 0.0f;
		day = 0;
		bool up = true;
		while (1)
		{
			float hC = U - day*(U*F / 100.0);
			day++;
			hC = roundf(hC * 1000) / 1000;
			currentHeight = currentHeight + hC;
			currentHeight = roundf(currentHeight * 1000) / 1000;
			if (currentHeight > H)
				break;
			currentHeight -= D;
			if (currentHeight < 0.0f)
			{
				up = false;
				break;
			}
				
			currentHeight = roundf(currentHeight * 1000) / 1000;
			
		}

		if (up)
			cout << "success";
		else
			cout << "failure";
		cout << " on day ";
		cout << day << endl;
	}

	return 0;
}

#endif
