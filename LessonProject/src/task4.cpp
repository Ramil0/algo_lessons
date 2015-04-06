#include "stdafx.h"
#include <iostream>
#include <MathUtil.h>
using namespace std;

int task4(vector<int>& a) 
{
	int run_sum = 0, min_sum = INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		run_sum += a[i];

		if (run_sum < min_sum)
			min_sum = run_sum;
	}
	return run_sum - min_sum;
}

void test_task4()
{
	cout << "================= Test task 4 ========================" << endl;
	static const int arr[] =  {1,-3,5,-4,2};
	vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]));
	print_vector(vec1);
	cout << "Expected output: 3" << endl;
	cout << "Result: " << task4(vec1) << endl;
	cout << endl;
}
