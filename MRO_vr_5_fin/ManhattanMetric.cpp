#include "ManhattanMetric.h"

float Metrix::Evclid( std::vector<float> A, std::vector<float>  B)
{
	float C = 0;
	for (int i = 0; i < A.size(); i++) {
		C = C + pow((B[i] - A[i]), 2);
	}
	return pow(C, 0.5);
}

float Metrix::Manhatans(std::vector<float> A, std::vector<float> B)
{
	float C = 0;
	for (int i = 0; i < A.size(); i++) {
		C = C + (B[i] - A[i]);
	}
	return abs(C);
}

bool Metrix::Upgrate_for_simple_Evclid(std::vector<std::vector<float>> A, std::vector<float> B)
{
	for (int i = 0; i < A.size(); i++) {
		
	}
	return false;
}
