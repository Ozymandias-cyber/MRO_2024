#include "ManhattanMetric.h"

float ManhattanMetric::Get_Avarage_x(const std::vector<std::vector<float>>& A)
{
    float sumX = 0;
    int count = 0; // ��� �������� ���������� ���������

    // �������� �� ������ ������
    if (A.empty() || A[0].empty()) {
        return 0; // ��� ��������� ����������, ���� ��� ����������
    }

    // �������� �� ���� �������
    for (int i = 0; i < A.size(); i++) {
        sumX += A[i][0]; // ��������� �������� ������� �������
        count++; // ����������� �������
    }

    return sumX / count; // ���������� ������� ��������
}


