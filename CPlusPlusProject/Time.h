#pragma once
#include <ctime>
#include <chrono>

using namespace std::chrono;

class Time {
private:
	static steady_clock::time_point lastFixedUpdate;
	static steady_clock::time_point lastUpdate;

	static double timeSincePoint(steady_clock::time_point t1);

public:
	static double fixedDeltaTime();
	static double deltaTime();

	static void tickFixedUpdate();
	static void tickUpdate();

};