#include "stdafx.h"
#include <iostream> 
#include <stdlib.h>
#include <tasks.h>
#include <MathUtil.h>
using namespace std; 

int lesson1_max_stream(const vector<int>& a, int* out_index=NULL)
{
	/*
	Возвращает максимальный элемент в векторе a и
	(опционально) записывает его индекс в out_index.
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

int lesson1_oddmax_evenmin_diff(const vector<int>& a)
{
	/*
	Возвращает разность между максимальным нечетным и минимальным
	четным числом в векторе a, если четные и нечетные существуют.
	В противном случае возвращается NULL.
	*/
	int odd_max = NULL, even_min = NULL;
	for (int i = 0; i < a.size(); i++) 
	{
		if (abs(a[i] % 2) == 1) // нечетное 
		{
			if (odd_max == NULL)
			{
				odd_max = a[i];
			}
			else if (a[i] > odd_max)
				odd_max = a[i];
		}
		else // if (a[i] % 2 == 0) // четное 
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
	else // if (odd_max == NULL || even_min == NULL) //если не нашлось нечетных/четных чисел
		return NULL;
}


void test_lesson1_max_stream() 
{
	cout << "==================== Test max_stream (lesson 1) ====================" << endl;
	// Вектор из 10 случайных целых чисел из [-9;9]
	vector<int> a; 
	for (int j = 0; j < 10; j++)
	{
		int x = (rand() % 19) - 9;
		a.push_back(x); 
	}
	print_vector(a);
	int max, max_i;
	max = lesson1_max_stream(a, &max_i);
	cout << "Result: " << max << " " << max_i << endl;
	cout << endl;
}

void test_lesson1_oddmax_evenmin_diff() 
{
	cout << "==================== Test oddmax_evenmin_diff (lesson 1) ====================" << endl;
	// Вектор из 10 случайных целых чисел из [-9;9]
	vector<int> a;  
	for (int j = 0; j < 10; j++)
	{
		int x = (rand() % 19) - 9;
		a.push_back(x); 
	}
	print_vector(a);
	cout << "Result: " << lesson1_oddmax_evenmin_diff(a) << endl;
	cout << endl;
}
