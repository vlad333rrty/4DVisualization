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

void AbstractRegularShape::rotate(int x, int y, int z) {
    angle_x+=x;
    angle_y+=y;
    angle_z+=z;
}

void AbstractRegularShape::draw() {
    glPushMatrix();
    glTranslated(centre.x,centre.y,centre.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glRotatef(angle_z,0,0,1);
    glBegin(GL_LINES);
    glColor3d(0.3,0.6,1);
    for (auto &edge:edges){
        glm::vec3 v=TransformationUtils::projectPointTo3D(edge.first,  1+edge_len/2.f);
        glVertex3d(v.x,v.y,v.z);
        v=TransformationUtils::projectPointTo3D(edge.second,  1+edge_len/2.f);
        glVertex3d(v.x,v.y,v.z);
    }
    glEnd();
    glPopMatrix();
}