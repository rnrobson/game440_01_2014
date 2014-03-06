#pragma once
#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "GuiElement.h"
#include <math.h>

//Vector Struct
struct Vector2{
	float x, y;
	Vector2(float _x, float _y) : x(_x), y(_y) {};
	Vector2();
};

/*typedef enum {
	UP, DOWN, LEFT, RIGHT
} DIRECTION; */

//Particle class - For use only within Particle System
class Particle : public GuiElement{
public:
	Particle(){}
	Particle(SDL_Texture* _texture, float _speed)
	{
		alive = true;
		alpha = 255;
		texture = _texture;
		speed = _speed;
		SDL_QueryTexture(texture, NULL, NULL, &rectWidth, &rectHeight); //Grab the texture data and set the width and height of our dst rectangle to the textures dimensions
		rect = { 500, 500, rectWidth, rectHeight };
		SetDirection(0, 0);
	}
	Particle(SDL_Texture* _texture)
	{
		alive = true;
		alpha = 255;
		texture = _texture;
		speed = rand() % 20;
		SDL_QueryTexture(texture, NULL, NULL, &rectWidth, &rectHeight); //Grab the texture data and set the width and height of our dst rectangle to the textures dimensions
		rect = { 500, 500, rectWidth, rectHeight };
		SetDirection(0, 0);
	}
	virtual void Update(double time)
	{
		if (Active)
		{
			//Offsets and padding prior to updating 
			if (alive)
			{

				rect.x += offset.x + padding.x;
				rect.y += offset.y + padding.y;
				SetPosition((int)GetPosition().x + (directionX * speed), //Set the position of the particle and update based on its directional vector and speed
					(int)GetPosition().y + (directionY * speed));
				
				//Reduce the alpha over time
				if (alpha >= 10){
					alpha -= time / 20;
				}else{
					alpha = 0;
				}
				if (alpha == 0){ alive = false; } //If the alpha is equal to zero, the particle is no longer living

				SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND); //Change blending mode of the texture
				SDL_SetTextureAlphaMod(texture, alpha); //Set the alpha of the texture
			}

		}
	}
	virtual void Draw()
	{
		if (Active) 
		{
			if (alive)
			{
				rect.x += offset.x + padding.x;
				rect.y += offset.y + padding.y;
				SDL_RenderCopyEx(Window::Renderer(), texture, NULL, &rect, 0, NULL, flip);
			}
		}
	}
	float GetDirectionX() { return directionX; }
	float GetDirectionY() { return directionY; }
	void SetDirection(float x, float y){ directionX = x; directionY = y; }
	bool isAlive() { return alive; }

private:
	int rectWidth, rectHeight;
	float directionX, directionY, speed, alpha;
	bool alive;
};

class ParticleSystem : public GuiElement{
public:
	enum DIRECTION { UP, DOWN, LEFT, RIGHT };
	ParticleSystem(){};
	ParticleSystem(size_t numberOfParticles, SDL_Texture* texture, bool randomSpeeds);
	ParticleSystem(size_t numberOfParticles, SDL_Texture* texture, float particleSpeed);
	~ParticleSystem();
	void Burst();
	void Emit(DIRECTION);
private:
	bool randomSpeeds;
	float particleSpeed;
	SDL_Texture* particleTexture;
	std::vector<Particle*> particleList;
	virtual void Update(double time);
	virtual void Draw();
	void Initialize(size_t numberOfParticles);
};


#endif


