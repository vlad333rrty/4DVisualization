#include "modules/Application.h"
#include "modules/Window.h"
#include "shapes/Tesseract.h"
#include "shapes/Pentachoron.h"
#include "io/Input.h"
#include "shapes/SixteenCell.h"
#include "shapes/TwentyFourCell.h"
#include "shapes/OneHundredAndTwentyCell.h"
#include "shapes/SixHundredCell.h"

Application::Application(Window &window):window(window) {
    TransformationManager::setWidth(window.getWidth());
    TransformationManager::setHeight(window.getHeight());
}

void Application::start() {
    std::vector<AbstractRegularShape> shapes;
    int shapeIndex=0;
    shapes.emplace_back(Pentachoron(40));
    shapes.emplace_back(Tesseract(40));
    shapes.emplace_back(SixteenCell(40));
    shapes.emplace_back(TwentyFourCell(40));
    shapes.emplace_back(OneHundredAndTwentyCell(40));
    shapes.emplace_back(SixHundredCell(40));

    GLFWwindow *windowObject=window.getWindowObject();
    glEnable(GL_DEPTH_TEST);

    while (!window.isClosed()){
        window.update();
        processInput(windowObject,shapes[shapeIndex],shapeIndex);
        shapes[shapeIndex].draw();
        glfwPollEvents();
        window.swapBuffers();
    }
}
