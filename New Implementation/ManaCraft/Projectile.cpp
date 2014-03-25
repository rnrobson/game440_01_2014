#include "Projectile.h"


Projectile::Projectile(void)
{
}


Projectile::~Projectile(void)
{
}
Projectile::Projectile(Tower* _origin, Minion* _target, float _projectileSpeed)
{
	origin = _origin;
	target = _target;
	speed = _projectileSpeed;
	
	//calculating the direction the projectile should move based on the position of the target
	xDir = _target->xPos - _origin->infSquare->xPos;
	yDir = _target->yPos - _origin->infSquare->yPos;

	collisionBox = new SDL_Rect();
	colWidth = 5;
	colHeight = 5;
	collisionBox->x = (int)round(xPos);
	collisionBox->y = (int)round(yPos);
	collisionBox->w = colWidth;
	collisionBox->h = colHeight;

}