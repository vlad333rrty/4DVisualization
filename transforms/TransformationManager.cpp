#include "../modules/TransformationManager.h"
#include <GLFW/glfw3.h>

int TransformationManager::width=DEFAULT_WIDTH;
int TransformationManager::height=DEFAULT_HEIGHT;
int TransformationManager::near=DEFAULT_NEAR;
int TransformationManager::far=DEFAULT_FAR;
int TransformationManager::scale=(width<height ? width/2 : height/2);

int TransformationManager::getHeight() {
    return height;
}

int TransformationManager::getWidth() {
    return width;
}

void TransformationManager::setHeight(int h) {
    height=h;
    if (height<width){
        scale=height/2;
    }
}

void TransformationManager::setWidth(int w) {
    width=w;
    if (width<height){
        scale=width/2;
    }
}

int TransformationManager::getScale() {
    return scale;
}

void TransformationManager::ortho() {
    glViewport(0, 0, width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width,width,-height,height,-near,far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}