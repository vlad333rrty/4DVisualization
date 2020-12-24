//
// Created by vlad333rrty on 21.12.2020.
//

#ifndef INC_4DVISUALIZATION_TRANSFORMATIONMANAGER_H
#define INC_4DVISUALIZATION_TRANSFORMATIONMANAGER_H

#include "../config/Config.h"

class TransformationManager{
private:
    static int width,height,near,far,scale;
public:
    static int getWidth();
    static int getHeight();
    static int getScale();
    static void setWidth(int);
    static void setHeight(int);
    static void ortho();
};

#endif //INC_4DVISUALIZATION_TRANSFORMATIONMANAGER_H
