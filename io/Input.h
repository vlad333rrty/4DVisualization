#ifndef INC_4DVISUALIZATION_INPUT_H
#define INC_4DVISUALIZATION_INPUT_H
#include "../modules/AbstractRegularShape.h"
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window,AbstractRegularShape &shape,int &index);

bool isPressed(GLFWwindow *window,int key);


#endif //INC_4DVISUALIZATION_INPUT_H
