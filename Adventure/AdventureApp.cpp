#include "pch.h"

#include "AdventureApp.h"

AdventureApp::AdventureApp() : mHero("Assets/Textures/kirby.png", 0, 0, 10), mFrameCounter(0)
{
    mShader.Load("Assets/Shaders/myVertexShader.glsl", "Assets/Shaders/myFragmentShader.glsl");
    mShader.SetVec2IntUniform(
        "screenSize",
        800,
        600);
}

void AdventureApp::OnUpdate()
{
   mHero.UpdatePosition();
   //update existing viruses
   for (auto & enemy: mEnemies)
   {
      enemy.UpdatePosition();
   }

   if (mFrameCounter % FRAMES_PER_SECOND == 0 && mEnemies.size() < 10) 
   {
      int newX {rand() % (700)};
      int newY {rand() % (500)};
      Unit::Direction newDir;
      int dirVal { rand() % 4 };
      if (dirVal == 0)
         newDir =Unit::Direction::Down;
      else if (dirVal == 1)
         newDir = Unit::Direction::Up;
      else if (dirVal == 2)
         newDir = Unit::Direction::Left;
      else
         newDir = Unit::Direction::Right;
      mEnemies.push_back(Unit{ "Assets/Textures/enemy.png", newX, newY, 0 });
      mEnemies.back().SetDirection(newDir);
   }

   auto it = mEnemies.begin();
   while(it != mEnemies.end()) 
   {
      if(mHero.CollideWith(*it))
         it = mEnemies.erase(it);
      else 
         it++;
   }

   mHero.Draw(mShader);

   for (auto &enemy : mEnemies)
   {
      enemy.Draw(mShader);
   }

   mFrameCounter++;
}

void AdventureApp::OnKeyPressed(Story::KeyPressedEvent& event)
{
   switch(event.GetKeyCode())
   {
      case STORY_KEY_LEFT:
         // mHero.SetPosX(mHero.GetPosX() - mHero.GetSpeed());
         mHero.SetDirection(Unit::Direction::Left);
         break;
      case STORY_KEY_RIGHT:
         // mHero.SetPosX(mHero.GetPosX() + mHero.GetSpeed());
         mHero.SetDirection(Unit::Direction::Right);

         break;
      case STORY_KEY_DOWN:
         // mHero.SetPosY(mHero.GetPosY() - mHero.GetSpeed());
         mHero.SetDirection(Unit::Direction::Down);

         break;
      case STORY_KEY_UP:
         // mHero.SetPosY(mHero.GetPosY() + mHero.GetSpeed());
         mHero.SetDirection(Unit::Direction::Up);

         break;
      }
}
