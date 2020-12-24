//
// Created by vlad333rrty on 20.12.2020.
//

#ifndef INC_4DVISUALIZATION_APPLICATION_H
#define INC_4DVISUALIZATION_APPLICATION_H
#include "Window.h"

class Application{
private:
    Window window;
public:
    explicit Application(Window&);
    void start();
};

#endif //INC_4DVISUALIZATION_APPLICATION_H
