#include "TransformationUtils.h"
#include "../modules/TransformationManager.h"

std::vector<float> TransformationUtils::perspectiveProjectionTo3D( float l, float w) {
    float d=(float)TransformationManager::getScale()/(w+l);
    return {d,0,0,0,0,d,0,0,0,0,d,0,0,0,0,1};
}

glm::vec3 TransformationUtils::projectPointTo3D(glm::vec4 &point,float l) {
    glm::vec4 res;
    std::vector<float> mat=TransformationUtils::perspectiveProjectionTo3D(l, point.w);
    for (int i=0;i<4;i++){
        float t=0;
        for (int j=0;j<4;j++){
            t+=mat[4*i+j]*point[j];
        }
        res[i]=t;
    }
    return glm::vec3(res.x,res.y,res.z);
}

void TransformationUtils::setDefaultPosition(std::vector<glm::vec4> &vertices,
                                             std::vector<std::pair<glm::vec4, glm::vec4>> &edges, double k) {
    for (auto & vertex : vertices){
        vertex-=0.5;
        vertex*=k;
    }
    for (auto & edge : edges){
        edge.first-=0.5;
        edge.first*=k;
        edge.second-=0.5;
        edge.second*=k;
    }
}

void TransformationUtils::scale(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4, glm::vec4>> &edges,
                                double k) {
    for (auto &vertex : vertices){
        vertex*=k;
    }
    for (auto & edge : edges){
        edge.first*=k;
        edge.second*=k;
    }
}
