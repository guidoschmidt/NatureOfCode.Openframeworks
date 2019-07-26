#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(glm::vec2 position, std::string spritePath)
{
  _origin = position;
	_sprite.load(spritePath);
}

void ParticleSystem::addParticle()
{
  _particles.push_back(new Particle(_origin, &_sprite));
}

void ParticleSystem::run()
{
  for (int i = 0; i < _particles.size(); i++) {
    Particle* p = _particles.at(i);
    p->run();
    if (p->isDead()) {
      _particles.erase(_particles.begin() + i);
    }
  }
}

void ParticleSystem::applyForce(glm::vec2 force) {
  for (Particle *p : _particles) {
    p->applyForce(force);
  }
}
