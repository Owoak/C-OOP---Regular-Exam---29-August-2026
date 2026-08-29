#include "Car.h"
#include <algorithm>

//car define
Car::Car(int maxSpeed, int fuel) : _fuel(fuel), _maxSpeed(maxSpeed) {}

int Car::getSpeed() const { return _speed; }
int Car::getFuel() const { return _fuel; }
int Car::getMaxSpeed() const { return _maxSpeed; }
int Car::getTotalDistance() const { return _distance; }
bool Car::ranOutOfFuel() const { return _outOfFuel; }

void Car::advance() {
	_distance += _speed;
}