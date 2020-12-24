#ifndef INC_4DVISUALIZATION_PENTACHORON_H
#define INC_4DVISUALIZATION_PENTACHORON_H
#include "../modules/AbstractRegularShape.h"
#include <vector>
#include <glm/glm.hpp>

#define PENTACHORON_VERTEX_NUM 5
#define PENTACHORON_EDGE_NUM 10

class Pentachoron: public AbstractRegularShape {
public:
    explicit Pentachoron(int);
};


#endif //INC_4DVISUALIZATION_PENTACHORON_H
