
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
#define _CRT_SECURE_NO_WARNINGS
/**************************************ad-hoc Algorithm*************************************************/

//#define AD_HOC_01_UVA_100_THE_3N_PROBLEM aaa

#define ENTRY_FUNC AD_HOC_01_UVA_100_THE_3N_PROBLEM

/*******************************************************************************************************/
#include <iostream>
#include <string>
#include <direct.h>

#define CAT(A, B)   A##B
#define FILE_NAME1(A) CAT(#A, ".txt")
#define FILE_NAME(A) FILE_NAME1(A)

int before_main()
{	
	std::string path_dir = _getcwd(NULL, 0);
	//std::string st = FILE_NAME(AD_HOC_01_UVA_100_THE_3N_PROBLEM);
	std::string st = FILE_NAME(ENTRY_FUNC);
	std::string input_file = path_dir + "\\..\\input\\" + st;

	freopen(input_file.c_str(), "r", stdin);
	
	return 0; 
}
int n = before_main();
/*******************************************************************************************************/


