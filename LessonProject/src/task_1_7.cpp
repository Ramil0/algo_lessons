#include "stdafx.h"
#include <iostream>
#include <my_util.h>
#include <Board.h>
#include <Math.h>
using namespace std;

void task_1_7_addRandomLine(Board& board)
{
	
	if (Math::randomInt(2))
	{
		int begin = Math::randomInt(board.m), end = Math::randomInt(board.m);
		int y = Math::randomInt(board.n);
		for (int k = min(begin, end); k < max(begin, end); k++) board(k, y) = '#';
	}
	else 
	{
		int begin = Math::randomInt(board.n), end = Math::randomInt(board.n);
		int x = Math::randomInt(board.m);
		for (int k = min(begin, end); k < max(begin, end); k++) board(x, k) = '#';
	}
}

void task_1_7_genRandomBoard(Board& board)
{
	for (int k = 0; k < 20; k++) task_1_7_addRandomLine(board);
}
void task_1_7(Board& board)
{
	/*

	##################################
	#S                               #
	#o                               #
	#o            ##########         #
	#o            #Sooooooo#         #
	#o            #oooooooD#         #
	#ooooooo!     ##########         #
	########o     ooooo              #
	#      #o     o###o              #
	#      #ooooooo#o>ooo>...        #
	##################################

	char state: v ^ < >    

		# ~ #|wall
		                     .   ^           #   #
	>   o      >.  o>        >#  o#          >#  <#
	.   v      #   #         #   #           #   #






	*/
}

void test_task_1_7()
{
	Board board(30, 20);
	task_1_7_genRandomBoard(board);
	board.Print(cout);
	task_1_7(board);
	
}