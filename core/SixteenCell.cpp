#include "../shapes/SixteenCell.h"
#include "../transforms/TransformationUtils.h"

SixteenCell::SixteenCell(uint edge_len):AbstractRegularShape(edge_len) {
    for (int i=0;i<4;i++){
        glm::vec4 vertex(0,0,0,0);
        vertex[i]=1;
        vertices.push_back(vertex);
        vertex[i]=-1;
        vertices.push_back(vertex);
    }
    for (int i=0;i<4;i++){
        for (int j=2*(i+1);j<SIXTEEN_CELL_VERTEX_NUM;j++){
            edges.emplace_back(std::make_pair(vertices[2*i],vertices[j]));
            edges.emplace_back(std::make_pair(vertices[2*i+1],vertices[j]));
        }
    }
    TransformationUtils::scale(vertices,edges,edge_len/2.);
}

