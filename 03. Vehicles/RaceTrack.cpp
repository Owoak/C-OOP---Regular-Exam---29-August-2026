#include  "RaceTrack.h"
#include "ManualCar.h"
#include "AutomaticCar.h"

#include <iostream>
#include <sstream>
#include <memory>
bool RaceTrack::isRaceRunning() const {
	for (auto& car : _cars) {
		if (car->getFuelRemaining() <= 0) {
			return false;
		}
	}
	return true;
}

void RaceTrack::printWinner() {
	if (_cars[0]->getFuelRemaining() <= 0) {
		std::cout << "Car with index: 1 won!";
	}
	else if (_cars[1]->getFuelRemaining() <= 0) {
		std::cout << "Car with index: 0 won!";
	}
	else {
		if (_cars[0]->getDistance() > _cars[1]->getDistance()) {
			std::cout << "Car with index: 0 won!";
		}
		else if (_cars[0]->getDistance() < _cars[1]->getDistance()) {
			std::cout << "Car with index: 1 won!";
		}
		else {
			std::cout << "No winner";
		}
	}
}

void RaceTrack::createManualCar(const std::vector<int>& shifts, int maxSpeed, int startFuel) {
	_cars.push_back(std::make_unique<ManualCar>(shifts, maxSpeed, startFuel));
}

void RaceTrack::createAutomaticCar(int maxSpeed, int startFuel) {
	_cars.push_back(std::make_unique<AutomaticCar>(maxSpeed, startFuel));
}

void RaceTrack::increaseSpeed(int speedIncrease, int fuelConsumtion) {
	for (auto& car : _cars) {
		car->increaseSpeed(speedIncrease, fuelConsumtion);
	}
}

void RaceTrack::decreaseSpeed(int speedDecrease) {
	for (auto& car : _cars) {
		car->decreaseSpeed(speedDecrease);
	}
}

void RaceTrack::advance() {
	for (auto& car : _cars) {
		car->addDistance(car->getCurSpeed());
	}
}

void RaceTrack::printInfo() const {
	std::ostringstream output;
	int index = 0;
	for (auto it = _cars.cbegin(); it != _cars.cend(); it++, index++) {
		output << "Car with index : " << index << " has totalDistance : " << (*it)->getDistance() << ", is running with " << (*it)->getCurSpeed() << " speed, has " << (*it)->getFuelRemaining() << " fuel left" << std::endl;
	}
	std::cout << output.str();
}