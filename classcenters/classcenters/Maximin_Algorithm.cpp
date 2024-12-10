#include "Maximin_Algorithm.h"

std::vector<std::vector<float>> Maximin_Algorithm::placeCenters(const std::vector<std::vector<float>>& points, int numCenters)
{
    std::vector<std::vector<float>> centers;

    // »нициализируем генератор случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // ¬ыбор первого центра случайным образом
    centers.push_back(points[rand() % points.size()]);

    while (centers.size() < numCenters) {
        std::vector<float> minDistances(points.size(), std::numeric_limits<float>::max());

        // ƒл€ каждой точки вычисл€ем минимальное рассто€ние до уже выбранных центров
        for (size_t i = 0; i < points.size(); ++i) {
            for (const auto& center : centers) {
                float distance = euclideanDistance(points[i], center);
                minDistances[i] = std::min(minDistances[i], distance);
            }
        }

        // Ќаходим точку с максимальным минимальным рассто€нием
        size_t farthestPointIndex = 0;
        float maxMinDistance = -1.0f;

        for (size_t i = 0; i < minDistances.size(); ++i) {
            if (minDistances[i] > maxMinDistance) {
                maxMinDistance = minDistances[i];
                farthestPointIndex = i;
            }
        }

        // ƒобавл€ем найденный центр
        centers.push_back(points[farthestPointIndex]);
    }

    return centers;
}

float Maximin_Algorithm::euclideanDistance(const std::vector<float>& a, const std::vector<float>& b)
{
    float sum = 0.0f;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return std::sqrt(sum);
}
