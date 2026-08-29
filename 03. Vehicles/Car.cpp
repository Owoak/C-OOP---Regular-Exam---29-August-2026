#include "Car.h"
#include "ManualCar.h"
#include "AutomaticCar.h"

//base car
Car::Car(int maxSpeed, int fuel) :maxSpeed(maxSpeed), fuelAvaible(fuel) {}
void Car::increaseSpeed(int speedIncrease, int fuelConsumtion) {
	curSpeed += speedIncrease;
	fuelAvaible -= fuelConsumtion;
}
void Car::decreaseSpeed(int speedDecrease) {
	this->curSpeed -= speedDecrease;
}
void Car::addDistance(int distanceToAdd) {
	this->distanceTraveled += distanceToAdd;
}
int Car::getCurSpeed()const {
	return curSpeed;
}
int Car::getDistance() const {
	return distanceTraveled;
}
int Car::getFuelRemaining()const {
	return fuelAvaible;
}

//automathic car
AutomaticCar::AutomaticCar(int maxSpeed, int fuel) :Car(maxSpeed, fuel) {}
void AutomaticCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
	if (speedIncrease + this->curSpeed <= maxSpeed) {
		Car::increaseSpeed(speedIncrease, fuelConsumtion);
	}
}
void AutomaticCar::decreaseSpeed(int speedDecrease) {
	Car::decreaseSpeed(speedDecrease * 2);
}

//manual car
ManualCar::ManualCar(const std::vector<int>& shiftSpeeds, int maxSpeed, int fuel) :Car(maxSpeed, fuel), _shiftSpeeds(shiftSpeeds) {}
void ManualCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
	size_t _currShiftIdx = findShiftIdx();
	int beforeIncreaseShiftCopy = _currShiftIdx;
	if (speedIncrease + this->curSpeed <= maxSpeed) {
		Car::increaseSpeed(speedIncrease, fuelConsumtion);
		_currShiftIdx = findShiftIdx();
	}
	if (beforeIncreaseShiftCopy < _currShiftIdx) {
		fuelAvaible -= fuelConsumtion;
	}
	if (fuelAvaible < 0) {	//cant have negative fuel
		fuelAvaible = 0;
	}
}
void ManualCar::decreaseSpeed(int speedDecrease) {
	Car::decreaseSpeed(speedDecrease);
}

size_t ManualCar::findShiftIdx() const {
	int lowerThreshhold = 0;
	int index = 1;
	for (auto it = _shiftSpeeds.cbegin(); it != _shiftSpeeds.cend(); it++, index++) {
		if (curSpeed >= lowerThreshhold and curSpeed < *it) {
			return index;
		}
		lowerThreshhold = *it;
	}
	return _shiftSpeeds.empty() ? 0 : _shiftSpeeds.size() + 1;
}