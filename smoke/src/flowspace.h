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

    bool InitFlowSpace();
    void CreateFlows(Vec4 _size, int _resolution);


private:


std::vector<Flow> m_flows;

};


#endif // FLOWSPACE_H
