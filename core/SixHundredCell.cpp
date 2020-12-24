#include "../shapes/SixHundredCell.h"
#include "../transforms/TransformationUtils.h"
#include "../io/FileReadUtils.h"
#include <fstream>

#define VERTICES_FILE_NAME "polytopeData/600cell/600-cell_vertices.txt"
#define EDGES_FILE_NAME "polytopeData/600cell/600-cell_correspondences.txt"

SixHundredCell::SixHundredCell(uint edge_len):AbstractRegularShape(edge_len) {
    fillVertexArray(vertices,VERTICES_FILE_NAME);
    fillEdgeArray(vertices,edges,EDGES_FILE_NAME);
    TransformationUtils::scale(vertices,edges,edge_len/5.);
}
