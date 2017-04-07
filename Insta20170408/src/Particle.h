#pragma once

#include "ofMain.h"

class Particle
{
public:
	Particle(float x, float y, float z);
	~Particle();
	
	void applyForce(ofVec3f force);
	ofVec3f seek(ofVec3f target);

	void update();
	void draw();
	void draw(vector<Particle> particles);

private:
	ofVec3f location;
	ofVec3f velocity;
	ofVec3f acceleration;
	float max_speed;
	float max_force;
	float radius;
	float angle;
	
	ofColor body_color;
	float body_size;
};