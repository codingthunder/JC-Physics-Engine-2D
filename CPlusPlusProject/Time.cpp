#include "Time.h"

steady_clock::time_point Time::lastFixedUpdate = steady_clock::now();
steady_clock::time_point Time::lastUpdate = steady_clock::now();

double Time::fixedDeltaTime() {
	return timeSincePoint(lastFixedUpdate);
}

double Time::deltaTime() {
	return timeSincePoint(lastUpdate);
}

double Time::timeSincePoint(steady_clock::time_point t1) {
	duration<double> time_span = duration_cast<duration<double>>(steady_clock::now() - t1);
	return time_span.count();
}

void Time::tickFixedUpdate() {
	lastFixedUpdate = steady_clock::now();
}

void Time::tickUpdate() {
	lastUpdate = steady_clock::now();
}