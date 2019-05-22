// OBSERVER PATTERN
#include <iostream>
#include <vector>
using namespace std;

class Subject {

	vector < class Observer* > observers;
	int value;
public:
	void attach(Observer* obs) {
		observers.push_back(obs);
	}
	void setVal(int val) {
		value = val;
		notify();
	}
	int getVal() {
		return value;
	}
	void notify();
};

class Observer {

	Subject* model;

public:
	Observer(Subject* mod) {
		model = mod;
		model->attach(this);
	}
	virtual void update() = 0;
protected:
	Subject* getSubject() {
		return model;
	}

};

void Subject::notify() {

	for (int i = 0; i < observers.size(); i++)
		observers[i]->update();
}

class Observer1 : public Observer {
public:
	Observer1(Subject* mod) : Observer(mod) {}
	void update() {
		int v = getSubject()->getVal();
		cout << "value for obs1 : " << v << '\n';
	}
};

class Observer2 : public Observer {
public:
	Observer2(Subject* mod) : Observer(mod) {} //CALL BASE CLASS CONSTRUCTOR USING INITALIZATION LIST
	void update() {
		int v = getSubject()->getVal();
		cout << "value for obs2 : " << v << '\n';
	}
};

int main() {
	Subject subj;
	Observer1 Obs1(&subj);
	Observer2 Obs2(&subj);
	subj.setVal(14);
	subj.setVal(16);
}