#include "space.h"

Space::Space() : m_size(0,0,0)
{

}

Space::~Space()
{

}

void Space::init()
{

}


Vec4 Space::GetSize()
{
    return m_size;
}

void Space::SetSize(Vec4 _size)
{
    m_size = _size;
}

Vec4 Space::isInSpace(Vec4 _ppos)
{
    if      (_ppos.m_x > m_size.m_x) {_ppos.m_x = m_size.m_x; _ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_y > m_size.m_y) {_ppos.m_y = m_size.m_y; _ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_z > m_size.m_z) {_ppos.m_z = m_size.m_z; _ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_x < -m_size.m_x){_ppos.m_x = -m_size.m_x;_ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_y < -m_size.m_y){_ppos.m_y = -m_size.m_y;_ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_z < -m_size.m_z){_ppos.m_z = -m_size.m_z;_ppos.m_w = -2;return _ppos;}
    else _ppos.m_w=1;return _ppos;
}



