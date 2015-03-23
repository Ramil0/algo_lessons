#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "my_util.h"
using namespace std;

vector<vector<int>> one_step(vector<vector<int>>& board, char* dx, char* dy, 
	int init_x, int init_y)
{
	/*
	Returns cells reachable from (init_x, int init_y) in one step
	*/
	int x = init_x, y = init_y;
	vector<vector<int>> destinations;
	for (int step = 0; step < 8; step ++)
	{
		x += dx[step];
		y += dy[step];
		
		if (board[x][y] == 0) // not yet visited and not outside
		{
			// The following two lines just initialize a vector with {x,y}
			int arr[] =  {x,y};
			vector<int> position (arr, arr + sizeof(arr) / sizeof(arr[0]));
			destinations.push_back(position);
		}

		x = init_x;
		y = init_y;

	}
	return destinations;
}

vector<vector<int>> steps(vector<vector<int>>& board, char* dx, char* dy, 
	vector<vector<int>> cells, int M) 
{
	/*
	Returns cells reachable from all cells in "cells" in "M" steps
	*/
	vector<vector<int>> all_new_cells = cells;
	if (M > 0)
	{
		for (int i = 0; i < cells.size(); i++)
		{
			vector<vector<int>> new_cells = one_step(board, dx, dy, 
				cells[i][0], cells[i][1]);
			for (int j = 0; j < new_cells.size(); j++)
			{
				// add current cell if it hasn't yet been added
				if  (!(find(all_new_cells.begin(), all_new_cells.end(), 
					new_cells[j]) != all_new_cells.end()))
					all_new_cells.push_back(new_cells[j]);
			}
		}
		return steps(board, dx, dy, all_new_cells, M - 1);
	}

	else 
		return all_new_cells;
}

void task_1_2(int init_x, int init_y, int num_steps)
{
	/*

	*/
	vector<vector<int>> board(12, vector<int>(12));
	//fill the board with 0 and 1. 1 - if the cell is outside
	//the 8x8 board or if it has been visited. 
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			if ((i >= 2) && (i <= 9) && (j >= 2) && (j <= 9))
				board[i][j] = 0;
			else 
				board[i][j] = 1;
		}
	// possible moves
	char dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	char dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

	// start_cells - is a 1-length vector with vector <init_x, init_y>
	// taking into account the unreachable lanes of width 2 around the board
	int arr[] =  {init_x, init_y};
	vector<int> start_point(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<vector<int>> start_cells;
	start_cells.push_back(start_point);
	print_2d_vector(steps(board, dx, dy, start_cells, num_steps));
}


void test_task_1_2() 
{
	cout << "Test task_1_2" << endl;
	cout << "Cells reachable from the corner (2,2) in two steps" << endl;
	task_1_2(2, 2, 2);
	cout << endl;
}
