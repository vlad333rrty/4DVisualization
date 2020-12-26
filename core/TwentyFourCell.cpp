#include "../shapes/TwentyFourCell.h"
#include "../transforms/TransformationUtils.h"
#include <algorithm>

std::vector<glm::vec4> generateTesseract(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4,glm::vec4>> &edges);
void createEdges(std::vector<glm::vec4> &vertices,std::vector<std::pair<glm::vec4,glm::vec4>> &edges);
void addVertices(std::vector<glm::vec4> &vertices);

TwentyFourCell::TwentyFourCell(uint edge_len):AbstractRegularShape(edge_len) {
    generateTesseract(vertices, edges);
    createEdges(vertices,edges);
    addVertices(vertices);

    TransformationUtils::scale(vertices,edges,edge_len/5.);
}

void createEdges(std::vector<glm::vec4> &vertices,std::vector<std::pair<glm::vec4,glm::vec4>> &edges){
    for (auto &v : vertices){
        for (int j=0;j<4;j++){
            glm::vec4 vertex;
            vertex[j]= v[j] > 0 ? 2 : -2;
            edges.emplace_back(std::make_pair(v, vertex));
        }
    }
}

void addVertices(std::vector<glm::vec4> &vertices){
    for(int i=0;i<4;i++){
        glm::vec4 vertex;
        vertex[i]=2;
        vertices.push_back(vertex);
        vertex[i]=-2;
        vertices.push_back(vertex);
    }
}

void recFill(std::vector<glm::vec4> &vertices,glm::vec4 vertex,std::vector<std::pair<glm::vec4,glm::vec4>> &edges){
    for (int i=0;i<4;i++){
        if (vertex[i]==-1) {
            glm::vec4 nextVertex(vertex);
            nextVertex[i] = 1;
            if (std::find(vertices.begin(), vertices.end(), nextVertex) == vertices.end()) {
                vertices.emplace_back(nextVertex);
                edges.emplace_back(std::make_pair(vertex,nextVertex));
                recFill(vertices, nextVertex,edges);
            }else{
                edges.emplace_back(std::make_pair(vertex,nextVertex));
            }
        }
    }
}

std::vector<glm::vec4> generateTesseract(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4,glm::vec4>> &edges){
    glm::vec4 vertex=glm::vec4(-1,-1,-1,-1);
    vertices.emplace_back(vertex);
    recFill(vertices,vertex,edges);
    return vertices;
}