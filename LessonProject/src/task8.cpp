#include "stdafx.h"
#include <iostream> 
#include <Board.h>
#include <MathUtil.h>

#define WALL (-1) 

void print_line(int* line, int m)
{
	for (int j = 0; j < m; j++) 
	{
		if (line[j] >= 0) cout << line[j];
		else if (line[j] == WALL) cout << '_'; 
		else cout << '?';
	}
	cout << endl; 
}

void find_path(const Board& board)
{
	// global data 
	// 
	int i0 = 0; // current maximal index+1 (== next index) 
	map<int,int>; // associations: 3 --> 2 
	//
	// per step data
	//
	int* line = new int[board.m]; // connected component indicies 
	//
	for (int y = 0; y < board.n; y++)
	{
		if (y == 0)
		{
			char left = '#'; // virtual wall at position -1
			//
			for (int x = 0; x < board.m; x++) 
			{
				if (board(x,0) == ' ')
				{
					if (left == '#') 
					{
						// i0 -- new index 
						line[x] = i0;
						i0++; 
					}
					else if (left == ' ') 
					{
						line[x] = i0 - 1;
					}
				}
				else if (board(x,0) == '#') 
				{
					// do nothing 
					//
					line[x] = WALL; 
				}
				left = board(x,0);
			}
			print_line(line, board.m); 
		}
		else // i > 0   
		{
			/*
					^^      #.....#....###........#~~~#22222222!222!2###
					^^      ###0000000#######111#######222#####333#4444#
			*/
			//
			int* newLine = new int[board.m];
			//
			for (int x = 0; x < board.m; x++) // scanning the line UNDER 
			{
				if (line[x] == WALL)
				{
					// do nothing 
				}
				else // line[x] >= 0 // space 
				{
				}
			}
		}
	}
}

Board test_board()
{
	int n = 8 + (rand() % 5);
	Board b(n);
	for (int y = 0; y < b.n; y++)
	{
		for (int x = 0; x < b.m; x++)
		{
			b(x,y) = (MathUtil::randomInt(10) < 3) ? '#' : ' '; 
		}
	}
	b(0,0) = b(b.m-1, b.n-1) = ' ';
	return b; // TODO: копирование? 
}

void test_task8()
{
	cout << "================= Test task 8 ========================" << endl;
	Board board = test_board();
	board.Print(cout);
	find_path(board);
	cout << endl;
}

