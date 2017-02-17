#include "runway.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	int takeoffRate;
	int landingRate;
	int timeToLand;
	int timeToTakeoff;
	int timeSimulation;

	//Variables for random number
	int rand1, rand2, rand11, rand22, rand911;

	//Variables for statistics
	int maxLanding = 0;
	int totalMinutesLanding = 0;
	int maxTakeoff = 0;
	int totalMinutesTakeoff = 0;
	//A counter for flight;
	int flightNumber = 1;

	//construct a new runway that is not in use
	Runway r;
	Runway r1;

	//inputs
	cout<< "Enter: " <<endl;
	cout << "Time for a plane to land (in minutes): ";
	cin >> timeToLand;
	cout << "Time for a plane to takeOff (in minutes): ";
	cin >> timeToTakeoff;
	cout << "Landing rate (planes per hour): ";
	cin >> landingRate;
	cout << "Takeoff rate (planes per hour): ";
	cin >> takeoffRate;
	cout << "How long to run the simulation (in minutes): ";
	cin >> timeSimulation;

	int timerInUse = 0;
	int landingQueueCounter = 0;
	int takeoffQueueCounter = 0;
	int totalLandingFlight = 0;
	int totalTakeoffFlight = 0;
	int timeTotal;
	bool r2aval = true;
	int timerInUse1 = 0;
	int landingQueueCounter1 = 0;
	int takeoffQueueCounter1 = 0;
	int totalLandingFlight1 = 0;
	int totalTakeoffFlight1 = 0;

	//generate random number seed
	srand (time(NULL));

	//start of the loop
	for (timeTotal = 1; timeTotal <= timeSimulation; timeTotal++) {
		rand1 = rand()% 60000;
		rand2 = rand()% 60000;
		rand911 = rand()% 10;

		totalMinutesLanding = totalMinutesLanding + landingQueueCounter + landingQueueCounter1;
		totalMinutesTakeoff = totalMinutesTakeoff + takeoffQueueCounter + takeoffQueueCounter1;

		cout << "Time = " << timeTotal << endl;

		// add landing planes
		if (rand1 % 60 < landingRate) {
            r.addLanding(flightNumber);
            landingQueueCounter++;
            totalLandingFlight++;
            if (maxLanding < landingQueueCounter) {
            	maxLanding = landingQueueCounter;
            }

            cout << "Plane " << flightNumber << " wants to land on R1; added to landing queue; " 
            << landingQueueCounter << " in queue " << endl;

			flightNumber++;
		}
		// add takeoff planes
		if (rand2 % 60 < takeoffRate) {
			r.addTakeoff(flightNumber);
			takeoffQueueCounter++; 
			totalTakeoffFlight++;

			if (maxTakeoff < takeoffQueueCounter) {
            	maxTakeoff = takeoffQueueCounter;
            }

			cout << "Plane " << flightNumber << " wants to takeoff from R1; added to takeoff queue; " 
            << takeoffQueueCounter << " in queue " << endl;

			flightNumber++;
		}

		//time to keep track the time when runway is in use
		if (timerInUse != 0) {
			timerInUse --;
			if (timerInUse == 0) {
				r.setInUseFalse();
				cout << "Runway R1 is free for use" <<endl;
				cout << "R1:Takeoff queue: " << takeoffQueueCounter << " in queue" << endl;
				cout << "R1:Landing queue: " << landingQueueCounter << " in queue" << endl;
			}
		}

		//check if runway is in use
		if (r.checkInUse() == false) {
			// consider the landing queue if runway is not in use
			if (r.checkEmptyLandingQueue() == false) {
				r.setInUseTrue();
				timerInUse = timeToLand;
				cout << "R1:Landing: Plane " << r.firstLandingNumber() << endl;
				r.dequeueLanding();
				landingQueueCounter--;
			} else {
				//consider the takeoff queue if runway is not in use
				if (r.checkEmptyTakeoffQueue() == false) {
					r.setInUseTrue();
					timerInUse = timeToTakeoff;
					cout << "R1:Taking off: Plane " << r.firstTakeoffNumber() << endl;
					r.dequeueTakeoff();
					takeoffQueueCounter--;
				}
			}
		}
    //--------------------------Runway 2---------------------------------------------
		if (r2aval) {
			rand11 = rand()% 60000;
			rand22 = rand()% 60000;
		if (rand11 % 60 < landingRate) {
            r1.addLanding(flightNumber);
            landingQueueCounter1++;
            totalLandingFlight1++;
        	if (maxLanding < landingQueueCounter1) {
            	maxLanding = landingQueueCounter1;
        	}

            cout << "Plane " << flightNumber << " wants to land on R2; added to landing queue; " 
            << landingQueueCounter1 << " in queue" << endl;

			flightNumber++;
		}
		if (rand22 % 60 < takeoffRate) {
			r1.addTakeoff(flightNumber);
			takeoffQueueCounter1++; 
			totalTakeoffFlight1++;

			if (maxTakeoff < takeoffQueueCounter1) {
            	maxTakeoff = takeoffQueueCounter1;
            }

			cout << "Plane " << flightNumber << " wants to takeoff from R2; added to takeoff queue; " 
            << takeoffQueueCounter1 << " in queue" << endl;

			flightNumber++;
		}

		if (timerInUse1 != 0) {
			timerInUse1 --;
			if (timerInUse1 == 0) {
				r1.setInUseFalse();
				cout << "Runway R2 is free for use" <<endl;
				cout << "R2:Takeoff queue: " << takeoffQueueCounter1 << " in queue" << endl;
				cout << "R2:Landing queue: " << landingQueueCounter1 << " in queue" << endl;
			}
		}

		if (r1.checkInUse() == false) {
			if (r1.checkEmptyLandingQueue() == false) {
				r1.setInUseTrue();
				timerInUse1 = timeToLand;
				cout << "R2:Landing: Plane " << r1.firstLandingNumber() << endl;
				r1.dequeueLanding();
				landingQueueCounter1--;
			} else {
				if (r1.checkEmptyTakeoffQueue() == false) {
					r1.setInUseTrue();
					timerInUse1 = timeToTakeoff;
					cout << "R2:Taking off: Plane " << r1.firstTakeoffNumber() << endl;
					r1.dequeueTakeoff();
					takeoffQueueCounter1--;
				}
			}
		}


		//generate a random number to represent emergency, 
		//merge this runway to r1 when emergency happens
		if (rand911 < 4) {
			r2aval = false;
			cout << "R2 has been shut down due to emergency" << endl;
			cout << "All flights move to R1" << endl;
			r.merge_two_runways(r1);
			landingQueueCounter = landingQueueCounter + landingQueueCounter1;
			takeoffQueueCounter = takeoffQueueCounter + takeoffQueueCounter1;
			landingQueueCounter1 = 0;
			takeoffQueueCounter1 = 0;
			totalLandingFlight = totalLandingFlight + totalLandingFlight1;
			totalTakeoffFlight = totalTakeoffFlight+ totalTakeoffFlight1;

		}
	}

	}

	cout << "No new takeoffs or landings will be generated" << endl;

	while (!r.checkEmptyTakeoffQueue() || !r.checkEmptyLandingQueue() || timerInUse != 0 
		|| !r1.checkEmptyTakeoffQueue() || !r1.checkEmptyLandingQueue() || timerInUse1 != 0) {

		cout << "Time = " << timeTotal << endl;
		timeTotal++;

	if (timerInUse != 0) {
			timerInUse --;
			if (timerInUse == 0) {
				r.setInUseFalse();
				cout << "Runway 1 is free for use" <<endl;
				cout << "R1:Takeoff queue: " << takeoffQueueCounter << " in queue" << endl;
				cout << "R1:Landing queue: " << landingQueueCounter << " in queue" << endl;
			}
		}

		if (r.checkInUse() == false) {
			if (r.checkEmptyLandingQueue() == false) {
				r.setInUseTrue();
				timerInUse = timeToLand;
				cout << "R1:Landing: Plane " << r.firstLandingNumber() << endl;
				r.dequeueLanding();
				landingQueueCounter--;
			} else {
				if (r.checkEmptyTakeoffQueue() == false) {
					r.setInUseTrue();
					timerInUse = timeToTakeoff;
					cout << "R1:Taking off: Plane " << r.firstTakeoffNumber() << endl;
					r.dequeueTakeoff();
					takeoffQueueCounter--;
				}
			}
		}

		//---------------------------------Runway2------------------------
			if (timerInUse1 != 0) {
			timerInUse1 --;
			if (timerInUse1 == 0) {
				r1.setInUseFalse();
				cout << "Runway 2 is free for use" <<endl;
				cout << "R2:Takeoff queue: " << takeoffQueueCounter1 << " in queue" << endl;
				cout << "R2:Landing queue: " << landingQueueCounter1 << " in queue" << endl;
			}
		}

		if (r1.checkInUse() == false) {
			if (r1.checkEmptyLandingQueue() == false) {
				r1.setInUseTrue();
				timerInUse1 = timeToLand;
				cout << "R2:Landing: Plane " << r1.firstLandingNumber() << endl;
				r1.dequeueLanding();
				landingQueueCounter1--;
			} else {
				if (r1.checkEmptyTakeoffQueue() == false) {
					r1.setInUseTrue();
					timerInUse1 = timeToTakeoff;
					cout << "R2:Taking off: Plane " << r1.firstTakeoffNumber() << endl;
					r1.dequeueTakeoff();
					takeoffQueueCounter1--;
				}
			}
		}

	}

	cout << "End of program" << endl;
	cout << endl;

	cout << "Statistics" << endl;
	cout << "Maximum number of plane in landing queue was: " << maxLanding <<endl;
	cout << "Average minutes spent waiting to land: " << totalMinutesLanding/totalLandingFlight << endl;
	cout << "Maximum number of plane in takeoff queue was: " << maxTakeoff << endl;
	cout << "Average minutes spent waiting to takeoff: " << totalMinutesTakeoff/totalTakeoffFlight << endl;

    return 0;
}
