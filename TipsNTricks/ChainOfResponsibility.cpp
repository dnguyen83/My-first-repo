#include "ChainOfResponsibility.h"

Base::Base() : m_next(NULL) {

}

void Base::setNext(Base* n) {
	m_next = n;
}

void Base::add(Base* n) {
	if(m_next) {
		m_next->add(n);
	} else {
		m_next = n;
	}
}

void Base::handle(int i) {
	m_next->handle(i);
}

void H1::handle(int i) {
	if (i == 10) {
		printf("H1 handled 10\n");
	} else {
		Base::handle(i);
	}
}

void H2::handle(int i) {
	if (i == 1) {
		printf("H2 handled 1\n");
	} else {
		printf("chain can't handle this shit: %d", i);
	}
}