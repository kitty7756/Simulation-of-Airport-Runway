#include <iostream>
using namespace std;

#include "runway.h"
#include "LQueue.h"

//--- Definition of Runway constructor
Runway::Runway()
{}

//destructor
Runway::~Runway()
{}

void Runway::addTakeoff(int flight) {
	takeoff.enqueue(flight);
}

void Runway::addLanding(int flight) {
	landing.enqueue(flight);
}

void Runway::dequeueTakeoff() {
	takeoff.dequeue();
}

void Runway::dequeueLanding() {
	landing.dequeue();
}

bool Runway::checkEmptyTakeoffQueue() {
	return takeoff.empty();
}

bool Runway::checkEmptyLandingQueue() {
	return landing.empty();
}

bool Runway::checkInUse() {
	return inUse;
}

void Runway::setInUseTrue(){
	inUse = true;
}

void Runway::setInUseFalse() {
	inUse = false;
}

int Runway::firstTakeoffNumber() {
	return takeoff.front();
}

int Runway::firstLandingNumber() {
	return landing.front();
}

void Runway::merge_two_runways(Runway & anotherRunway) {
	takeoff.merge_two_queues(anotherRunway.takeoff);
	landing.merge_two_queues(anotherRunway.landing);
}