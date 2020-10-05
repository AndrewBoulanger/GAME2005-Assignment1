#include "Background.h"
#include "TextureManager.h"
#include "Renderer.h"


Background::Background()
{
	TextureManager::Instance()->load("../Assets/textures/Background.jpg", "background");

	const auto size = TextureManager::Instance()->getTextureSize("background");
	m_pTexture = TextureManager::Instance()->getTexture("background");
	m_dst = new SDL_Rect();
	m_src = new SDL_Rect();
	
	m_dst->x = m_dst->y = m_src->x = m_src->y = 0;
	m_src->w = 2560;
	m_src->h = 1440;

	m_dst->w = 1000;
	m_dst->h = 600;
}

void Background::draw()
{

	SDL_RenderCopyEx(Renderer::Instance()->getRenderer(), m_pTexture, m_src, m_dst, 0, nullptr, SDL_FLIP_NONE);
}

void Background::update()
{

}

void Background::clean()
{
	delete m_src;
	delete m_dst;

	m_src = nullptr;
	m_dst = nullptr;

}