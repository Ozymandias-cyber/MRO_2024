#include"Ho_ckoshap.h"
#include"Read_file.h"
#include "ManhattanMetric.h"


int main() {
	setlocale(LC_ALL, "Russian");
	float Hk = 0.5;
	PointGenerator pointGen;
	pointGen.processInputFile("C:/MRO_vr_5_fin/input.txt");

	Ho_ckoshap vec; 
	ManhattanMetric metrica;
	cout<<metrica.Get_Avarage_x(vec.Initial_matrix("points_set_1.txt"));
	//vec.PrintMatrix(vec.Matrix_Multiple(vec.Initial_matrix("points_set_1.txt"), vec.Matrix_Transpose(vec.Initial_matrix("points_set_1.txt"))));
	//cout << vec.Get_determinant(vec.Matrix_Multiple(vec.Initial_matrix("points_set_1.txt"), vec.Matrix_Transpose(vec.Initial_matrix("points_set_1.txt"))));

	return 0;
	//vec.PrintMatrix(vec.Pseudoinverse_matrix(Initial_matrix)); Вывод псевдообратной проверка

	//std::vector<std::vector<float>> W = vec.Matrix_Multiple\
		(vec.Pseudoinverse_matrix(Initial_matrix),\
			vec.Creat_positive_vector(Initial_matrix));

	//vec.PrintMatrix(vec.Checking_for_positivity(W));


}