#include "Animation.h"

void Animation::Draw(const Vei2 & pos, const Graphics & gfx) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], sprite, chroma);
}

void Animation::Draw(const Vei2 & pos, const Graphics & gfx, const RectI & clip) const
{
}
	

void Animation::Update(float dt)
{
}

void Animation::Advance()
{
}
