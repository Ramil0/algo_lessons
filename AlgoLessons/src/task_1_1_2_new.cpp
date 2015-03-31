#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "my_util.h"
#include "Math.h"
#include "Board.h"
using namespace std;

void step_by_horse(const Board& board, Board& board2)
{
	char dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	char dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	const int num_steps = sizeof(dx)/sizeof(char);
	for (int y = 0; y < board.n; y++)
	{
		for (int x = 0; x < board.m; x++)
		{
			if (board(x,y) == 'H')
			{
				for (int step_i = 0; step_i < num_steps; step_i++)
						if ((x + dx[step_i] >= 0) && (x + dx[step_i] < board.m) && (y + dy[step_i] >= 0) && (y + dy[step_i] < board.n))
								board2(x + dx[step_i], y + dy[step_i]) = 'H';
			}
		}
	}
	
}

void test_task_1_2_new() 
{
	//
	// standard board size 
	int n = 8;
	int K_steps = 5;

	

	Board board(n), board2(n);
	int x0 = Math::randomInt(8), y0 = Math::randomInt(8); 
	board(x0, y0) = 'H'; // '0', '1' лучше, чем 0, 1   (int)   '3'-'0' == 3    
	//
	board.Print(cout);
	for (int k = 0; k < K_steps; k++)
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		board2.Chess_Init();
		step_by_horse(board, board2);
		board2.Print(cout);
		board = board2;
	}

	//board.Print(cout);
	//Board board1(n);
	//Board board2(n);
	//step_by_horse(board, board1);
	//board1.Print(cout);
	//step_by_horse(board1, board2); // опасный дизайн 
	////
	//board2.Print(cout);
}
