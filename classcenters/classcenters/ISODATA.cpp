#include "ISODATA.h"

std::vector<std::vector<std::vector<float>>> ISODATA::cluster(const std::vector<std::vector<float>>& points, int maxClusters, float threshold, int maxIterations)
{
    std::vector<std::vector<float>> centroids(maxClusters);
    std::vector<int> clusterAssignments(points.size(), -1);

    // Случайно инициализировать центроиды
    initializeCentroids(points, centroids, maxClusters);

    for (int iter = 0; iter < maxIterations; ++iter) {
        // Шаг 1. Назначьте точки ближайшему центроиду.
        assignPointsToClusters(points, centroids, clusterAssignments);

        // Step 2: Обновление центройдов.
        updateCentroids(points, clusterAssignments, centroids);

        // Step 3: Проверка сходимости.
        if (checkConvergence(centroids, points, clusterAssignments, threshold)) {
            break;
        }
    }

    // Step 4: Group points into clusters
    return groupPointsIntoClusters(points, clusterAssignments, maxClusters);
}

void ISODATA::initializeCentroids(const std::vector<std::vector<float>>& points, std::vector<std::vector<float>>& centroids, int maxClusters)
{
    std::unordered_map<int, bool> usedIndices;
    for (int i = 0; i < maxClusters; ++i) {
        int index;
        do {
            index = rand() % points.size();
        } while (usedIndices[index]);
        usedIndices[index] = true;
        centroids[i] = points[index];
    }
}

void ISODATA::assignPointsToClusters(const std::vector<std::vector<float>>& points, const std::vector<std::vector<float>>& centroids, std::vector<int>& clusterAssignments)
{
    for (size_t i = 0; i < points.size(); ++i) {
        float minDistance = std::numeric_limits<float>::max();
        int bestCluster = -1;

        for (size_t j = 0; j < centroids.size(); ++j) {
            float distance = euclideanDistance(points[i], centroids[j]);
            if (distance < minDistance) {
                minDistance = distance;
                bestCluster = j;
            }
        }

        clusterAssignments[i] = bestCluster;
    }
}

void ISODATA::updateCentroids(const std::vector<std::vector<float>>& points, const std::vector<int>& clusterAssignments, std::vector<std::vector<float>>& centroids)
{
    std::vector<int> counts(centroids.size(), 0);
    std::vector<std::vector<float>> newCentroids(centroids.size(), std::vector<float>(points[0].size(), 0));

    for (size_t i = 0; i < points.size(); ++i) {
        int cluster = clusterAssignments[i];
        if (cluster != -1) {
            counts[cluster]++;
            for (size_t d = 0; d < points[i].size(); ++d) {
                newCentroids[cluster][d] += points[i][d];
            }
        }
    }

    for (size_t j = 0; j < centroids.size(); ++j) {
        if (counts[j] > 0) {
            for (size_t d = 0; d < centroids[j].size(); ++d) {
                newCentroids[j][d] /= counts[j];
            }
            centroids[j] = newCentroids[j];
        }
    }
}

bool ISODATA::checkConvergence(const std::vector<std::vector<float>>& centroids, const std::vector<std::vector<float>>& points, const std::vector<int>& clusterAssignments, float threshold)
{
    for (size_t i = 0; i < centroids.size(); ++i) {
        if (clusterAssignments[i] != -1) {
            float distance = euclideanDistance(points[clusterAssignments[i]], centroids[i]);
            if (distance > threshold) {
                return false;
            }
        }
    }
    return true;
}

float ISODATA::euclideanDistance(const std::vector<float>& a, const std::vector<float>& b)
{
    float sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return std::sqrt(sum);
}

std::vector<std::vector<std::vector<float>>> ISODATA::groupPointsIntoClusters(const std::vector<std::vector<float>>& points, const std::vector<int>& clusterAssignments, int maxClusters)
{
    std::vector<std::vector<std::vector<float>>> clusteredPoints(maxClusters);

    // Группируем точки по кластерам
    for (size_t i = 0; i < points.size(); ++i) {
        int cluster = clusterAssignments[i];
        if (cluster != -1) {
            clusteredPoints[cluster].push_back(points[i]);
        }
    }

    return clusteredPoints;
}


