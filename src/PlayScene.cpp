#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	TextureManager::Instance()->draw("background", 0, 0,900,550);
	drawDisplayList();
}

void PlayScene::update()
{
	// If the Particle is not moving, change the starting parameters (For part 2f)
	if (!m_pParticle->GetIsActive())
	{
		m_angle = (glm::degrees(glm::asin((m_distanceToTarget * 9.8f) / (m_velocityMag * m_velocityMag))) / 2);
		m_direction = Util::normalize(glm::vec2(glm::cos(glm::radians(m_angle)), -glm::sin(glm::radians(m_angle))));
		m_pParticle->getRigidBody()->velocity = m_velocityMag * m_direction;
	}
	else
	{
		// If the Particle IS moving, then update the time
		m_time += 1.0f / 60.0f;		// 1.0f / FPS = Seconds per Frame
	}

	updateDisplayList();

	m_pdeltaXLabel->setText("DeltaX (m) = " + std::to_string(m_pParticle->getTransform()->position.x - 100.0f));		// 100 is starting pos
	m_pdeltaYLabel->setText("DeltaY (m) = " + std::to_string(-m_pParticle->getTransform()->position.y + 430.0f));		// 430 is the ground (Remember to chagne if ground height does)
	m_pAngleLabel->setText("Angle (degrees) = " + std::to_string(m_angle));
	m_pTimeLabel->setText("Time Elapsed (s) = " + std::to_string(m_time));

	// m_pDistanceLabel->setText("Distance = " + std::to_string(m_pPlayer->checkDistance(m_pEnemy)));
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
	{
		// m_pPlayer->moveLeft();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
	{
		// m_pPlayer->moveRight();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}
}

void PlayScene::start()
{

	/*m_pBackground = new Background();
	addChild(m_pBackground);*/
	TextureManager::Instance()->load("../Assets/textures/Background.jpg", "background");
	
	// Default info
	m_distanceToTarget = 485.0f;
	m_velocityMag = 95.0f;
	m_angle = (glm::degrees(glm::asin((m_distanceToTarget * 9.8f) / (m_velocityMag * m_velocityMag))) / 2);		// 9.8 is gravity CHANGE IF Pixels Per Meter CHANGES
	m_direction = Util::normalize(glm::vec2(glm::cos(glm::radians(m_angle)), -glm::sin(glm::radians(m_angle))));
	m_playedSim = false;
	m_time = 0.0f;

	// Particle Sprite
	m_pParticle = new Particle();
	addChild(m_pParticle);

	// Labels
	const SDL_Color cyan = { 0, 255, 255, 255 };
	m_pdeltaXLabel = new Label("Delta X (m) = ", "Consolas", 20, cyan, glm::vec2(10.0f, 20.0f), 0, false);
	m_pdeltaXLabel->setParent(this);
	addChild(m_pdeltaXLabel);

	m_pdeltaYLabel = new Label("Delta Y (m) = ", "Consolas", 20, cyan, glm::vec2(10.0f, 50.0f), 0, false);
	m_pdeltaYLabel->setParent(this);
	addChild(m_pdeltaYLabel);

	m_pAngleLabel = new Label("Angle (degrees) = ", "Consolas", 20, cyan, glm::vec2(10.0f, 80.0f), 0, false);
	m_pAngleLabel->setParent(this);
	addChild(m_pAngleLabel);

	m_pTimeLabel = new Label("Time Elapsed (s) = ", "Consolas", 20, cyan, glm::vec2(10.0f, 110.0f), 0, false);
	m_pTimeLabel->setParent(this);
	addChild(m_pTimeLabel);

	// Buttons
	// Sim Reset Button
	m_pResetButton = new Button("../Assets/textures/GAME2005_RestartButton.png", "restartButton", BACK_BUTTON);
	m_pResetButton->getTransform()->position = glm::vec2(300.0f, 500.0f);
	m_pResetButton->addEventListener(CLICK, [&]()-> void
	{
		m_pResetButton->setActive(false);

		// Reset the Simulation
		resetSim();

	});

	m_pResetButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pResetButton->setAlpha(128);
	});

	m_pResetButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pResetButton->setAlpha(255);
	});
	addChild(m_pResetButton);

	// Sim Play Button
	m_pPlayButton = new Button("../Assets/textures/GAME2005_PlayButton.png", "playButton", NEXT_BUTTON);
	m_pPlayButton->getTransform()->position = glm::vec2(500.0f, 500.0f);
	m_pPlayButton->addEventListener(CLICK, [&]()-> void
	{
		m_pPlayButton->setActive(false);

		// If the sim is not already playing, play the simulation
		if (!m_pParticle->GetIsActive() && !m_playedSim)
		{
			// Play the Simulation
			activateSim();
		}
	});

	m_pPlayButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pPlayButton->setAlpha(128);
	});

	m_pPlayButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pPlayButton->setAlpha(255);
	});

	addChild(m_pPlayButton);
}

void PlayScene::resetSim()
{
	// Reset Particle
	m_pParticle->reset();

	// Reset Time and Sim has not been played yet
	m_time = 0.0f;
	m_playedSim = false;
}

void PlayScene::activateSim()
{
	// Activate the Particle's movement
	m_pParticle->toggleActive();

	// Sim is being played
	m_playedSim = true;
}
