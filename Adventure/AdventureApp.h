#pragma once

#include "Story.h"
#include "Unit.h"
#include <vector>

class AdventureApp : public Story::StoryApp 
{
public: 
   AdventureApp();
	virtual void OnUpdate() override;
   virtual void OnKeyPressed(Story::KeyPressedEvent& event) override;

private:
   Unit mHero;
   std::vector<Unit> mEnemies;

   int mFrameCounter;
   Story::Shader mShader;
};
