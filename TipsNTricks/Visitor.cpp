#include "Visitor.h"

void DatHouse::accept(Visitor* v) {
	v->visits(this);
}

void MumHouse::accept(Visitor* v) {
	v->visits(this);
}

void Relatives::visits(DatHouse* e) {
	e->drinkTea();
}

void Relatives::visits(MumHouse* e) {
	e->eatsDinner();
}