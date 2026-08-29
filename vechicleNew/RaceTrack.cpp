#include "RaceTrack.h"

#include "AutomaticCar.h"
#include "ManualCar.h"

#include <iostream>

bool RaceTrack::isRaceRunning() const {
  for (const auto& car : _cars) {
    if (car->ranOutOfFuel()) return false;
  }
  return true;
}

void RaceTrack::printWinner() {
  for (size_t i = 0; i < _cars.size(); ++i) {
    if (_cars[i]->ranOutOfFuel()) {
      std::cout << "Car with index: " << (1 - i) << " won!" << std::endl;
      return;
    }
  }

  long long d0 = _cars[0]->getTotalDistance();
  long long d1 = _cars[1]->getTotalDistance();

  if (d0 > d1) std::cout << "Car with index: 0 won!" << std::endl;
  else if (d1 > d0) std::cout << "Car with index: 1 won!" << std::endl;
  else std::cout << "No winner" << std::endl;
}

void RaceTrack::createManualCar(const std::vector<int>& shifts, int maxSpeed, int startFuel) {
  _cars.push_back(std::make_unique<ManualCar>(shifts, maxSpeed, startFuel));
}

void RaceTrack::createAutomaticCar(int maxSpeed, int startFuel) {
  _cars.push_back(std::make_unique<AutomaticCar>(maxSpeed, startFuel));
}

void RaceTrack::increaseSpeed(int speedIncrease, int fuelConsumtion) {
  for (auto& car : _cars) car->increaseSpeed(speedIncrease, fuelConsumtion);
}

void RaceTrack::decreaseSpeed(int speedDecrease) {
  for (auto& car : _cars) car->decreaseSpeed(speedDecrease);
}

void RaceTrack::advance() {
  for (auto& car : _cars) car->advance();
}

void RaceTrack::printInfo() const {
  for (size_t i = 0; i < _cars.size(); ++i) {
    std::cout << "Car with index: " << i
              << " has totalDistance: " << _cars[i]->getTotalDistance()
              << ", is running with " << _cars[i]->getSpeed()
              << " speed, has " << _cars[i]->getFuel() << " fuel left"
              << std::endl;
  }
}
