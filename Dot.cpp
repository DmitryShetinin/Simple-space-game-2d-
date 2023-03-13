#define _USE_MATH_DEFINES
#include "Dot.h"



size_t countParticle = 90;
std::vector<Texture*> s_textures;

Dot::Dot()
{
	//s_textures.push_back(new Texture("1.png"));
	s_textures.push_back(new Texture("4.png"));
	//s_textures.push_back(new Texture("3.png"));
	for (int i = 0; i < countParticle; i++)
		m_particle.push_back(new Particle(m_x, m_y));
	

	m_texture = new Texture("v1.png");
}

Dot::~Dot()
{
	delete m_texture; 
}



void Dot::draw()
{


	for (int i = 0; i < countParticle; i++)
		m_particle[i]->draw(m_particle[i]->m_alpha , s_textures, angle);

	m_texture->Scale(0.20f);

	glTranslatef(m_x * 0.01f, m_y *0.01f, 0);
	glRotatef(angle, 0, 0, 1); 
	m_texture->draw(1);
	//m_texture->setPos(m_x * 0.005f, m_y * 0.005f);

}
float speed = 0; 


void Dot::move()
{


		
	
	if (GetKeyState('W') < 0) 
		speed = 1.5f;	
	else if (GetKeyState('S') < 0) 	
		speed = -1.5f;
	else 
		speed = 0; 
	
	

	if (GetKeyState('A') < 0) {
		speed = 1.5f;

		angle++;
	}
	else if (GetKeyState('D') < 0) {
		speed = 1.5f;
		angle--;
	}
	

	float ugol = -(angle) * M_PI / 180; 

	if (speed != 0) {
	
		m_x += sin(ugol) * speed;
		m_y += cos(ugol) * speed;
	}


	for (int i = 0; i < countParticle; i++)
		if (m_particle[i]->is_dead())
			m_particle[i]->reInt(m_x, m_y);

}

glm::vec2 Dot::getPos()
{
	return glm::vec2(m_dx,m_dy);
}
