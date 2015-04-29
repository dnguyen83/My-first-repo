#include "Mediator.h"

void Window::pressButton() {
	m_mediator->notifyChange(this);
}

void Window::doPressButton() {
	printf("Window activated\n");
}

void Tab::pressButton() {
	m_mediator->notifyChange(this);
}

void Tab::doPressButton() {
	printf("Tab activated\n");
}

Mediator::Mediator() {
	bases[0] = new Window(this);
	bases[1] = new Tab(this);
}

void Mediator::notifyChange(Base* object) {
	if(bases[0] == object) {
		bases[0]->doPressButton();
		bases[1]->wait();
	} else if(bases[1] == object){
		bases[0]->wait();
		bases[1]->doPressButton();
	}
}

void Mediator::handleEvent(ObjectEvents events) {
	switch(events) {
	case WINDOW_BUTTON:
		bases[0]->pressButton();
		break;
	case TAB_BUTTON:
		bases[1]->pressButton();
		break;
	}
}