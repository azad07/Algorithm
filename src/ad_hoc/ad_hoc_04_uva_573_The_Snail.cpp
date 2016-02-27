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
	int H, D, F, dia;
	float U, alt, f;

	while (1)
	{
		scanf("%d %f %d %d", &H, &U, &D, &F);
		if (H == 0) break;
		dia = 1;
		alt = 0;
		f = U*F / 100;
		while (1){
			alt += U;
			if (U > 0)
				U -= f;
			if (alt > H) break;
			alt -= D;
			if (alt < 0) break;
			dia++;
		}
		if (alt < 0)
			printf("failure on day %d\n", dia);
		else
			printf("success on day %d\n", dia);
	}
	return 0;
}

#endif
