#include <iostream>
#include <GLFW/glfw3.h>
#include "../modules/Window.h"

const std::string Window_GLFW_initialize_error="Error occurred initializing glfw";
const std::string Window_GLFW_window_creating_error="Error occurred creating glfw window";

Window::Window(int width,int height,const std::string& title):width(width),height(height){
    if (!glfwInit()){
        throw std::runtime_error(Window_GLFW_initialize_error);
    }
    glfwWindowHint(GLFW_RESIZABLE,GLFW_TRUE);
    window=glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);
    if (!window){
        throw std::runtime_error(Window_GLFW_window_creating_error);
    }

    glfwMakeContextCurrent(window);
}

void Window::update(){
    glfwGetWindowSize(window,&width,&height);

    TransformationManager::setWidth(width);
    TransformationManager::setHeight(height);

    TransformationManager::ortho();

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::isClosed() {
    return glfwWindowShouldClose(window);
}

GLFWwindow *Window::getWindowObject() {
    return window;
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}
