#include "../shapes/Tesseract.h"
#include "../transforms/TransformationUtils.h"
#include <algorithm>

Tesseract::Tesseract(int edge_len) : AbstractRegularShape(edge_len) {
    vertices.emplace_back(glm::vec4(0, 0, 0, 0));
    createFrame(vertices[0]);
    TransformationUtils::translate(vertices,edges,glm::vec4(-0.5));
    TransformationUtils::scale(vertices,edges,edge_len/2.);
}

void Tesseract::createFrame(glm::vec4 vertex) {
    for (int i=0;i<4;i++){
        if (vertex[i]==0){
            glm::vec4 nextVertex(vertex);
            nextVertex[i]=1;
            if (std::find(vertices.begin(),vertices.end(),nextVertex)!=vertices.end()){
                edges.emplace_back(std::make_pair(vertex,nextVertex));
            }else{
                vertices.emplace_back(nextVertex);
                edges.emplace_back(std::make_pair(vertex,nextVertex));
                createFrame(nextVertex);
            }
        }
    }
}