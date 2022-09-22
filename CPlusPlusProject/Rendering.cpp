#include "Rendering.h"

Rendering::Rendering(sf::RenderWindow* window) {
	this->window = window;
	entities = std::vector<CircleCollider*>();
	renderCircles = std::vector<sf::CircleShape>();
}

void Rendering::render() {

	window->clear();

	for (int i = 0; i < entities.size(); ++i) {
		//Convert position - radius to screen coordinates.
		Vector2 entPos = entities[i]->getPosition();
		float radius = entities[i]->getRadius();
		sf::CircleShape & renderCircle = renderCircles[i];

		sf::Vector2f pixelPosition = convertToScreenCoordinates(entPos.x, entPos.y);
		float pixelRadius = radius * pixelsPerUnit;

		renderCircle.setPosition(pixelPosition.x - pixelRadius,pixelPosition.y - pixelRadius);
		renderCircle.setRadius(pixelRadius);

		window->draw(renderCircle);
	}

	window->display();

}

sf::Vector2f Rendering::convertToScreenCoordinates(float x, float y) {

	float newX = x * pixelsPerUnit + SCREEN_W / 2.f;

	//DOUBLE-CHECK MATH HERE
	float newY = -y * pixelsPerUnit + SCREEN_H / 2.f;

	return sf::Vector2f(newX, newY);
}

Vector2 Rendering::convertToWorldCoordinates(sf::Vector2i screenCoord) {
	float newX = (screenCoord.x - (SCREEN_W / 2.f)) / pixelsPerUnit;

	float newY = -(screenCoord.y - (SCREEN_H / 2.f)) / pixelsPerUnit;

	return Vector2(newX, newY);
}

void Rendering::trackEntity(CircleCollider* entity) {
	for (CircleCollider* col : entities) {
		if (entity->getEID() == col->getEID()) {
			return;
		}
	}

	entities.push_back(entity);
	sf::CircleShape newShape(entity->getRadius());
	renderCircles.push_back(newShape);
}

void Rendering::untrackEntity(CircleCollider* entity) {
	for (int i = 0; i < entities.size(); ++i) {
		if (entity->getEID() == entities[i]->getEID()) {
			entities.erase(entities.begin() + i);
			renderCircles.erase(renderCircles.begin() + i);
			return;
		}
	}
}