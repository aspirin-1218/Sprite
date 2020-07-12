#pragma once
#include "surface.h"
#include "Graphics.h"
#include <vector>

class Animation{
public:
	void Draw(const Vei2& pos, const Graphics& gfx) const;
	void Draw(const Vei2& pos, const Graphics& gfx, const RectI& clip) const; 
	void Update(float dt);
private:
	void Advance();
private:
	Color Chroma; //Chroma key: background color
	const Surface& sprite; //image class
	std::vector<RectI> frames;
	int iCurFrame = 0;
	float holdTime; //hold time for each frame
	float curFrameTime = 0.0f; //current frame's timestamp for appearance
};