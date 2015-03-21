// Lesson1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
//---------------------------------------

#include <stdlib.h>
#include <time.h>
#include <iostream> // <-- STL 
using namespace std; // HPP-styles

int max_stream(const vector<int>& a, int* out_index=NULL)
{
	/*
	Returns the maximal element and (optionally) sets its index.
	*/
	int current_max = a[0], current_index = 0;
	for (int i = 0; i < a.size(); i++) 
	{
		if (a[i] > current_max)
		{
			current_index = i;
			current_max = a[i];
		}
	}
	if (out_index) *out_index = current_index;
	return current_max;
}

int oddmax_evenmin_diff(const vector<int>& a)
{
	/*
	Returns the difference between the maximal odd integer (if any) and 
	the mininmal even integer (if any). Otherwise, returns NULL.
	*/
	int odd_max = NULL, even_min = NULL;
	for (int i = 0; i < a.size(); i++) 
	{
		if (abs(a[i] % 2) == 1) // odd 
		{
			if (odd_max == NULL)
			{
				odd_max = a[i];
			}
			else if (a[i] > odd_max)
				odd_max = a[i];
		}
		else // if (a[i] % 2 == 0) // even 
		{
			if (even_min == NULL)
			{
				even_min = a[i];
			}
			else if (a[i] < even_min)
				even_min = a[i];
		}	
	}
	if (odd_max!= NULL && even_min != NULL)
	{
		return odd_max - even_min;
	}
	else return NULL;
}

void print(const vector<int>& a)
{
	for (int i = 0; i < a.size(); i++) 
	{
		cout << a[i] << " "; 
	}
	cout << endl;
}

void test_max_stream() 
{
	vector<int> a; // input 
	for (int j = 0; j < 10; j++)
	{
		int x = (rand() % 19) - 9;
		a.push_back(x); 
	}
	print(a);
	int max, max_i;
	max = max_stream(a, &max_i);
	cout << max << " " << max_i << endl;
}

void test_oddmax_evenmin_diff() 
{
	vector<int> a; // input 
	for (int j = 0; j < 10; j++)
	{
		int x = (rand() % 19) - 9;
		a.push_back(x); 
	}
	print(a);
	cout << oddmax_evenmin_diff(a) << endl;
}
int main(int argc, char* argv[])
{
	srand(time(0));
	test_max_stream();
	test_oddmax_evenmin_diff();
	getchar();
	return 0;
}

























