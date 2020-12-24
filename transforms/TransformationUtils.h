#ifndef INC_4DVISUALIZATION_TRANSFORMATIONUTILS_H
#define INC_4DVISUALIZATION_TRANSFORMATIONUTILS_H
#include <vector>
#include <glm/glm.hpp>

class TransformationUtils{
public:
    static std::vector<float> perspectiveProjectionTo3D(float l,float w);
    static glm::vec3 projectPointTo3D(glm::vec4 &point, float l);
    static void setDefaultPosition(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4,glm::vec4>> &edges,double k);
    static void scale(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4,glm::vec4>> &edges,double k);
};

#endif //INC_4DVISUALIZATION_TRANSFORMATIONUTILS_H
