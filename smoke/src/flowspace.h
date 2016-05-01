#ifndef FLOWSPACE_H
#define FLOWSPACE_H

#include "flow.h"
#include "Vec4.h"
#include <vector>


class FlowSpace
{
public:
    FlowSpace();
    ~FlowSpace();

    void init(Vec4 _size, int _resolution, Vec4 _origin);
    void createFlows(const Vec4 _size, Vec4 _origin);
    void drawFlows();
    void CalculateFlowSize(Vec4 _size, int _resolution);


private:


    std::vector<Flow> m_flows;
    GLfloat m_flowsize;

};


#endif // FLOWSPACE_H

/* TRASHBIN
 *
 *
 * bool InitFlowSpace();
 *
 *
 *
 */
