#include "Entity.h"

int Entity::eIDCounter = 0;

Entity::Entity() {
	eID = std::to_string(eIDCounter++);
}

std::string Entity::getEID() {
	return eID;
}

bool Entity::operator==(Entity& other) {
	int compValue = eID.compare(other.getEID());
	if (compValue == 0) {
		return true;
	}
	return false;
}

bool Entity::operator!=(Entity& other) {
	return !(*this == other);
}

bool Entity::operator<(Entity& other) {
	int compValue = eID.compare(other.getEID());
	if (compValue < 0) {
		return true;
	}
	return false;
}

bool Entity::operator>(Entity& other) {
	int compValue = eID.compare(other.getEID());
	if (compValue > 0) {
		return true;
	}
	return false;
}