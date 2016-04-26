#ifndef CONTROLS_H
#define CONTROLS_H
#include <SDL2/SDL.h>

struct Event{
  bool up,
       down,
       left,
      right,
       ctrl,
      space,
      lmouse,
      rmouse;
  int mouse_x,
      mouse_y;
  char letter;
};

class Controls
{
public:
  Controls();


  void TakeControls(SDL_Event _e);
  void KillControls();

  Event event;

private:


  SDL_Event m_e;
};

#endif // CONTROLS_H
