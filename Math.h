
#pragma once

#include <stdlib.h>
#include <time.h>

#define MATH_N0 (1000000000)

class Math
{
	Math() 
	{
		// randomize 
		//
		srand(time(0));
	}

	inline void Touch()
	{
	}

	inline static Math& Instance() 
	{
		static Math M;
		return M;
	}

public:
	inline static double random01()
	{
		Math::Instance().Touch();
		//
		return double(rand() % MATH_N0)/MATH_N0;
	};
};
