#pragma once
#include "Vec2.h"
#include "Animation.h"

class Character {
private:
	enum class Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		count

	};
public:
	Character(Vec2& pos);
	void Update(float dt);
	void Draw(Graphics& gfx);
	void SetDirection(const Vec2& dir);
private:
	Surface sprite;
	std::vector<Animation> animations;
	Sequence iCurSequence = Sequence::StandingDown;
	Vec2 pos;
	Vec2 vel = {0.0f, 0.0f};
	float speed = 80.0;
};