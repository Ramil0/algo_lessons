#include "stdafx.h"
#include <iostream>
#include <Board.h>
#include <MathUtil.h>
using namespace std;

void task7_addRandomLine(Board& board)
{
	
	if (MathUtil::randomInt(2))
	{
		int begin = MathUtil::randomInt(board.m), end = MathUtil::randomInt(board.m);
		int y = MathUtil::randomInt(board.n);
		for (int k = min(begin, end); k < max(begin, end); k++) board(k, y) = '#';
	}
	else 
	{
		int begin = MathUtil::randomInt(board.n), end = MathUtil::randomInt(board.n);
		int x = MathUtil::randomInt(board.m);
		for (int k = min(begin, end); k < max(begin, end); k++) board(x, k) = '#';
	}
}

void task7_genRandomBoard(Board& board)
{
	for (int k = 0; k < 20; k++) task7_addRandomLine(board);
}
void task7(Board& board)
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

void test_task7()
{
	cout << "================= Test task 7 ========================" << endl;
	Board board(30, 20);
	task7_genRandomBoard(board);
	board.Print(cout);
	task7(board);
	cout << endl;
	
}