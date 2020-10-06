#include "Particle.h"
#include "TextureManager.h"

#define DELTA_TIME 1.0f / 60.0f
#define FLOOR_HEIGHT 430.0f

Particle::Particle()
{
	TextureManager::Instance()->load("../Assets/textures/GAME2005_Detonator.png", "particle");

	// set frame width
	setWidth(50);

	// set frame height
	setHeight(50);

	reset();
	getRigidBody()->isColliding = false;
}

Particle::~Particle()
= default;

void Particle::draw()
{
	TextureManager::Instance()->draw("particle", getTransform()->position.x, getTransform()->position.y, getWidth(), getHeight(), 0.0f, 255, true);
}

void Particle::update()
{
	if (m_active)
	{
		// Update Position here
		getRigidBody()->velocity += getRigidBody()->acceleration * DELTA_TIME;
		getTransform()->position += getRigidBody()->velocity * DELTA_TIME;

		// Prevent particle from going through the floor
		if (getTransform()->position.y >= FLOOR_HEIGHT)
		{
			getTransform()->position.y = FLOOR_HEIGHT;
			toggleActive();
		}
	}
}

void Particle::clean()
{
}

void Particle::reset()
{
	m_active = false;
	getTransform()->position = glm::vec2(100.0f, FLOOR_HEIGHT);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 9.8f);	// Set to 9.8 * PixelsPerMeter in the Playscene instead of here
}

void Particle::toggleActive()
{
	m_active = !m_active;
}

bool Particle::GetIsActive()
{
	return m_active;
}
