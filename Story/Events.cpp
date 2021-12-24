#include "pch.h"
#include "Events.h"

namespace Story
{
   KeyPressedEvent::KeyPressedEvent(int keyCode) : mKeyCode(keyCode)
   {
   }

   int KeyPressedEvent::GetKeyCode() const
   {
      return mKeyCode;
   }

}
