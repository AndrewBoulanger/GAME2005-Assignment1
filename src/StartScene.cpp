#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pStartLabel = new Label("GAME2005 Assignment 1 ", "Consolas", 60, blue, glm::vec2(500.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pNameLabel1 = new Label("Andrew Boulanger - 101 292 574", "Consolas", 32, blue, glm::vec2(500.0f, 120.0f));
	m_pNameLabel1->setParent(this);
	addChild(m_pNameLabel1);

	m_pNameLabel2 = new Label("Robert Palermo - ", "Consolas", 32, blue, glm::vec2(500.0f, 180.0f));
	m_pNameLabel2->setParent(this);
	addChild(m_pNameLabel2);

	m_pInstructionsLabel = new Label("press start button to Play", "Consolas", 40, blue, glm::vec2(500.0f, 500.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);


	m_pShip = new Ship();
	m_pShip->getTransform()->position = glm::vec2(500.0f, 300.0f); 
	addChild(m_pShip); 

	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(500.0f, 400.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	
}

