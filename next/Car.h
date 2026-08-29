#ifndef CAR_H_
#define CAR_H_
#include <vector>

//deffine car base of Automartich and Manual
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
	int getTotalDistance() const;

protected:
	int _speed = 0;
	int _fuel;
	int _maxSpeed;
	int _distance = 0;
	bool _outOfFuel = false;
};

#endif /* CAR_H_ */
