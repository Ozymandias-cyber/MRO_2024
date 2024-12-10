#include "ManhattanMetric.h"

float ManhattanMetric::Get_Avarage_x(const std::vector<std::vector<float>>& A)
{
    float sumX = 0;
    int count = 0; // Для подсчета количества элементов

    // Проверка на пустой вектор
    if (A.empty() || A[0].empty()) {
        return 0; // Или выбросьте исключение, если это необходимо
    }

    // Итерация по всем строкам
    for (int i = 0; i < A.size(); i++) {
        sumX += A[i][0]; // Суммируем элементы первого столбца
        count++; // Увеличиваем счетчик
    }

    return sumX / count; // Возвращаем среднее значение
}


