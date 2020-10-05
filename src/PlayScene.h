#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "Enemy.h"
#include "Particle.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
private:
	glm::vec2 m_mousePosition;

	// Particle
	Particle* m_pParticle;

	// Variables for changing simulation
	glm::vec2 m_direction;
	float m_velocityMag;
	float m_angle;
	float m_distanceToTarget;
	bool m_playedSim;
	float m_time;

	// Plane* m_pPlaneSprite;
	// Player* m_pPlayer;
	// Enemy* m_pEnemy;

	// Labels
	Label* m_pdeltaXLabel;
	Label* m_pdeltaYLabel;
	Label* m_pAngleLabel;
	Label* m_pTimeLabel;

	// Button* m_pBackButton;
	// Button* m_pNextButton;

	// Buttons
	Button* m_pPlayButton;
	Button* m_pResetButton;

	// Functions
	void resetSim();
	void activateSim();
};

#endif /* defined (__PLAY_SCENE__) */