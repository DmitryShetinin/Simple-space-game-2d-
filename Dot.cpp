#include "Dot.h"
#include <iostream>



size_t countParticle = 60;
std::vector<Texture*> s_textures;

Dot::Dot()
{
	s_textures.push_back(new Texture("1.png"));
	s_textures.push_back(new Texture("4.png"));
	s_textures.push_back(new Texture("3.png"));
	for (int i = 0; i < countParticle; i++)
		m_particle.push_back(new Particle(m_x - m_dx, m_y - m_dy));
	

	m_texture = new Texture("1.png");
}

Dot::~Dot()
{
	delete m_texture; 
}



void Dot::draw()
{


	for (int i = 0; i < countParticle; i++)
		m_particle[i]->draw(m_particle[i]->m_alpha , s_textures);

	m_texture->setPos(m_x * 0.005f, m_y * 0.005f);
	m_texture->scale(0.15f);
	m_texture->draw(1);
}

void Dot::move()
{
	//m_x += m_dx;
	//m_y += m_dy;

	for (int i = 0; i < countParticle; i++) {
		if (m_particle[i]->is_dead()) {					
			m_particle[i]->reInt((m_x - m_dx)*0.5f, (m_y - m_dy) * 0.5f);
		}
	}


	if (GetKeyState('W') < 0) {
		m_y += m_dy;
	}
	else if (GetKeyState('S') < 0) {
		m_y -= m_dy;
	}

	if (GetKeyState('A') < 0) {
		m_x -= m_dx; 
	}
	else if (GetKeyState('D') < 0) {
		m_x += m_dx;
	}



	if ((m_x * 0.005f) + 0.02f > 1 || (m_y * 0.005f) + 0.02f > 1) {
		m_dx *= -1;
		m_dy *= -1;
	}

	if ((m_x * 0.005f) - 0.015f < -1 || (m_y * 0.005f) - 0.015f < -1) {
		m_dx *= -1;
		m_dy *= -1;
	}
}
