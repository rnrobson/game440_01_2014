#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(size_t _numberOfParticles, SDL_Texture* _texture)
{
	particleTexture = _texture;
	particleNum = _numberOfParticles;
	Initialize();
}

ParticleSystem::~ParticleSystem(){

}

void ParticleSystem::Initialize()
{
	particleList = std::vector<Particle*>();
	for (size_t i = 0; i < particleNum; i++)
	{
		if (particleTexture != nullptr)
		{
			particleList.push_back(new Particle(particleTexture));
		}
	}
}

void ParticleSystem::Draw()
{
	if (Active)
	{
		rect.x += offset.x + padding.x;
		rect.y += offset.y + padding.y;
		for (size_t i = 0; i < particleList.size(); i++)
		{
			particleList.at(i)->Draw();
		}
	}
}

void ParticleSystem::Update(double time){
	if (Active)
	{
		for (size_t i = 0; i < particleList.size(); i++)
		{
			//TODO
			//Get the direction each particle has to move in
			//Add a velocity to this directional vector
			particleList.at(i)->Update(time);
		}
	}
}