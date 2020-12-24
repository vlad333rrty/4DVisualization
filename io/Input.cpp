#include "Input.h"

bool isPressed(GLFWwindow *window,int key){
    return glfwGetKey(window,key);
}

void processInput(GLFWwindow *window,AbstractRegularShape &shape,int &index){
    if (isPressed(window,GLFW_KEY_S)){
        shape.move(0,-2,0);
    }
    if (isPressed(window,GLFW_KEY_D)){
        shape.move(2,0,0);
    }
    if (isPressed(window,GLFW_KEY_A)){
        shape.move(-2,0,0);
    }
    if (isPressed(window,GLFW_KEY_W)){
        shape.move(0,2,0);
    }
    if (isPressed(window,GLFW_KEY_N)){
        glScaled(2,2,2);
    }
    if (isPressed(window,GLFW_KEY_F)){
        glScaled(0.5,0.5,0.5);
    }
    if (isPressed(window,GLFW_KEY_X)){
        shape.rotate(2,0,0);
    }
    if (isPressed(window,GLFW_KEY_Y)){
        shape.rotate(0,2,0);
    }
    if (isPressed(window,GLFW_KEY_Z)){
        shape.rotate(0,0,2);
    }
    for (int i=0;i<6;i++){
        if (isPressed(window,GLFW_KEY_1+i)){
            index=i;
            break;
        }
    }
}
