#pragma once

#include <cstddef>
class Car {
protected:
	int curSpeed = 0;
	int distanceTraveled = 0;

	int maxSpeed;
	int fuelAvaible;

	Car(int maxSpeed, int fuel);
public:
	virtual void increaseSpeed(int speedIncrease, int fuelConsumtion);
	virtual void decreaseSpeed(int speedDecrease);
	void addDistance(int distanceToAdd);
	int getCurSpeed()const;
	int getDistance() const;
	int getFuelRemaining()const;
};