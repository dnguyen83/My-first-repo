#include "Template Method.h"

void Base::execute() {
	a();
	ph1();
	c();
	ph2();
	e();
}

void Base::a() {
	printf("Base::a\n");
}

void Base::c() {
	printf("Base::c\n");
}

void Base::e() {
	printf("Base::c\n");
}

void One::ph1() {
	printf("One::b\n");
}

void One::ph2() {
	printf("One::d\n");
}

void Two::ph1() {
	printf("Two::2\n");
}

void Two::ph2() {
	printf("Two::4\n");
}