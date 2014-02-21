#pragma once
#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "GuiElement.h"
#include <vector>
class Particle : public GuiElement{
public:
	Particle(){
		texture = nullptr;
	}

	Particle(SDL_Texture* _texture){
		texture = _texture;
		SDL_QueryTexture(texture, NULL, NULL, &rectWidth, &rectHeight); //Grab the texture data and set the width and height of our dst rectangle to the textures dimensions
		rect = {100 , 100, rectWidth, rectHeight };
	}
	virtual void Free(){}
	virtual void Update(double time)
	{
		if (Active)
		{
			//Offsets and padding prior to updating 
			rect.x += offset.x + padding.x;
			rect.y += offset.y + padding.y;

			rect.y--;
		}
	}

	virtual void Draw()
	{
		if (Active) 
		{
			rect.x += offset.x + padding.x;
			rect.y += offset.y + padding.y;
			SDL_RenderCopyEx(Window::Renderer(), texture, NULL, &rect, 0, NULL, flip);
		}
	}
private:
	int rectWidth, rectHeight;

};

class ParticleSystem : public GuiElement{
public:
	ParticleSystem() : particleNum(0) {};
	ParticleSystem(size_t numberOfParticles, SDL_Texture* texture);
	~ParticleSystem();
private:
	size_t particleNum;
	SDL_Texture* particleTexture;
	std::vector<Particle*> particleList;

	virtual void Update(double time);
	virtual void Draw();
	void Initialize();
};


#endif


