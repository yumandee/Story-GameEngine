#pragma once
#include "Story.h"

class Unit
{
public:
   Unit() = delete;
   Unit(const std::string & imageFile, int xPos, int yPos, int speed, int pointValue);
   int GetUnitWidth() const;
   int GetUnitHeight() const;
   void SetPosX(int newX);
   void SetPosY(int newY);
   int GetPosX() const;
   int GetPosY() const;
   int GetSpeed() const;
   int GetPointValue() const;
   bool CollideWith(const Unit &other) const;

   void Draw(Story::Shader & shader);

   enum class Direction
   {
      None,
      Up,
      Down,
      Left,
      Right
   };

   Unit::Direction GetDirection() const;
   void SetDirection(Unit::Direction newDirection);

   void UpdatePosition();

private:
   bool IsPositionPossible(int newX,  int newY) const; 
   Story::Sprite mImage;
   int mPosX;
   int mPosY;
   int mSpeed;
   int mPointValue;

   Direction mDirection;
};

