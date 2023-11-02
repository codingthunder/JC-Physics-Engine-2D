#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>


//Consider using Spatial Hashing or Quad Trees
//Consider using OpenGL, GLM, and DirectXMath

struct Vector2 {

	Vector2(float x, float y);
	Vector2() = default;

	float x;
	float y;

	//I should just make a length field that is updated whenever x and y are updated.

	float magnitude();
	Vector2 normalized();

	static float distance(Vector2 pos1, Vector2 pos2);
	//The proportion argument is clamped between 0 and 1, inclusive.
	static Vector2 lerp(Vector2 pos1, Vector2 pos2, float proportion);
	Vector2 operator+(Vector2 otherVec);
	Vector2 operator-(Vector2 otherVec);
	Vector2 operator/(float otherVal);
	Vector2 operator*(float otherVal);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);

private:

	float _savedX;
	float _magnitude = 0;
	float _xNormalized = 0;
	float _yNormalized = 0;
};

class CircleCollider : public Entity {

private:
	float radius;
	Vector2 position;
	std::vector<CircleCollider*> overlappedColliders = std::vector<CircleCollider*>();

public:
	CircleCollider() = default;
	CircleCollider(Vector2 position, float radius);
	
	Vector2 getPosition();
	float getRadius();
	float getArea();

	void move(Vector2 offset);


	static bool isCollided(CircleCollider* colA, CircleCollider* colB);

};

class Rigidbody2D : public Entity {
private:
	CircleCollider * collider;
	Vector2 acceleration;//Units per second per second. How much I'm increasing/decreasing velocity each second.
	Vector2 velocity;//Units per second.
	float mass;
	float resistanceModifier = 1.f;
	

public:
	Rigidbody2D(CircleCollider * collider, Vector2 velocity = Vector2(0,0), float mass = 1);
	CircleCollider* getCollider();
	Vector2 getAcceleration();
	Vector2 getVelocity();
	float getMass();
	void setMass(float newMass);
	float getResistanceModifier();

	void applyMomentum(Vector2 momentum);
	void applyForce(Vector2 force);
	
};

class Physics2D {
private:
	//I should probably make this into a Binary tree. Red-Black, maybe?
	std::vector<Rigidbody2D*> entities;
	//std::vector<Vector2> projectedPositions;

	void calculatePositions();
	//My initial implementation for this will be super inefficient. I intend to optimize it once I've got the basics working.
	void calculateCollisions();
	static void negateOverlap(Rigidbody2D * rb1, Rigidbody2D * rb2);
	static void collide(Rigidbody2D* rb1, Rigidbody2D* rb2);
	static Vector2 calculateMomentumTransfer(Rigidbody2D* primaryRb, Rigidbody2D* otherRb);

	static Vector2 resistanceToMovement(Vector2 velocity, float resistanceModifier);
	static float baseResistance;

public:
	
	Physics2D();
	void updatePhysics();
	void trackEntity(Rigidbody2D* entity);
	void untrackEntity(Rigidbody2D* entity);
};