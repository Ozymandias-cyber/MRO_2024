#include"Ho_ckoshap.h"
#include"Read_file.h"
#include "ManhattanMetric.h"
#include <iostream>
#include "Perseptron.h"


int main() {
	setlocale(LC_ALL, "Russian");
	float Hk = 0.5;

	//PointGenerator pointGen;
	//pointGen.processInputFile("C:/MRO_vr_5_fin/input.txt");
	Ho_ckoshap vec;

	Metrix metrica;
	std::vector<float> A = { 1,2 };
	std::vector<float> B = { 3,5 };
	std::vector<std::vector<float>> Q = { {1,4},{45,3},{5,3}, {8,6} };
	
	//for (int i = 1; i < pointGen.CountMatrix + 1; i++) {
	//	for (int j = i+1; j < pointGen.CountMatrix + 1; j++) {
	//		if (i != j) {
	//			vec.PrintMatrix(vec.Ho__ckoshap(vec.Initial_matrix("points_set_" + std::to_string(j) + ".txt"), vec.Initial_matrix("points_set_" + std::to_string(i) + ".txt"), Hk));
	//			vec.Save_ho_vector_to_txt(vec.Ho__ckoshap(vec.Initial_matrix("points_set_" + std::to_string(j) + ".txt"), vec.Initial_matrix("points_set_" + std::to_string(i) + ".txt"), Hk), "C:/MRO_vr_5_fin/output_ho_vector.txt");
	//		}
	//	}
	//}
	//return 0;

	//cout << Metrix::Evclid(A, B)<< '\n';
	//cout << Metrix::Manhatans(A, B)<< '\n';

	
	std::vector<std::vector<float>> Input = { {1,4,23},{45,3,2},{5,3,1} };

	std::vector<std::vector<float>> Weight = { {1,4,7},{45,3,8},{5,3,3} };

	std::vector<std::vector<float>> Weight_2 = { {-0.1,0.6, 0}, {0.5,0,-0.7}, {0.28, -0.6,-1} };
	
	cout << Perseptron::Func_activ(Perseptron::Summator(Perseptron::Multiple(Input, Weight)))<<'\n';
	cout << Perseptron::Func_activ(Perseptron::Summator(Perseptron::Multiple(Input, Weight_2)))<<'\n';
}
