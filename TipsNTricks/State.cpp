#include "State.h"

Machine::Machine() {
	m_state = new OFF();
}

void Machine::setCurrent(State* s) {
	m_state = s;
}

void Machine::on() {
	m_state->on(this);
}

void Machine::off() {
	m_state->off(this);
}

void State::on(Machine* m) {
	printf("state is already on\n");
}

void State::off(Machine* m) {
	printf("state is already off\n");
}

void OFF::on(Machine* m) {
	printf("going from OFF to ON\n");
	m->setCurrent(new ON());
	delete this;
}

void ON::off(Machine* m) {
	printf("going from ON to OFF\n");
	m->setCurrent(new OFF());
	delete this;
}