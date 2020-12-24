#ifndef INC_4DVISUALIZATION_SIXTEENCELL_H
#define INC_4DVISUALIZATION_SIXTEENCELL_H
#include "../modules/AbstractRegularShape.h"

#define SIXTEEN_CELL_VERTEX_NUM 8
#define SIXTEEN_CELL_EDGE_NUM 24

class SixteenCell: public AbstractRegularShape{
public:
    explicit SixteenCell(uint);
};

#endif //INC_4DVISUALIZATION_SIXTEENCELL_H
