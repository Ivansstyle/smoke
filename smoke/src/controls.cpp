#include "controls.h"
#include <iostream>

Controls::Controls()
{
  KillControls();
}

void Controls::TakeControls(SDL_Event* _e)
{
  m_e = _e;

  if (m_e->key.state == SDL_RELEASED)
  {
   KillControls();
  }
  if( m_e->type == SDL_TEXTINPUT )
  {
    // std::cout<<"typed input ---> " << m_e->text.text[0] <<std::endl;

    //if (_e->text.text[0] != ' '){
    event.letter = m_e->text.text[0];
    //}

  }
  if (m_e->type == SDL_KEYDOWN)
  {
    if (m_e->key.keysym.sym == SDLK_LEFT) { event.left = true;}
    if (m_e->key.keysym.sym == SDLK_RIGHT) { event.right = true;}
    if (m_e->key.keysym.sym == SDLK_UP) { event.up = true;}
    if (m_e->key.keysym.sym == SDLK_DOWN) { event.down = true;}
    if (m_e->key.keysym.sym == SDLK_SPACE) { event.space = true;}
    if (m_e->key.keysym.sym == SDLK_LCTRL) { event.ctrl = true;}
    if (m_e->key.keysym.sym == SDLK_LSHIFT ) {event.shift = true;}
  }

  SDL_GetMouseState(&event.mouse_x, &event.mouse_y);


}


void Controls::KillControls()
{
  Event m_event;

//  if (m_e->key.keysym.sym != SDLK_LEFT) { event.left = false;}
//  if (m_e->key.keysym.sym != SDLK_RIGHT) { event.right = false;}
//  if (m_e->key.keysym.sym != SDLK_UP) { event.up = false;}
//  if (m_e->key.keysym.sym != SDLK_DOWN) { event.down = false;}
//  if (m_e->key.keysym.sym != SDLK_SPACE) { event.space = false;}
//  if (m_e->key.keysym.sym != SDLK_LCTRL) { event.ctrl = false;}
//  if (m_e->key.keysym.sym != SDLK_LSHIFT ) {event.shift = false;}

    event.shift = false;
    event.ctrl = false;
    event.down = false;
    event.left = false;
    event.right = false;
    event.up = false;
    event.space = false;
    event.lmouse = false;
    event.rmouse = false;
    event.letter = 0;
if (m_event != event)
    std::cout<<"Control Kill Call"<<std::endl;

}

Event* Controls::GiveControls()
{
  return &event;
}
