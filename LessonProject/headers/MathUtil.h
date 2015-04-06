
#pragma once

#include <stdlib.h>
#include <time.h>
using namespace std;

class MathUtil
{
	MathUtil() 
	{
		// randomize 
		//
		srand((unsigned int)time(0));
	}

	inline void Touch()
	{
	}

	inline static MathUtil& Instance() 
	{
		static MathUtil M;
		return M;
	}

public:
	inline static double random01()
	{
		MathUtil::Instance().Touch();
		//
		return double(rand() % INT_MAX)/INT_MAX;
	}

	inline static int randomInt(int M)
	{
		MathUtil::Instance().Touch();
		//
		return (rand() % M);
	};
};

void print_vector(const vector<int>& a);

void print_2d_vector(const vector<vector<int>>& a);