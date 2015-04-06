#include "stdafx.h"
#include <iostream>
#include <MathUtil.h>
using namespace std;

int task5(vector<int>& a) 
{
	// „тоб не потер€лс€ последний участок, добавл€ем в конец
	// элемент, обратного знака с последним
	a.push_back(-a[a.size()-1]);
	int last_elem = a[0];
	int global_max = 0;
	int run_sum1 = 0, run_sum2 = 0, min_sum = 0, max_sum = -INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] * last_elem < 0) // смена знака
		{
			if (max(max_sum, run_sum2 - min_sum) > global_max)
				global_max = max(max_sum, run_sum2 - min_sum);
			run_sum1 = 0;
			run_sum2 = 0;
			min_sum = 0;
			max_sum = -INT_MAX;
			
		}
		run_sum1 += a[i] % 5 - 2;
		run_sum2 += a[i] % 7 - 3;

		if (run_sum1 > max_sum)
			max_sum = run_sum1;

		if (run_sum2 < min_sum)
			min_sum = run_sum2;	
		last_elem = a[i];
	}
	a.pop_back();
	return global_max;
}

int local_max(vector<int>& a) 
{
	/*
	¬озвращает максимум из S1 и S2 на массиве "a" 
	(предполагаетс€, что все элементы "a" - одного знака)
	*/
	int run_sum1 = 0, run_sum2 = 0, min_sum = INT_MAX, max_sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		run_sum1 += a[i] % 5 - 2;
		run_sum2 += a[i] % 7 - 3;

		if (run_sum1 > max_sum)
			max_sum = run_sum1;

		if (run_sum2 < min_sum)
			min_sum = run_sum2;
	}
	return max(max_sum, run_sum2 - min_sum);
}

void test_task5()
{
	cout << "================= Test task 5 ========================" << endl;
	static const int arr[] =  {1,2,3,4,5};
	vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]));
	print_vector(vec1);
	cout << "Expected output: 3" << endl;
	cout << "Result: " << task5(vec1) << endl;
	cout << endl;

	static const int arr2[] =  {6,2,8,9};
	vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
	print_vector(vec2);
	cout << "Expected output: 2" << endl;
	cout << "Result: " << task5(vec2) << endl;
	cout << endl;

	static const int arr3[] =  {6,2,8,9,-1,-7,-4,6,6,6};
	vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
	print_vector(vec3);
	cout << "Expected output: 9" << endl;
	cout << "Result: " << task5(vec3) << endl;
	cout << endl;
}
