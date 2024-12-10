#include "Perseptron.h"

std::vector<std::vector<float>> Perseptron::Multiple(std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B)
{
    {
        if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) {
            throw std::invalid_argument("������� �� ������ ���� �������.");
        }

        int rowA = A.size();            // ���������� ����� � ������ �������
        int columnA = A[0].size();      // ���������� �������� � ������ �������
        int columnB = B[0].size();      // ���������� �������� �� ������ �������

        // �������� �� ����������� ���������
        if (columnA != B.size()) {
            throw std::invalid_argument("���������� �������� ������ ������� ������ ���� ����� ���������� ����� ������ �������.");
        }
        // ������������� �������������� ������� C �������� rowA x columnB
        std::vector<std::vector<float>> Multiplied_Matrix(rowA, std::vector<float>(columnB, 0));

        // ��������� ������
        for (int r = 0; r < rowA; r++) {
            for (int c = 0; c < columnB; c++) {
                for (int k = 0; k < columnA; k++) {
                    Multiplied_Matrix[r][c] += A[r][k] * B[k][c];
                }
            }
        }
        return Multiplied_Matrix;
    }
}

float Perseptron::Summator(std::vector<std::vector<float>> A)
{
    float sum = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            sum = sum + A[i][j];
        }
    }
    //cout << sum<<'\n';
    return sum;
}

float Perseptron::Func_activ (float x)
{
    float max = 0;
    if (x > max) {
        return 1;
    }
    else {
        return max;
    }
}
