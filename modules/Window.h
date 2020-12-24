//
// Created by vlad333rrty on 11.12.2020.
//

#ifndef INC_4DVISUALIZATION_WINDOW_H
#define INC_4DVISUALIZATION_WINDOW_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "TransformationManager.h"

class Window{
private:
    int width,height;
    GLFWwindow *window;
public:
    Window(int,int,const std::string&);
    bool isClosed();
    void update();
    void swapBuffers();
    GLFWwindow* getWindowObject();
    int getWidth();
    int getHeight();
};

#endif //INC_4DVISUALIZATION_WINDOW_H
