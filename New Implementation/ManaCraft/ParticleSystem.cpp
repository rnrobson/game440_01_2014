#include "ParticleSystem.h"

//ParticleSystem::DIRECTION;
ParticleSystem::ParticleSystem(size_t _numberOfParticles, SDL_Texture* _texture, bool _randomSpeeds)
{
	particleTexture = _texture;
	randomSpeeds = _randomSpeeds;
	Initialize(_numberOfParticles);
}
ParticleSystem::ParticleSystem(size_t _numberOfParticles, SDL_Texture* _texture, float _particleSpeed)
{
	randomSpeeds = false;
	particleTexture = _texture;
	particleSpeed = _particleSpeed;
	Initialize(_numberOfParticles);
}
ParticleSystem::~ParticleSystem(){}

void ParticleSystem::Initialize(size_t particleNum)
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
	bool particleListOccupied = false;
	if (Active)
	{
		if (particleList.size() != 0)
		{
			for (size_t i = 0; i < particleList.size(); i++)
			{
				if (particleList.at(i)->isAlive())
				{
					particleListOccupied = true;
					particleList.at(i)->Update(time);
				}

			}
		}
	}
	if (!particleListOccupied)
	{
		particleList.clear();
		Active = false;
	}
}

void ParticleSystem::Burst()
{
	//Spread the particles out along a circle
	for (size_t i = 0; i < particleList.size(); i++)
	{
		float inDegrees = 360 / particleList.size();
		float inRadians = inDegrees * (3.14f / 180);
		particleList[i]->SetDirection(sin(inRadians*i), cos(inRadians*i));
	}
}

/*void ParticleSystem::Emit(DIRECTION emitterDirection)
{
	//Determines which direction the emitter will emit.
	Vector2 tempEmitterDirection;
	/*switch (emitterDirection){
	case UP:
		tempEmitterDirection = Vector2(0, 1);
		break;
	case DOWN:
		tempEmitterDirection = Vector2(0, -1);
		break;
	case LEFT:
		tempEmitterDirection = Vector2(1, 0);
		break;
	case RIGHT:
		tempEmitterDirection = Vector2(-1, 0);
		break;
	}

	for (size_t i = 0; i < particleList.size(); i++)
	{
		//particleList.at(i)->SetDirection(tempEmitterDirection.x, 
			//						     tempEmitterDirection.y);
	}
} */