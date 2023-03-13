#define _USE_MATH_DEFINES
#include "MyParticiple.h"





Particle::Particle(float aX, float aY)
{
	init(aX, aY); 
}


Particle::~Particle(){}


void Particle::draw(float alpha, std::vector<Texture*>& s_textures, float angle) {
	if (m_is_dead)
		return;
	
	
	glPushMatrix(); 
		glTranslatef((m_x) * 0.01f, (m_y)*0.01f, 0);
		s_textures[m_index]->Scale(0.06f); 
		glRotatef(angle, 0, 0, 1);
		s_textures[m_index]->draw(alpha);
	glPopMatrix();
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
	
	m_x = aX ;	
	m_y = aY;
	
	m_is_dead = false;
	m_frame = rand() % 60 - 20;
	m_alpha = 1;
	m_alpha_dx = 01.00f / (s_frame_count_for - m_frame);
}



