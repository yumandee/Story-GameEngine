#include "pch.h"
#include "Sprite.h"
#include "OpenGLimpl/OpenGLSprite.h"

namespace Story
{
   Sprite::Sprite()
   {
      #ifdef STORY_OPENGL
         mSpriteImplementation = std::unique_ptr<SpriteImplementation>{new OpenGLSprite};
      #else
         #only_OpenGL_us_supported_so_far
      #endif
   }
    void Sprite::LoadImage(const std::string& pictureFile)
   {
      mSpriteImplementation->LoadImage(pictureFile);
   }

   int Sprite::GetWidth() const
   {
      return mSpriteImplementation->GetWidth();
   }
   int Sprite::GetHeight() const
   {
      return mSpriteImplementation->GetHeight();
   }
   void Sprite::Bind()
   {
      mSpriteImplementation->Bind();
   }
}