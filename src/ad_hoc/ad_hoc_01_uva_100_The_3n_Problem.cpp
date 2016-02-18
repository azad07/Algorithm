#include "CommonHeader.h"

//#ifdef AD_HOC_01_UVA_100_THE_3N_PROBLEM
//#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define COMPL(b) PRIMITIVE_CAT(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0
#define EQUAL(x, y) COMPL(NOT_EQUAL(x, y))

#define AA aa
#define BB bb

#if EQUAL(AA, BB)

#include <iostream>
using namespace std;


int main()
{
	int a;
	cin >> a;
	cout << "azad" << endl;
	return 0;
}

#endif
