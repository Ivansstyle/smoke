#include "controls.h"
#include <iostream>

Controls::Controls()
{

}

void Controls::TakeControls(SDL_Event _e)
{
  if (_e.key.state == SDL_RELEASED)
  {
  KillControls();
  }
  m_e = _e;
  std::cout<<"typed input --->"  <<m_e.text.text[0]<<std::endl;

}


void Controls::KillControls()
{
    event.ctrl = false;
    event.down = false;
    event.left = false;
    event.right = false;
    event.up = false;
    event.space = false;
    event.lmouse = false;
    event.rmouse = false;
}
