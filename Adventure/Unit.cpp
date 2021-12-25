#include "Unit.h"

Unit::Unit(const std::string& imageFile, int xPos, int yPos, int speed, int pointValue) 
	: mPosX(xPos), mPosY(yPos), mSpeed(speed), mDirection(Direction::None), mPointValue(pointValue)
{
	mImage.LoadImage(imageFile);
}

int Unit::GetUnitWidth() const
{
	return mImage.GetWidth();
}

int Unit::GetUnitHeight() const
{
	return mImage.GetHeight();
}

void Unit::SetPosX(int newX)
{
	mPosX = newX;
}

void Unit::SetPosY(int newY)
{
	mPosY = newY;
}

int Unit::GetPosX() const
{
	return mPosX;
}

int Unit::GetPosY() const
{
	return mPosY;
}

int Unit::GetSpeed() const
{
	return mSpeed;
}

int Unit::GetPointValue() const
{
	return mPointValue;
}

bool Unit::CollideWith(const Unit& other) const
{
	int oXleft { other.GetPosX() };
	int oXright { other.GetPosX() + other.GetUnitWidth() };
	int oYbottom { other.GetPosY() };
	int oYtop { other.GetPosY() + other.GetUnitHeight() };

	bool intersectOnX {
		(mPosX <= oXleft && oXleft <= mPosX + GetUnitWidth()) ||
		(mPosX <= oXright &&  oXright <= mPosX + GetUnitWidth()) ||
		(oXleft <= mPosX && mPosX + GetUnitWidth() <= oXright)
	};

	bool intersectOnY {
		(mPosY <= oYbottom && oYbottom <= mPosY + GetUnitHeight()) ||
			 (mPosY <= oYtop && oYtop <= mPosY + GetUnitHeight()) ||
			 (oYbottom <= mPosY && mPosY  + GetUnitHeight() <= oYtop)
	};

	return intersectOnX && intersectOnY;
}

void Unit::Draw(Story::Shader & shader)
{
	Story::Renderer::Draw(mImage, mPosX, mPosY, mImage.GetWidth(), mImage.GetHeight(), shader);
}

Unit::Direction Unit::GetDirection() const
{
	return mDirection;
}

void Unit::SetDirection(Unit::Direction newDirection)
{
	mDirection = newDirection;
}

void Unit::UpdatePosition()
{
	switch (mDirection)
	{
		case Direction::Down:
			if(IsPositionPossible(mPosX, mPosY-mSpeed))
				mPosY -= mSpeed;
			break;
		case Direction::Up:
			if (IsPositionPossible(mPosX, mPosY + mSpeed))
				mPosY += mSpeed;
			break;
		case Direction::Left:
			if (IsPositionPossible(mPosX - mSpeed, mPosY))
				mPosX -= mSpeed;
			break;
		case Direction::Right:
			if (IsPositionPossible(mPosX + mSpeed, mPosY))
				mPosX += mSpeed;
			break;
	}
}

bool Unit::IsPositionPossible(int newX, int newY) const
{
	return !(newX < 0 || newY < 0 || newX + mImage.GetWidth() > 800 || newY + mImage.GetHeight() > 600);

}

