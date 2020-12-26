#include "../modules/AbstractRegularShape.h"
#include "../transforms/TransformationUtils.h"
#include <GLFW/glfw3.h>
#include <iostream>
AbstractRegularShape::AbstractRegularShape(uint edge_len, uint vertex_num, uint edge_num) : edge_len(edge_len),vertices(vertex_num),edges(edge_num) {}

void AbstractRegularShape::move(float x, float y, float z) {
    centre.x+=x;
    centre.y+=y;
    centre.z+=z;
}

void AbstractRegularShape::rotate(float x, float y, float z) {
    angle_x+=x;
    angle_y+=y;
    angle_z+=z;
}

void AbstractRegularShape::rotate4D(float xw, float yw, float zw) {
    angle_xw+=xw;
    angle_yw+=yw;
    angle_zw+=zw;
}

glm::vec4 rotatePoint4D(glm::vec4 &point, float xw, float yw, float zw);
void renderEdgePoint(glm::vec4 &point, float angle_xw, float angle_yw, float angle_zw, float l);

void AbstractRegularShape::draw() {
    glPushMatrix();
    glTranslated(centre.x,centre.y,centre.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glRotatef(angle_z,0,0,1);
    glBegin(GL_LINES);
    glColor3d(0.3,0.6,1);
    for (auto &edge:edges){
        renderEdgePoint(edge.first, angle_xw, angle_yw, angle_zw, 1 + edge_len / 2.f);
        renderEdgePoint(edge.second, angle_xw, angle_yw, angle_zw, 1 + edge_len / 2.f);
    }
    glEnd();
    glPopMatrix();
}

glm::vec4 rotatePoint4D(glm::vec4 &point, float xw, float yw, float zw){
    auto rotated=TransformationUtils::rotateXW(point,xw);
    rotated=TransformationUtils::rotateYW(rotated,yw);
    rotated=TransformationUtils::rotateZW(rotated,zw);
    return rotated;
}

void renderEdgePoint(glm::vec4 &point, float angle_xw, float angle_yw, float angle_zw, float l){
    glm::vec4 rotatedPoint=rotatePoint4D(point,angle_xw,angle_yw,angle_zw);
    glm::vec3 v=TransformationUtils::projectPointTo3D(rotatedPoint,  l);
    glVertex3d(v.x,v.y,v.z);
}