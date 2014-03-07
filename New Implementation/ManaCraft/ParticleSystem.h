#pragma once
#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "GuiElement.h"
#include <math.h>


/* PARTICLE CLASS - DO NOT ALTER */
class Particle : public GuiElement{
public:
	Particle(){}
	Particle(SDL_Texture* _texture)
	{
		alive = true;
		alpha = 255;
		texture = _texture; 
		//speed = (rand() % 20) + 5; //Default the speed to be random. Override later if you desire another outcome
		SDL_QueryTexture(texture, NULL, NULL, &rectWidth, &rectHeight); //Grab the texture data and set the width and height of our dst rectangle to the textures dimensions
		rect = {0, 0, rectWidth, rectHeight };
		SetDirection(0, 0);
		originalX = GetPosition().x;
		originalY = GetPosition().y;

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

	void SetPosition(float x, float y) { rect.x = x; rect.y = y;}
	void SetOriginalPosition(float x, float y){ originalX = x, originalY = y; }
	void SetDirection(float x, float y){ directionX = x; directionY = y; }
	void SetSpeed(float _speed) { speed = _speed; }

	void ResetParticle() { alpha = 255; alive = true, SetPosition(originalX, originalY); }
	bool isAlive() { return alive; }

private:
	int rectWidth, rectHeight, originalX, originalY;
	float directionX, directionY, speed, alpha;
	bool alive;
};



/* BASE PARTICLESYSTEM CLASS */
class ParticleSystem : public GuiElement{
public:
	ParticleSystem();
	~ParticleSystem();
	virtual void Setup();

	//Setters
	void SetPosition(float x, float y);
	void SetSpeed(float _speed);
	void SetTexture(SDL_Texture* _texture) { particleTexture = _texture; }
	void SetRepeat(bool _repeat) { repeating = _repeat; }
	void SetRandom(bool myBool) { randomSpeeds = myBool; }

	//Getters
	float GetSpeed(){ return particleSpeed; }
	bool isRepeating(){ return repeating;}
	bool isRandomSpeeds(){ return randomSpeeds; }

	void Initialize(size_t numberOfParticles);

	std::vector<Particle*> particleList;
private:
	bool randomSpeeds;
	bool repeating;
	float particleSpeed;
	//std::vector<SDL_Texture*> particleTextures;
	SDL_Texture* particleTexture;
	virtual void Update(double time);
	virtual void Draw();
};



/* BURST PARTICLE CLASS */
class Burst : public ParticleSystem{
public:
	Burst();
	Burst(size_t numberOfParticles, SDL_Texture* texture, float particleSpeed, bool randomSpeeds, bool isRepeating);
private:
	virtual void Setup();
	virtual void Update(double time);
};

/* EMITTER PARTICLE CLASS */
class Emitter : public ParticleSystem{
public:
	Emitter();
	Emitter(size_t numberOfParticles, SDL_Texture* texture, bool oneShot, int xDirection, int yDirection);
private:
	float xDirection, yDirection, timer;
	virtual void Setup();
	virtual void Update(double time);
};


#endif


