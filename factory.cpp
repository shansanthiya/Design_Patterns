//Factory Pattern
#include <iostream> 
using namespace std;


class Vehicle {
public:
	virtual void printVehicle() = 0;
};
class TwoWheeler : public Vehicle {
public:
	void printVehicle() {
		cout << "I am two wheeler" << endl;
	}
};
class FourWheeler : public Vehicle {
public:
	void printVehicle() {
		cout << "I am four wheeler" << endl;
	}
};

class VehicleFactory {

public:
	Vehicle* createV(int type) {

		Vehicle* createVeh = NULL;
		if (type == 1)
			createVeh = new TwoWheeler();
		else if (type == 2)
			createVeh = new FourWheeler();
		else
			createVeh = NULL;
		return createVeh;
	}
};

class Client {
private:
	Vehicle* pVehicle;

public:
	Client(int type) {

		/*
		// Client explicitly creates classes according to type
		if (type == 1)
			pVehicle = new TwoWheeler();
		else if (type == 2)
			pVehicle = new FourWheeler();
		else
			pVehicle = NULL;
		*/

		VehicleFactory* vp;
		pVehicle = vp->createV(type);
	}

	~Client() {
		if (pVehicle)
		{
			delete[] pVehicle;
			pVehicle = NULL;
		}
	}

	Vehicle* getVehicle() {
		return pVehicle;
	}

};

int main() {
	Client* pClient = new Client(2);
	Vehicle* pVehicle = pClient->getVehicle();
	pVehicle->printVehicle();
	return 0;
}