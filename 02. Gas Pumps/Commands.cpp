#include "commands.h"

#include <iostream>
#include <sstream>

using namespace std;
//end command

void EndCommand::process(void) {
	ostringstream cycles;
	this->outputTicks(cycles);
	cycles << ": Final gas quantity: " << GasReservoir::get().getQuantity() << " kg3";
	cout << cycles.str() << endl;
}

//init command
InitCommand::InitCommand(std::istream& istr) :Command(istr) { istr >> initQ; }
void InitCommand::process(void) {
	GasReservoir::get().setQuantity(initQ);

	ostringstream cycles;
	this->outputTicks(cycles);
	cycles << ": Gas quantity: " << GasReservoir::get().getQuantity() << " kg3";
	cout << cycles.str() << endl;
}
InitCommand::~InitCommand() = default;

//in command
InCommand::InCommand(std::istream& istr) :TwoParametersCommand(istr) {}
void InCommand::process(void) {
	GasReservoir::get().addCycles(getPar2());
	GasReservoir::get().setQuantity(GasReservoir::get().getQuantity() + (getPar1() * getPar2()));

	ostringstream cycles;
	this->outputTicks(cycles);
	cycles << ": Pumping in " << getPar1() << " kg3 for " << getPar2() << " hours, remaining " << GasReservoir::get().getQuantity() << " kg3";
	cout << cycles.str() << endl;
}
InCommand::~InCommand() = default;

//out command
OutCommand::OutCommand(std::istream& istr) :TwoParametersCommand(istr) {}
void OutCommand::process(void) {
	GasReservoir::get().addCycles(getPar2());

	if (GasReservoir::get().getQuantity() == 0) {
		ostringstream cycles;
		this->outputTicks(cycles);
		cycles << ": Gas Storage Empty.";
		cout << cycles.str() << endl;
		return;
	}
	int requiredDemand = getPar1() * getPar2();
	GasReservoir::get().setQuantity(GasReservoir::get().getQuantity() - requiredDemand);

	ostringstream cycles;
	this->outputTicks(cycles);
	if (GasReservoir::get().getQuantity() < 0) {
		int shortage = -1 * GasReservoir::get().getQuantity();
		GasReservoir::get().setQuantity(0);
		cycles << ": Delivering out " << requiredDemand - shortage << " kg3 (shortage " << shortage << " kg3), remaining " << GasReservoir::get().getQuantity() << " kg3";
	}
	else {
		cycles << ": Delivering out " << requiredDemand << " kg3, remaining " << GasReservoir::get().getQuantity() << " kg3";
	}

	cout << cycles.str() << endl;
}
OutCommand::~OutCommand() = default;

//demand command
DemandCommand::DemandCommand(std::istream& istr) :TwoParametersCommand(istr) {}
void DemandCommand::process(void) {
	if (GasReservoir::get().getQuantity() == 0) {
		ostringstream cycles;
		this->outputTicks(cycles);
		cycles << ": CHECK: Gas Storage Empty.";
		cout << cycles.str() << endl;
		return;
	}

	int requiredDemand = getPar1() * getPar2();
	if (requiredDemand <= GasReservoir::get().getQuantity()) {
		ostringstream cycles;
		this->outputTicks(cycles);
		cycles << ": CHECK: OK.";
		cout << cycles.str() << endl;
		return;
	}
	else {
		int shortage = requiredDemand - GasReservoir::get().getQuantity();
		int possibleToFillAmount = GasReservoir::get().getQuantity() / getPar2();
		ostringstream cycles;
		this->outputTicks(cycles);
		cycles << ": CHECK: Shortage of " << shortage << ": availability " << possibleToFillAmount << " for " << getPar2() << " hours";
		cout << cycles.str() << endl;
	}
}

DemandCommand::~DemandCommand() = default;