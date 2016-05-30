
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
//#define flood_fill_11_uva_784_Maze_Exploration
//#define flood_fill_12_uva_785_Grid_Colouring
//#define flood_fill_13_uva_852_Deciding_victory_in_Go
//#define flood_fill_14_uva_871_Counting_Cells_in_a_Blob


//#define codejam_01_Counting_sheep
//#define codejam_02_Revenge_of_the_Pancakes
//#define codejam_03_Coin_Jam
//#define codejam_04_1A_2010_Rotate
//#define codejam_05_R_1A_2016_A
//#define codejam_06_R_1A_2016_B
//#define codejam_07_R_1B_2016_A

/************************************** CodeForce*************************************************/
//#define codeforce_01_A_Time
//#define codeforce_02_B_Weird_Cryptography
//#define codeforce_03_C_OCR

/************************************** Codechef*************************************************/
//#define codechef_01_apr_Chef_And_Coloring
//#define codechef_02_apr_Chef_and_Ballons
//#define codechef_03_apr_Chef_And_Magical_Path

/************************************** Dynamic programming*************************************************/
//#define DP_01_uva_507_Jill_Rides_Again
//#define DP_02_uva_10755_Garbage_Heap
//#define DP_03_uva_10684_The_jackpot
//#define DP_04_uva_108_Maximum_Sum
//#define DP_05_Localized_Summing_for_Blurring
#define DP_06_uva_836_Largest_Submatrix

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


