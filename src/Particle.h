#pragma once
#ifndef __PARTICLE__
#define __PARTICLE__

#include "Sprite.h"
class Particle : public Sprite
{
public:
	Particle();
	~Particle();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void reset();
	void toggleActive();
	bool GetIsActive();

private:
	bool m_active;
};

#endif /* __PARTICLE__ */