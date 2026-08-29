#include "AutomaticCar.h"

#include <algorithm>

AutomaticCar::AutomaticCar(int maxSpeed, int fuel) : Car(maxSpeed, fuel) {}

void AutomaticCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
  if (_fuel < fuelConsumtion) {
    _fuel = 0;
    _speed = 0;
    _outOfFuel = true;
    return;
  }
  _fuel -= fuelConsumtion;
  _speed = std::min(_speed + speedIncrease, _maxSpeed);
}

void AutomaticCar::decreaseSpeed(int speedDecrease) {
  _speed = std::max(_speed - speedDecrease * 2, 0);
}
