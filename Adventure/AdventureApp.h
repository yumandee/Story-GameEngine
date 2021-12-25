#pragma once

#include "Story.h"
#include "Unit.h"
#include <vector>
#include <string>

class AdventureApp : public Story::StoryApp 
{
public: 
   AdventureApp();
	virtual void OnUpdate() override;
   virtual void OnKeyPressed(Story::KeyPressedEvent& event) override;

private:
   Unit mHero;
   std::vector<Unit> mEnemies;

   int mPoints { 0 };
   int mFrameCounter;
   Story::Shader mShader;
};
