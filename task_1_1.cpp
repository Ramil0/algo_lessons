#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "my_util.h"
using namespace std;

int task_1_1(const vector<int>& a)
{
	/*
	Returns the difference between the maximal even integer (if any) and 
	the mininmal even integer (if any) if they are both surrounded by
	odd integers. Expects a vetor of length > 1.
	Otherwise, returns NULL.
	*/
	int even_max = NULL, even_min = NULL;
	for (int i = 0; i < a.size(); i++) 
	{
		if (abs(a[i] % 2) == 0) // even 
		{
			if (((i == 0) && (a[i+1] % 2 == 1)) || ((abs(a[i-1] % 2) == 1) && (abs(a[i+1] % 2) == 1)) ||
				 ((i == a.size() - 1) && (a[i-1] % 2 == 1)))
			{
				if (even_max == NULL)
				{
					even_max = a[i];
				}
				else if (a[i] > even_max)
					even_max = a[i];
				if (even_min == NULL)
				{
					even_min = a[i];
				}
				else if (a[i] < even_min)
					even_min = a[i];
				}
			}
	}
	if (even_max!= NULL && even_min != NULL)
	{
		return abs(even_max - even_min);
	}
	else return NULL;
}

void test_task_1_1() 
{
	cout << "Test task_1_1" << endl;
	static const int arr[] =  {1,3,4,-1,-2,3,0,4,3,3};
	vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]));
	print_vector(vec1);
	cout << "Expected output: 6" << endl;
	cout << "Result: " << task_1_1(vec1) << endl;
	cout << endl;

	static const int arr2[] =  {1,3,4,3};
	vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
	print_vector(vec2);
	cout << "Expected output: 0" << endl;
	cout << "Result: " << task_1_1(vec2) << endl;
	cout << endl;

	static const int arr3[] =  {2,1};
	vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
	print_vector(vec3);
	cout << "Expected output: NULL" << endl;
	cout << "Result: " << task_1_1(vec3) << endl;
	cout << endl;
}
