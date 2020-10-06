#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "Enemy.h"
// #include "Background.h"
#include "Particle.h"
#include "Target.h"

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

	// Background* m_pBackground;

	// Particle
	Particle* m_pParticle;

	// Target
	Target* m_pTarget;

	// Variables for changing simulation
	glm::vec2 m_direction;
	float m_velocityMag;
	float m_angle;
	float m_distanceToTarget;
	bool m_playedSim;
	float m_time;

	// Labels
	Label* m_pdeltaXLabel;
	Label* m_pdeltaYLabel;
	Label* m_pAngleLabel;
	Label* m_pTimeLabel;
	Label* m_pTargetDistLabel;
	Label* m_pInitialVelocityLabel;

	// Button* m_pBackButton;
	// Button* m_pNextButton;

	// Buttons
	Button* m_pPlayButton;
	Button* m_pResetButton;

	// Functions
	void resetSim();
	void activateSim();

	void incTargetDistance();
	void decTargetDistance();

	void incVelocity();
	void decVelocity();
};

#endif /* defined (__PLAY_SCENE__) */