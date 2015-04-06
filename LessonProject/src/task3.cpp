#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <MathUtil.h>
#include <random>
using namespace std;
using namespace Eigen;

vector<Vector3d> generate_points(int M) 
{
	vector<Vector3d> points;
	for (int i= 0; i < M; i ++)
	{
		// —лучайный вектор с концом на единичной сфере
		Vector3d p (2*MathUtil::random01() - 1, 2*MathUtil::random01() - 1, 2*MathUtil::random01() - 1);
		p.normalize();
		points.push_back(p);
	}
	return points;
}

int num_close_points(double max_dist, const vector<Vector3d> points)
{
	int num_close_points = 0;
	vector<Vector3d> close_points = points;
	// —лучайно выбираем 3 точки и удал€ем их из "close_points"
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
		// –ассто€ние от точки "close_points[j]" до плоскости,
		// образованной трем€ точками "selected_points". —читаетс€
		// на основе смешанного и векторного произведени€.
		double h = abs(close_points[j].cross(selected_points[0]).dot(selected_points[1])) / 
			selected_points[0].cross(selected_points[1]).size();
		if (h < max_dist) // если точка близка к плоскости треугольника
			num_close_points ++;
	}
	return num_close_points;
}

void task3(double max_dist, int M)
{
	vector<Vector3d> points = generate_points(M);
	int num_close = num_close_points(max_dist, points);
	cout << num_close << " close point(s)." <<endl;
}

void test_task3() 
{
	cout << "================= Test task 3 ========================" << endl;
	task3(0.3, 10);
	cout << endl;
	
}

