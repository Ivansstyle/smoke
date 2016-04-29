#ifndef CONTROLS_H
#define CONTROLS_H
#include <SDL2/SDL.h>

struct Event{
  bool up,
       down,
       left,
      right,
       ctrl,
      shift,
      space,
      lmouse,
      rmouse;
  int mouse_x,
      mouse_y;
  char letter;

  bool operator !=(const Event &_rhs) const
  {
    if ( up != _rhs.up &&
         down != _rhs.down &&
         left != _rhs.left &&
         right != _rhs.right &&
         ctrl != _rhs.ctrl &&
         shift != _rhs.shift &&
         space != _rhs.space &&
         lmouse != _rhs.lmouse &&
         rmouse != _rhs.rmouse &&
         //mouse_x != _rhs.mouse_x &&
         //mouse_y != _rhs.mouse_y &&
         letter != _rhs.letter) return true;
    else return false;
  }
};

class Controls
{

public:
  Controls();

  void KillControls();

  Event* GiveControls();

  void TakeControls(SDL_Event *_e);

  Event event;

  SDL_Event* m_e;

private:


};

#endif // CONTROLS_H
