#pragma once

#include "pch.h"
#include "StoryUtils.h"
#include "SpriteImplementation.h"
#include "glad/glad.h"

namespace Story 
{
   class STORY_API OpenGLSprite : public SpriteImplementation
   {
   public:
      OpenGLSprite();
      OpenGLSprite(const std::string& pictureFile);
      ~OpenGLSprite();

      virtual void LoadImage(const std::string& pictureFile) override;
      virtual int GetWidth() const override;
      virtual int GetHeight() const override;
      virtual void Bind() override;

   private:
      unsigned int mTexture { 0 };
      int mWidth {0};
      int mHeight {0};
   };
}