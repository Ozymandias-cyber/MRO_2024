#include "Simplest_Algorithm.h"
float Simplest_Algorithm::euclideanDistance(const vector<float>& point1, const vector<float>& point2)
{
    float sum = 0.0;
    for (size_t i = 0; i < point1.size(); ++i) {
        sum += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return sqrt(sum);
}

vector<vector<float>> Simplest_Algorithm::kCenters(const vector<vector<float>>& data, int k, float h)
{
    vector<vector<float>> centers;
    centers.push_back(data[0]); // Первый центр - первый элемент выборки

    for (int i = 1; i < data.size() && centers.size() < k; ++i) {
        bool canAdd = true;
        for (const auto& center : centers) {
            if (euclideanDistance(data[i], center) <= h) {
                canAdd = false; // Если расстояние меньше или равно h, не добавляем
                break;
            }
        }
        if (canAdd) {
            centers.push_back(data[i]); // Добавляем новый центр
        }
    }

    return centers;
}

void Simplest_Algorithm::Print_centrs(vector<vector<float>> A)
{
    cout << "Выбранные центры кластеров:" << endl;
    for (const auto& A : A) {
        for (const auto& value : A) {
            cout << value << " ";
        }
        cout << endl;
    }

}
