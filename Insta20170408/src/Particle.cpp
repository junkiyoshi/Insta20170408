#include "Particle.h"

Particle::Particle(float x, float y, float z)
{
	this->location = ofVec3f(x, y, z);
	this->velocity = ofVec3f(0, 0, 0);
	this->acceleration = ofVec3f(0, 0, 0);

	this->max_speed = 15;
	this->max_force = 5;
	this->radius = 30;
	this->angle = ofRandom(360);

	float body_value = ofRandom(255);
	this->body_color.setHsb(body_value, 255, 255, 255);
	this->body_size = 5;
}

Particle::~Particle()
{

}

void Particle::applyForce(ofVec3f force)
{
	this->acceleration += force;
}

ofVec3f Particle::seek(ofVec3f target)
{
	ofVec3f desired = this->location - target;
	float distance = desired.length();
	desired.normalize();
	if (distance < this->radius)
	{
		float m = ofMap(distance, 0, this->radius, 0, this->max_speed);
		desired *= m;
	}
	else
	{
		desired *= this->max_speed;
	}

	ofVec3f steer = this->velocity - desired;
	steer.limit(this->max_force);
	return steer;
}

void Particle::update()
{
	this->velocity += this->acceleration;
	this->velocity.limit(max_speed);
	this->location += this->velocity;
	
	this->acceleration *= 0;
	this->velocity *= 0.98;
}

void Particle::draw()
{
	ofSetColor(this->body_color);
	ofPushMatrix();
	ofTranslate(this->location);
	ofSphere(this->body_size);
	ofPopMatrix();
}

void Particle::draw(vector<Particle> particles)
{
	vector<Particle> near_particles;
	for (auto& p : particles)
	{
		float distance = this->location.distance(p.location);
		if (distance < 75) {
			near_particles.push_back(p);
		}
	}

	ofPath line = ofPath();
	line.setStrokeColor(this->body_color);
	line.setStrokeWidth(1.0);
	line.setFilled(false);

	for (auto itr = near_particles.begin(); itr != near_particles.end(); ++itr)
	{
		if (itr == near_particles.begin())
		{
			line.moveTo(itr->location.x, itr->location.y);
		}
		else
		{
			line.lineTo(itr->location.x, itr->location.y);
		}
	}

	line.draw();
	line.close();

	ofPushMatrix();
	ofTranslate(this->location);
	ofBox(1);
	ofPopMatrix();
}
