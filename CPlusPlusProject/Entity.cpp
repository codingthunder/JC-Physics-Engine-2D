#include "Entity.h"

int Entity::eIDCounter = 0;

Entity::Entity() {
	eID = eIDCounter++;
}

int Entity::getEID() {
	return eID;
}