#pragma once
#include "Physics2D.h"
#include "Rendering.h"
#include <SFML/Graphics.hpp>

class Game {
private:


	//For now, FixedUpdate, Update, and Render will all take place on the same thread. I intend to fix that later.
	//Ideally, I want to make these functions be delegates. Then, each entity can have its own Update, etc. that gets added to the delegates.

	void initialize();
	void events();
	void fixedUpdate();
	void update();
	void render();
	void onExit();

	bool exitGame = false;

	sf::RenderWindow * window;
	sf::Event event;

	std::vector<CircleCollider*> colliderPtrs;
	std::vector<Rigidbody2D*> rbPtrs;

	Physics2D physics2D;
	Rendering * rendering;

public:
	//Game();
	void run();
};