
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
#define _CRT_SECURE_NO_WARNINGS
#define  _SCL_SECURE_NO_WARNINGS
 
#include "ConsoleColor.h";

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
//#define graph_01_basic

/************************************** Flood Fill Algorithm*************************************************/
//#define flood_fill_01_uva_260_Gioco_dell
//#define flood_fill_02_uva_352_The_Seasonal_War 
//#define flood_fill_03_uva_459_Graph_Connectivity
//#define flood_fill_04_uva_469_Wetlands_of_Florida
//#define flood_fill_05_uva_572_ Oil_Deposits
//#define flood_fill_06_uva_657_The_die_is_cast
//#define flood_fill_07_uva_722_Lakes
//#define flood_fill_08_uva_758_The_Same_Game
//#define flood_fill_09_uva_776_Monkeys_in_a_Regular_Forest
//#define flood_fill_10_uva_782_Contour_Painting
#define flood_fill_11_uva_784_Maze_Exploration


/************************************** CodeForce*************************************************/
//#define codeforce_01_A_Time
//#define codeforce_02_B_Weird_Cryptography
//#define codeforce_03_C_OCR

/************************************** Codechef*************************************************/
//#define codechef_01_apr_Chef_And_Coloring
//#define codechef_02_apr_Chef_and_Ballons
//#define codechef_03_apr_Chef_And_Magical_Path

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


