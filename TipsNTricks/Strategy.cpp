#include "Strategy.h"
#include <stdio.h>

StringType::~StringType() {
	if(m_strategy == NULL) {
		delete m_strategy;
	}
}

void StringType::doIt(string words, int type) {
	switch(type) {
	case APPEND:
		if(m_strategy != NULL) {
			delete m_strategy;
			m_strategy = NULL;
		}

		m_strategy = new append;
		m_strategy->format(words);
		break;
	case CUT:
		if(m_strategy != NULL) {
			delete m_strategy;
			m_strategy = NULL;
		}

		m_strategy = new cut;
		m_strategy->format(words);

		break;
	}
}

void Strategy01::format(string words) {
	strategy(words);
}

void append::strategy(string words) {
	words += " this is append strategy";
	printf("%s", words.c_str());
}

void cut::strategy(string words) {
	words += " this is cut strategy";
	printf("%s", words.c_str());
}

void Strategy02::doIt(string words) {
	m_method(words);
}