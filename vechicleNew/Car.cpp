#include "Car.h"

#include <algorithm>

Car::Car(int maxSpeed, int fuel) : _fuel(fuel), _maxSpeed(maxSpeed) {}

void Car::advance() { _distance += _speed; }

bool Car::ranOutOfFuel() const { return _outOfFuel; }

int Car::getSpeed() const { return _speed; }
int Car::getFuel() const { return _fuel; }
int Car::getMaxSpeed() const { return _maxSpeed; }
long long Car::getTotalDistance() const { return _distance; }
