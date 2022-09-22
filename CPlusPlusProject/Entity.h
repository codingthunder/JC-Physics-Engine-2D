#pragma once

class Entity {
private:
	static int eIDCounter;

	int eID;
public:
	Entity();
	int getEID();
};