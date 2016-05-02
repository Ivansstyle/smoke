#ifndef FLOWSPACE_H
#define FLOWSPACE_H

#include "flow.h"
#include "particle.h"
#include <vector>


class FlowSpace
{
public:
    FlowSpace();
    ~FlowSpace();

    void init(Vec4 _size, int _resolution, Vec4 _origin);
    void update();

    void createFlows(const Vec4 _size, Vec4 _origin);
    void drawFlows();
    void CalculateFlowSize(int _resolution);

    void SetSpherePtr(ControlSphere* _ptr);
    void FlowSearch(Particle* _pPtr);

private:

    std::vector<Flow>   m_flows;
    GLfloat             m_flowsize;
    ControlSphere*      m_spherePtr;

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
