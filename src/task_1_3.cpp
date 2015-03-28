#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "my_util.h"
#include <random>

using namespace std;
using namespace Eigen;

double random01()
{
	return double(rand() % INT_MAX)/INT_MAX;
}


vector<Vector3d> generate_points(int M) 
{
	vector<Vector3d> points;
	for (int i= 0; i < M; i ++)
	{
		// ��������� ������ � ������ �� ��������� �����
		Vector3d p (2*random01() - 1, 2*random01() - 1, 2*random01() - 1);
		p.normalize();
		points.push_back(p);
	}
	return points;
}

int num_close_points(double max_dist, const vector<Vector3d> points)
{
	int num_close_points = 0;
	vector<Vector3d> close_points = points;
	// �������� �������� 3 ����� � ������� �� �� "close_points"
	vector<Vector3d> selected_points;
	for (int i = 0; i < 3; i ++)
	{
		int rand_index = rand() % close_points.size();
		Vector3d point = close_points[rand_index];
		selected_points.push_back(point);
		close_points.erase(close_points.begin() + rand_index);
	}
	for (int j = 0; j < close_points.size(); j ++)
	{
		// ���������� �� ����� "close_points[j]" �� ���������,
		// ������������ ����� ������� "selected_points". ���������
		// �� ������ ���������� � ���������� ������������.
		double h = abs(close_points[j].cross(selected_points[0]).dot(selected_points[1])) / 
			selected_points[0].cross(selected_points[1]).size();
		if (h < max_dist) // ���� ����� ������ � ��������� ������������
			num_close_points ++;
	}
	return num_close_points;
}

void task_1_3(double max_dist, int M)
{
	vector<Vector3d> points = generate_points(M);
	int num_close = num_close_points(max_dist, points);
	cout << num_close << " close point(s)." <<endl;
}

void test_task_1_3() 
{
	cout << "Test task_1_3" << endl;
	task_1_3(0.3, 10);
	
}

