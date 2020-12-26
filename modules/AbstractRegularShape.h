#ifndef INC_4DVISUALIZATION_ABSTRACTREGULARSHAPE_H
#define INC_4DVISUALIZATION_ABSTRACTREGULARSHAPE_H
#include <glm/glm.hpp>
#include <vector>

class AbstractRegularShape{
protected:
    uint edge_len;
    glm::vec3 centre;
    float angle_x{},angle_y{},angle_z{},angle_xw{},angle_yw{},angle_zw{};
    std::vector<glm::vec4> vertices;
    std::vector<std::pair<glm::vec4,glm::vec4>> edges;
public:
    virtual void draw();
    virtual void move(float x, float y, float z);
    virtual void rotate(float x, float y, float z);
    virtual void rotate4D(float xw, float yw, float zw);
    explicit AbstractRegularShape(uint, uint vertex_num=0, uint edge_num=0);
};

#endif //INC_4DVISUALIZATION_ABSTRACTREGULARSHAPE_H
