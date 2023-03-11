#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Texture.h"
#include <math/glm.hpp>



float texCoord[] = { 0,1, 1,1, 1,0, 0,0 };
float vertexMap[] = { -1,-1,  1,-1,  1,1,-1,1 };



glm::vec2 vertex1[4] {
    glm::vec2(-1,-1),
    glm::vec2(1,-1),
    glm::vec2(1,1),
    glm::vec2(-1,1),
};



Texture::Texture(const char* path) {
    int width(2), height(2), cnt;

    data = stbi_load(path, &width, &height, &cnt, 0);

    if (data) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
            cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    else {
        printf("Error");
    }

}




Texture::Texture(){}


Texture::~Texture() {
    stbi_image_free(data);
}

void Texture::draw(float alpha) {

    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1, 1, 1, alpha);
    glPushMatrix();
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertex1);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void Texture::setPos(float x, float y) {
    this->PosX = x;
    this->PosY = y;
}



glm::vec2 Texture::getPos()
{
    return glm::vec2(PosX, PosY);
}



void Texture::scale(float x)
{
    vertex1[0] = glm::vec2(PosX + x, PosY - x);
    vertex1[1] = glm::vec2(PosX - x, PosY - x);
    vertex1[2] = glm::vec2(PosX - x, PosY + x);
    vertex1[3] = glm::vec2(PosX + x, PosY + x);
}