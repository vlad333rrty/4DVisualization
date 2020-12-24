#include "../shapes/OneHundredAndTwentyCell.h"
#include "../transforms/TransformationUtils.h"
#include "../io/FileReadUtils.h"
#include <fstream>

#define VERTICES_FILE_NAME "polytopeData/120cell/120-cell_vertices.txt"
#define EDGES_FILE_NAME "polytopeData/120cell/120-cell_correspondences.txt"

OneHundredAndTwentyCell::OneHundredAndTwentyCell(uint edge_len): AbstractRegularShape(edge_len) {
    fillVertexArray(vertices,VERTICES_FILE_NAME);
    fillEdgeArray(vertices,edges,EDGES_FILE_NAME);
    TransformationUtils::scale(vertices,edges,edge_len/5.);
}