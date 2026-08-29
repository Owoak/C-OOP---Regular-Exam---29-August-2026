#include "ManualCar.h"
#include <algorithm>

//manual car dedinition
ManualCar::ManualCar(const std::vector<int>& shiftSpeeds, int maxSpeed, int fuel)
	: Car(maxSpeed, fuel), _shiftSpeeds(shiftSpeeds) {
}

void ManualCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
	size_t oldShift = findShiftIdx();
	_speed = std::min(_speed + speedIncrease, _maxSpeed);

	int cost = fuelConsumtion;
	if (findShiftIdx() != oldShift)
		cost *= 2;

	if (_fuel < cost) {
		_fuel = 0;
		_speed = 0;
		_outOfFuel = true;
		return;
	}

	_fuel -= cost;
	_currShiftIdx = findShiftIdx();
}

void ManualCar::decreaseSpeed(int speedDecrease) {
	_speed = std::max(_speed - speedDecrease, 0);
	_currShiftIdx = findShiftIdx();
}

size_t ManualCar::findShiftIdx() const {
	for (size_t i = 0; i < _shiftSpeeds.size(); i++) {
		if (_speed < _shiftSpeeds[i])
			return i;
	}
	return _shiftSpeeds.empty() ? 0 : _shiftSpeeds.size() - 1;
}