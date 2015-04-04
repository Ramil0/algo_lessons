#include "stdafx.h"
#include <iostream>
#include "my_util.h"
using namespace std;

int task_1_6(vector<int>& a) 
{
	// Чтоб не потерялся последний участок, добавляем в конец
	// элемент, обратного знака с последним
	a.push_back(-a[a.size()-1]);
	int last_elem = a[0];
	int global_min = INT_MAX, local_max = 0;
	int run_sum1 = 0, run_sum2 = 0, min_sum = 0, max_sum = -INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] * last_elem < 0) // смена знака
		{
			local_max = max(max_sum, run_sum2 - min_sum);
			if (local_max < global_min)
				global_min = local_max;
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
	return global_min;
}

// #define INITVECTOR(vec1,t,values) static const t arr[] =  values; vector<t> vec1 arr, arr + sizeof(arr) / sizeof(arr[0]));

void test_task_1_6()
{
	cout << "Test task_1_6" << endl;
	static const int arr[] =  {1,2,3,4,5};
	vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]));
	print_vector(vec1);
	cout << "Expected output: 3" << endl;
	cout << "Result: " << task_1_6(vec1) << endl;
	cout << endl;

	static const int arr2[] =  {6,2,8,9};
	vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
	print_vector(vec2);
	cout << "Expected output: 2" << endl;
	cout << "Result: " << task_1_6(vec2) << endl;
	cout << endl;

	static const int arr3[] =  {6,2,8,9,-1,-7,-4,6,6,6};
	vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
	print_vector(vec3);
	cout << "Expected output: 0" << endl;
	cout << "Result: " << task_1_6(vec3) << endl;
	cout << endl;
}
