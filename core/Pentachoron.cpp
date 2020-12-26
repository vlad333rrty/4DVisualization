#include "../shapes/Pentachoron.h"
#include "../transforms/TransformationUtils.h"

Pentachoron::Pentachoron(int edge_len): AbstractRegularShape(edge_len, PENTACHORON_VERTEX_NUM) {
    double half_len=edge_len/2.;
    vertices[0]=glm::vec4(0,0,0,0);
    vertices[1]=glm::vec4(1,1,0,0);
    vertices[2]=glm::vec4(1,0,1,0);
    vertices[3]=glm::vec4(0,1,1,0);
    double c=4/9.;
    double w=sqrt(5)/2;
    vertices[4]=glm::vec4(c,c,c,w);

    for (int i=0;i<vertices.size();i++){
        for (int j=i+1;j<vertices.size();j++){
            edges.emplace_back(std::make_pair(vertices[i],vertices[j]));
        }
    }

    TransformationUtils::translate(vertices,edges,glm::vec4(-0.5));
    TransformationUtils::scale(vertices,edges,half_len);
}