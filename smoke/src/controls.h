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
         letter != _rhs.letter) return true;
    else return false;
  }
};

class Controls
{

public:
  Controls();
  //~Controls();
  void TakeControls(SDL_Event *_e);

  Event     event;

  void   KillControls();
  Event* GiveControls();

private:

  SDL_Event*  m_e;

};

#endif // CONTROLS_H
