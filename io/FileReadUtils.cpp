#include "FileReadUtils.h"
#include <fstream>

void fillVertexArray(std::vector<glm::vec4> &vertices,const std::string &fileName) {
    std::ifstream in(fileName);
    float x,y,z,w;
    while (in>>x>>y>>z>>w){
        vertices.emplace_back(glm::vec4(x,y,z,w));
    }
}

void fillEdgeArray(std::vector<glm::vec4> &vertices, std::vector<std::pair<glm::vec4, glm::vec4>> &edges,const std::string &fileName) {
    std::ifstream in(fileName);
    int u,v;
    while (in>>u>>v){
        edges.emplace_back(std::make_pair(vertices[u],vertices[v]));
    }
}