#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "Sprite.h"

class Background :
    public Sprite
{
private:
	SDL_Texture* m_pTexture;
	SDL_Rect* m_src, * m_dst;
public:
	Background();
	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

};

#endif /* defined (__BACKGROUND__) */
