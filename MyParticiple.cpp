#include "MyParticiple.h"



Particle::Particle(float aX, float aY)
{
	init(aX, aY); 
}


Particle::~Particle(){}


void Particle::draw(float alpha, std::vector<Texture*>& s_textures) {
	if (m_is_dead)
		return;

	s_textures[m_index]->setPos(m_x * 0.01f, m_y * 0.01f );
	s_textures[m_index]->scale(0.02f); 
	s_textures[m_index]->draw(alpha);
	m_alpha -= m_alpha_dx; 
	m_frame++; 

	if (m_frame > s_frame_count_for)
		m_is_dead = true; 

}

void Particle::reInt(float aX, float aY) {
	init(aX, aY); 
}

bool Particle::is_dead() {
	return m_is_dead;
}

int sign() {
	if ((rand() % 10 + 1) % 2 == 0)
		return 1;
	return -1;
}

void Particle::init(float aX, float aY) {
	
	m_x = aX  + (rand() % 2) * sign();
	m_y = aY;
	m_is_dead = false;
	m_frame = rand() % 20;
	m_index = rand() % 3;
	m_alpha = 1;
	m_alpha_dx = 01.00f / (s_frame_count_for - m_frame);
}



