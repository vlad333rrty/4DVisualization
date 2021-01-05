#include "TransformationUtils.h"

#include <cmath>
#include "../modules/TransformationManager.h"

std::vector<float> TransformationUtils::perspectiveProjectionTo3D( float l, float w) {
    float d=(float)TransformationManager::getScale()/(w+l);
    return {d,0,0,0,0,d,0,0,0,0,d,0,0,0,0,1};
}

glm::vec4 mulMatrixVec(std::vector<float> &matrix,glm::vec4 &vec);

glm::vec3 TransformationUtils::projectPointTo3D(glm::vec4 &point,float l) {
    std::vector<float> matrix=TransformationUtils::perspectiveProjectionTo3D(l, point.w);
    glm::vec4 res=mulMatrixVec(matrix,point);
    return glm::vec3(res.x,res.y,res.z);
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

void TransformationUtils::translate(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4, glm::vec4>> &edges,
                               glm::vec4 v) {
    for (auto & vertex : vertices){
        vertex+=v;
    }
    for (auto & edge : edges){
        edge.first+=v;
        edge.second+=v;
    }
}

glm::vec4 TransformationUtils::rotateXW(glm::vec4 &point, float radians) {
    auto cosValue=std::cos(radians);
    auto sinValue= std::sin(radians);
    std::vector<float> rotationMatrix = {cosValue,-sinValue,0,0,0,1,0,0,0,0,1,0,0,0,sinValue,cosValue};
    return mulMatrixVec(rotationMatrix,point);
}

glm::vec4 TransformationUtils::rotateYW(glm::vec4 &point, float radians) {
    auto cosValue=std::cos(radians);
    auto sinValue=std::sin(radians);
    std::vector<float> rotationMatrix={1,0,0,0,0,cosValue,-sinValue,0,0,0,1,0,0,0,sinValue,cosValue};
    return mulMatrixVec(rotationMatrix,point);
}

glm::vec4 TransformationUtils::rotateZW(glm::vec4 &point, float radians) {
    auto cosValue=std::cos(radians);
    auto sinValue=std::sin(radians);
    std::vector<float> rotationMatrix={1,0,0,0,0,1,0,0,0,0,cosValue,-sinValue,0,0,sinValue,cosValue};
    return mulMatrixVec(rotationMatrix,point);
}

glm::vec4 mulMatrixVec(std::vector<float> &matrix,glm::vec4 &vec){
    glm::vec4 res;
    for (int i=0;i<4;i++){
        float t=0;
        for (int j=0;j<4;j++){
            t+=matrix[4*i+j]*vec[j];
        }
        res[i]=t;
    }
    return res;
}