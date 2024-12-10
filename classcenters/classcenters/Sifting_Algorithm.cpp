#include "Sifting_Algorithm.h"

float Sifting_Algorithm::distance(const std::vector<float>& a, const std::vector<float>& b)
{
    float sum = 0.0f;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

std::vector<float> Sifting_Algorithm::calculateCentroid(const std::vector<std::vector<float>>& cluster)
{
    std::vector<float> centroid(cluster[0].size(), 0.0f);
    for (const auto& point : cluster) {
        for (size_t i = 0; i < point.size(); ++i) {
            centroid[i] += point[i];
        }
    }
    for (size_t i = 0; i < centroid.size(); ++i) {
        centroid[i] /= cluster.size();
    }
    return centroid;
}

std::vector<std::vector<float>> Sifting_Algorithm::kMeans(const std::vector<std::vector<float>>& points, int k, int maxIterations)
{
    srand(static_cast<unsigned int>(time(0)));

    // Инициализация центров кластеров случайными точками
    std::vector<std::vector<float>> centroids(k);
    for (int i = 0; i < k; ++i) {
        centroids[i] = points[rand() % points.size()];
    }

    std::vector<int> labels(points.size());
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // Шаг 1: Присвоение точек кластерам
        for (size_t i = 0; i < points.size(); ++i) {
            float minDistance = std::numeric_limits<float>::max();
            for (int j = 0; j < k; ++j) {
                float dist = distance(points[i], centroids[j]);
                if (dist < minDistance) {
                    minDistance = dist;
                    labels[i] = j;
                }
            }
        }

        // Шаг 2: Обновление центров кластеров
        std::vector<std::vector<std::vector<float>>> clusters(k);
        for (size_t i = 0; i < points.size(); ++i) {
            clusters[labels[i]].push_back(points[i]);
        }

        bool converged = true;
        for (int j = 0; j < k; ++j) {
            if (!clusters[j].empty()) {
                std::vector<float> newCentroid = calculateCentroid(clusters[j]);
                if (distance(centroids[j], newCentroid) > 1e-6) {
                    centroids[j] = newCentroid;
                    converged = false;
                }
            }
        }

        if (converged) {
            break; // Сближение достигнуто
        }
    }

    return centroids;
}
