#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

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

void print_vector(const vector<int>& a)
{
	for (int i = 0; i < a.size(); i++) 
	{
		cout << a[i] << " "; 
	}
	cout << endl;
}

void print_2d_vector(const vector<vector<int>>& a)
{
	cout << "<";
	for (int i = 0; i < a.size(); i++) 
	{
		cout << "(";
		for (int j = 0; j < a[i].size(); j++) 
		{
			cout << a[i][j] << " "; 
		}
		cout << "),";
	}
	cout  << ">" << endl;
}
