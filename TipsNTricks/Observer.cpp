#include "Observer.h"

void Subject::attach(Observer* observer) {
	m_listeners.push_back(observer);
	observer->setSubject(this);
}

void Subject::unattach(Observer* listener) {
	std::vector<class Observer*>::iterator ite = m_listeners.begin();
	for(; ite != m_listeners.end();) {
		if(listener == (*ite)) {
			ite = m_listeners.erase(ite);
		} else {
			++ite;
		}
	}
}

void Subject::notify(const char* stuff) {
	std::vector<class Observer*>::const_iterator ite = m_listeners.begin();
	std::vector<class Observer*>::const_iterator end = m_listeners.end();
	for(; ite != end; ++ite) {
		(*ite)->update(stuff);
	}
}

void Observer::setSubject(Subject* subj) {
	m_subject = subj;
}