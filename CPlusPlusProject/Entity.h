#pragma once
#include <string>

class Entity {
private:
	static int eIDCounter;

	std::string eID;
public:
	Entity();
	std::string getEID();
	bool operator ==(Entity& other);
	bool operator !=(Entity& other);
	bool operator <(Entity& other);
	bool operator >(Entity& other);
};