#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(size_t _numberOfParticles, SDL_Texture* _texture, bool _randomSpeeds)
{
	particleTexture = _texture;
	particleNum = _numberOfParticles;
	randomSpeeds = _randomSpeeds;
	Initialize();
}
ParticleSystem::ParticleSystem(size_t _numberOfParticles, SDL_Texture* _texture, float _particleSpeed)
{
	randomSpeeds = false;
	particleTexture = _texture;
	particleNum = _numberOfParticles;
	particleSpeed = _particleSpeed;
	Initialize();
}
ParticleSystem::~ParticleSystem(){}

void ParticleSystem::Initialize()
{
	for (size_t i = 0; i < particleNum; i++)
	{
		if (particleTexture != nullptr)
		{
			if (!randomSpeeds)
			{
				particleList.push_back(new Particle(particleTexture, particleSpeed));
			}
			else
			{
				particleList.push_back(new Particle(particleTexture));
			}
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
			if (particleList.at(i)->isAlive())
				particleList.at(i)->Draw();
		}
	}
}

void ParticleSystem::Update(double time)
{
	if (Active)
	{
		if (particleList.size() != 0)
		{
			for (size_t i = 0; i < particleList.size(); i++)
			{
				if (particleList.at(i)->isAlive())
					particleList.at(i)->Update(time);
				else
				{
					particleList.erase(particleList.begin() + i);
				}
			}
		}
	}
}

void ParticleSystem::Burst()
{
	//Spread the particles out along a circle
	for (size_t i = 0; i < particleList.size(); i++)
	{
		float inDegrees = 360 / particleNum;
		float inRadians = inDegrees * (3.14f / 180);
		particleList[i]->SetDirection(sin(inRadians*i), cos(inRadians*i));
	}
}