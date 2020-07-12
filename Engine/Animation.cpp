#include "Animation.h"

void Animation::Draw(const Vei2 & pos, const Graphics & gfx) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], sprite, Chroma);
}

void Animation::Draw(const Vei2 & pos, const Graphics & gfx, const RectI & clip) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], clip, sprite, Chroma);
}

void Animation::Update(float dt)
{
}

void Animation::Advance()
{
}
