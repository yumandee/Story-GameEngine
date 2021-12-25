#include "pch.h"

#include "AdventureApp.h"

AdventureApp::AdventureApp() : mHero("Assets/Textures/kirby.png", 0, 0, 10, 0), mFrameCounter(0)
{
   std::cout << "Welcome to Kirby's Adventure! Defeat enemies to get points. If you defeat an ally, you will lose points!  " << std::endl;
   
   mShader.Load("Assets/Shaders/myVertexShader.glsl", "Assets/Shaders/myFragmentShader.glsl");
   mShader.SetVec2IntUniform(
       "screenSize",
       800,
       600);
}

void AdventureApp::OnUpdate()
{
   mHero.UpdatePosition();

   for (auto & enemy: mEnemies)
   {
      enemy.UpdatePosition();
   }

   if (mFrameCounter  % FRAMES_PER_SECOND == 0 && mEnemies.size() < 10) 
   {
      int newX {rand() % (600) + mHero.GetUnitWidth()};
      int newY {rand() % (450) + mHero.GetUnitHeight()};
      Unit::Direction newDir;
      int dirVal { rand() % 4 };
      if (dirVal == 0)
         newDir = Unit::Direction::Down;
      else if (dirVal == 1)
         newDir = Unit::Direction::Up;
      else if (dirVal == 2)
         newDir = Unit::Direction::Left;
      else
         newDir = Unit::Direction::Right;

      std::string imageFile;
      int randEnemy { rand() % 100};
      int points {0};
      if (randEnemy < 55)
      {
         imageFile = "Assets/Textures/enemy.png";
         points = 100;
      }
      else if (randEnemy < 80)
      {
         imageFile = "Assets/Textures/fly.png";
         points = 500;
      }
      else if (randEnemy < 90)
      {
         imageFile = "Assets/Textures/ally.png";
         points = -800;
      }
      else
      {
         imageFile = "Assets/Textures/dedede.png";
         points = 1000;
      }
      mEnemies.push_back(Unit{imageFile, newX, newY, 0, points});
      mEnemies.back().SetDirection(newDir);
      }

   auto it = mEnemies.begin();
   while(it != mEnemies.end()) 
   {
      int dur = it->IncreaseDuration();
      if(mHero.CollideWith(*it))
      {
         int pts {it->GetPointValue()};
         mPoints += pts;
         
         if (pts > 0)
            std::cout << "Enemy defeated! +" << pts << "\tScore: " << mPoints << std::endl;
         else if (pts < 0)
            std::cout << "Ally defeated!  " << pts << "\tScore: " << mPoints << std::endl;
         it = mEnemies.erase(it);
      }
      else if (dur % 120 == 0)
         it = mEnemies.erase(it);
      else 
      {
         it++;
      }
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
