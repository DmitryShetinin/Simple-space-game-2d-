#include <vector>
#include "Texture.h"



class Particle {

public:
    Particle(float aX, float aY);
    ~Particle(); 
    
    void draw(float alpha, std::vector<Texture*> &s_textures, float angle);
    void reInt(float aX, float aY);
    bool is_dead();
   

    float m_alpha{ 1.00f };

private: 

  

    float m_x{ 0 };
    float m_y{ 0 };
    float m_alpha_dx{ 0.00f };
    bool m_is_dead{ true }; 
    float m_frame{ 0.00f };
    float s_frame_count_for{ 60.00f };
    int m_index{ 0 };
    void init(float aX, float aY); 

};