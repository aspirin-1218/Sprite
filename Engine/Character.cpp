#include "Character.h"

Character::Character(Vec2 & pos)
	:
	pos(pos),
	sprite("link90x90.bmp")
{
	//Create walking animation that contains 4 pictures of walking (in 4 directions)
	for (int i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(Animation(90, 90*i, 90, 90, 4, sprite, 0.16f));
	}
	//Create standing animation that contains 4 pictures of standing (in 4 directions)
	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::count; i++)
	{
		animations.emplace_back(Animation(0, 90 * (i-(int)Sequence::StandingLeft), 90, 90, 1, sprite, 0.16f));
	}
}

void Character::Update(float dt)
{
	pos += vel*dt;
	animations[(int)iCurSequence].Update(dt); //time accumulation for image switching
}

void Character::Draw(Graphics & gfx)
{
	animations[(int)iCurSequence].Draw((Vei2)pos, gfx);
}

void Character::SetDirection(const Vec2 & dir)
{
	if (dir.x > 0.0f)
	{
		iCurSequence = Sequence::WalkingRight;
	}
	else if(dir.x < 0.0f)
	{
		iCurSequence = Sequence::WalkingLeft;
	}
	else if (dir.y > 0.0f)
	{
		iCurSequence = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f)
	{
		iCurSequence = Sequence::WalkingUp;
	}
	else
	{
		if (vel.x > 0.0f)
		{
			iCurSequence = Sequence::StandingRight;
		}
		else if (vel.x < 0.0f)
		{
			iCurSequence = Sequence::StandingLeft;
		}
		else if (vel.y < 0.0f)
		{
			iCurSequence = Sequence::StandingUp;
		}
		else if (vel.y > 0.0f)
		{
			iCurSequence = Sequence::StandingDown;
		}
		else
		{
			iCurSequence = Sequence::StandingDown;
		}
	}
	vel = dir*speed;
}
