#include "Abstract Factory.h"
#include <stdio.h>

House* MaisonetteFactory::createRoof() {
	return new RoofMaisonette;
}

House* MaisonetteFactory::createTires() {
	return new TiresMaisonette;
}

House* MaisonetteFactory::createWindow() {
	return new WindowMaisonette;
}

House* FlatFactory::createRoof() {
	return new RoofFlat;
}

House* FlatFactory::createTires() {
	return new TiresFlat;
}

House* FlatFactory::createWindow() {
	return new WindowFlat;
}

void RoofMaisonette::whatAmI() {
	printf("I am RoofMaisonette");
}

void WindowMaisonette::whatAmI() {
	printf("I am WindowMaisonette");
}

void TiresMaisonette::whatAmI() {
	printf("I am TiresMaisonette");
}

void RoofFlat::whatAmI() {
	printf("I am RoofFlat");
}

void WindowFlat::whatAmI() {
	printf("I am WindowFlat");
}

void TiresFlat::whatAmI() {
	printf("I am TiresFlat");
}