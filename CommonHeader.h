
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
#define _CRT_SECURE_NO_WARNINGS
#define  _SCL_SECURE_NO_WARNINGS
 
#include "ConsoleColor.h"

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
//#define DP_06_uva_836_Largest_Submatrix
//#define DP_07_uva_10074_Take_the_Land
//#define DP_08_uva_10667_Larges_ Block
//#define DP_09_uva_10827_Maximum_sum_on_a_torus
//#define DP_10_uva_11951_Area
//#define DP_11_uva_111_History_Grading
//#define DP_12_uva_231_Testing_the_CATCHER
//#define DP_13_uva_562_Dividing_coins
//#define DP_14_uva_990_Diving_for_gold
//#define DP_15_uva_10130_SuperSale
//#define DP_16_uva_147_Dollors
//#define DP_17_uva_166_Making_changs
//#define DP_18_uva_357_Let_Me_Count_The_Ways
//#define DP_19_uva_674_Coin_Change
//#define DP_20_uva_11407_Squares
//#define DP_21_uva_00116_Unidirectional_TSP
//#define DP_22_uva_Simple_Minded_Hashing
//#define DP_23_uva_10910_Marks_Distribution
//#define DP_24_uva_11026_A_Grouping_Problem
//#define DP_25_uva_10003_Cutting_Sticks
//#define DP_26_uva_10465_Homer_Simpson
//#define DP_27_uva_10036_Divisibility
//#define DP_28_uva_10400_Game_Show_Math
//#define DP_29_uva_00437_The_Tower_of_Babylon
//#define DP_30_uva_10616_Divisible_Group_Sums
//#define DP_31_uva_10364_Square
//#define DP_32_uva_10534_Wavio_Sequence
//#define DP_33_uva_00481_What_goes_up
//#define DP_34_uva_11456_Trainsorting
//#define DP_35_uva_11790_Murcia_Skyline
//#define DP_36_uva_01196_Tiling_Up_Blocks
#define DP_37_uva_10131_Is_Bigger_Smarter

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


