#pragma once
#ifndef SIMPLEST_ALGORITM_H
#define SIMPLEST_ALGORITM_H
#include <iostream>
#include <vector>
using namespace std;
class Simplest_Algorithm
{
public:
	static float h ;
	static  int k ;
	static float euclideanDistance(const vector<float>& point1, const vector<float>& point2);
	static vector<vector<float>> kCenters(const vector<vector<float>>& data, int k, float h);
	static void Print_centrs(vector<vector<float>> A);
};
#endif // SIMPLEST_ALGORITM_H
