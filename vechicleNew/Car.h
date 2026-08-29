#ifndef CAR_H_
#define CAR_H_

#include <cstddef>

class Car {
public:
	Car(int maxSpeed, int fuel);
	virtual ~Car() = default;

	virtual void increaseSpeed(int speedIncrease, int fuelConsumtion) = 0;
	virtual void decreaseSpeed(int speedDecrease) = 0;

	void advance();
	bool ranOutOfFuel() const;

	int getSpeed() const;
	int getFuel() const;
	int getMaxSpeed() const;
	long long getTotalDistance() const;

protected:
	int _speed{ 0 };
	int _fuel;
	int _maxSpeed;
	long long _distance{ 0 };
	bool _outOfFuel{ false };
};

#endif /* CAR_H_ */
