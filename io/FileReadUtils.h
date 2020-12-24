#ifndef INC_4DVISUALIZATION_FILEREADUTILS_H
#define INC_4DVISUALIZATION_FILEREADUTILS_H
#include <string>
#include <vector>
#include <glm/glm.hpp>

void fillVertexArray(std::vector<glm::vec4>&,const std::string&);
void fillEdgeArray(std::vector<glm::vec4>&,std::vector<std::pair<glm::vec4,glm::vec4>>&,const std::string&);

#endif //INC_4DVISUALIZATION_FILEREADUTILS_H
