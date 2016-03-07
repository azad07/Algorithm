
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
#define _CRT_SECURE_NO_WARNINGS
#define  _SCL_SECURE_NO_WARNINGS


/**************************************ad-hoc Algorithm*************************************************/

//#define AD_HOC_01_UVA_100_THE_3N_PROBLEM
//#define AD_HOC_02_UVA_272_TEX_QUOTES
//#define AD_HOC_03_UVA_WORD_SCRAMBLE
//#define AD_HOC_04_UVA_573_THE_SNAIL
//#define ad_hoc_05_uva_661_Blowing_Fuses
//#define ad_hoc_06_uva_837_Light_and_Transparencies
//#define ad_hoc_07_uva_10082_WERTYU
//#define ad_hoc_08_uva_10141_Request_for_Proposal
//#define ad_hoc_09_uva_10281_Average_Speed


/**************************************Graph Algorithm*************************************************/
#define graph_01_basic

/*******************************************************************************************************/
#include <iostream>
#include <string>
#include <direct.h>

#define CAT(A, B)   A##B
#define FILE_NAME1(A, B) CAT(A, B)
#define FILE_NAME(A, B) FILE_NAME1(A, B)

#define READ_INPUT(A)													\
	int before_main1()													\
{																		\
	std::string path_dir = _getcwd(NULL, 0);							\
	std::string st = FILE_NAME1(#A, ".txt");							\
	std::string input_file = path_dir + "\\..\\input\\" + st;			\
	freopen(input_file.c_str(), "r", stdin);							\
	return 0;															\
}																		\
	int nn = before_main1();											\
/*******************************************************************************************************/


