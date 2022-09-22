#pragma once
#include <vector>
#include "Physics2d.h"
#include <SFML/Graphics.hpp>
class Rendering {
private:
	std::vector<CircleCollider*> entities;
	std::vector<sf::CircleShape> renderCircles;
	sf::RenderWindow* window;
	sf::Vector2f convertToScreenCoordinates(float x, float y);
	

	int pixelsPerUnit = 50;
	
	const int SCREEN_W = 1000;
	const int SCREEN_H = 750;

public:
	Rendering(sf::RenderWindow * window);
	void render();

	void trackEntity(CircleCollider* entity);
	void untrackEntity(CircleCollider* entity);
	Vector2 convertToWorldCoordinates(sf::Vector2i screenCoord);

};