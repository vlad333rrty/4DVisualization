#include <iostream>
#include "modules/Window.h"
#include "modules/Application.h"

int main(int argc,char **argv) {
    Window window=Window(800,800,"4DVisualization");
    auto app=Application(window);
    app.start();
    return 0;
}
