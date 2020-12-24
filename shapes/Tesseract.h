//
// Created by vlad333rrty on 11.12.2020.
//

#ifndef INC_4DVISUALIZATION_TESSERACT_H
#define INC_4DVISUALIZATION_TESSERACT_H
#include <glm/glm.hpp>
#include <vector>
#include "../modules/AbstractRegularShape.h"

#define TESSERACT_VERTEX_NUM 16
#define TESSERACT_EDGE_NUM 32

class Tesseract: public AbstractRegularShape{
private:
    void createFrame(glm::vec4 vertex);
public:
    explicit Tesseract(int edge_len);
};

#endif //INC_4DVISUALIZATION_TESSERACT_H
