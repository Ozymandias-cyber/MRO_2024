#include "Forel_Algoritm.h"

using namespace std;

std::vector<std::vector<std::vector<float>>> Forel_Algoritm::cluster(const std::vector<std::vector<float>>& points, float radius)
{
    std::vector<std::vector<std::vector<float>>> clusters;
    std::vector<bool> visited(points.size(), false);

    for (size_t i = 0; i < points.size(); ++i) {
        if (!visited[i]) {
            std::vector<std::vector<float>> newCluster;
            std::vector<float> center = points[i];

            for (size_t j = 0; j < points.size(); ++j) {
                if (!visited[j] && isInCluster(center, points[j], radius)) {
                    newCluster.push_back(points[j]);
                    visited[j] = true;
                }
            }

            if (!newCluster.empty()) {
                clusters.push_back(newCluster);
            }
        }
    }

    return clusters;
}
void Forel_Algoritm::Print_ansver(std::vector<std::vector<std::vector<float>>> A)
{
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            for (int k = 0; k < A[i][j].size(); k++) {
                std::cout << A[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
    bool Forel_Algoritm::isInCluster(const std::vector<float>&center, const std::vector<float>&point, float radius)
    {
        float distance = 0.0f;
        for (size_t i = 0; i < center.size(); ++i) {
            distance += std::pow(center[i] - point[i], 2);
        }
        distance = std::sqrt(distance);
        return distance <= radius;
    }
