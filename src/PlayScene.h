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
	bool m_higherAngle;
	bool m_lockOn;
	float m_time;
	float m_startingPos;
	int m_delayPress;

	// Labels
	Label* m_pdeltaXLabel;
	Label* m_pdeltaYLabel;
	Label* m_pAngleLabel;
	Label* m_pTimeLabel;
	Label* m_pTargetDistLabel;
	Label* m_pInitialVelocityLabel;

	Label* m_pInstructionsLabel;
	Label* m_pInstructionsLabel2;
	Label* m_pInstructionsLabel3;
	Label* m_pInstructionsLabel4;
	Label* m_pInstructionsLabel5;
	Label* m_pToggleInfoLabel;
	Label* m_pPPM;			// Pixels Per Meter

	// Button* m_pBackButton;
	// Button* m_pNextButton;

	// Buttons
	Button* m_pPlayButton;
	Button* m_pResetButton;
	Button* m_pDefaultButton;

	// Functions
	void setToDefaults();
	void resetSim();
	void activateSim();

	void toggleHigherAngle();
	void toggleLockOn();

	void incTargetDistance();
	void decTargetDistance();

	void incVelocity();
	void decVelocity();

	void incAngle();
	void decAngle();
};

#endif /* defined (__PLAY_SCENE__) */