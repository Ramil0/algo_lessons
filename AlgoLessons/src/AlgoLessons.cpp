// Lesson1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "tasks.h"
#include "my_util.h"
#include <iostream> 
using namespace std; 

int max_stream(const vector<int>& a, int* out_index=NULL)
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

int oddmax_evenmin_diff(const vector<int>& a)
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


void test_max_stream() 
{
	cout << "Test max_stream" << endl;
	// Вектор из 10 случайных целых чисел из [-9;9]
	vector<int> a; 
	for (int j = 0; j < 10; j++)
	{
		int x = (rand() % 19) - 9;
		a.push_back(x); 
	}
	print_vector(a);
	int max, max_i;
	max = max_stream(a, &max_i);
	cout << "Result: " << max << " " << max_i << endl;
	cout << endl;
}

void test_oddmax_evenmin_diff() 
{
	cout << "Test oddmax_evenmin_diff" << endl;
	// Вектор из 10 случайных целых чисел из [-9;9]
	vector<int> a;  
	for (int j = 0; j < 10; j++)
	{
		int x = (rand() % 19) - 9;
		a.push_back(x); 
	}
	print_vector(a);
	cout << "Result: " << oddmax_evenmin_diff(a) << endl;
	cout << endl;
}

int main(int argc, char* argv[])
{
	//srand(time(0));
	//test_max_stream();
	//test_oddmax_evenmin_diff();
	//test_task_1_1();
	//test_task_1_2();
	//test_task_1_3();
	//test_task_1_4();
	//test_task_1_5();
	//test_task_1_6();

	//test_task_1_2_new();
	test_task_1_7();
	getchar();
	return 0;
}