#include "Builder.h"

Builder::Builder()
{
	m_profile = new Profile();
}


void Profile::setLanguage(const char* language) {
	m_language = language;
}

void Profile::setCountry(const char* country) {
	m_country = country;
}

void Profile::setName(const char* name) {
	m_name = name;
}

void Profile::printProfile() {
	printf("%s\n", m_name.c_str());
	printf("%s\n", m_language.c_str());
	printf("%s\n", m_country.c_str());
}

void PS4Profile::setCountry(char* country) {
	std::string fString = "PS4: ";
	fString += country;
	m_profile->setCountry(fString.c_str());
}

void PS4Profile::setLanguage(char* language) {
	std::string fString = "PS4: ";
	fString += language;
	m_profile->setLanguage(fString.c_str());
}

void PS4Profile::setName(char* name) {
	std::string fString = "PS4: ";
	fString += name;
	m_profile->setName(fString.c_str());
}

void PSVitaProfile::setCountry(char* country) {
	std::string fString = "PSVita: ";
	fString += country;
	m_profile->setCountry(fString.c_str());
}

void PSVitaProfile::setLanguage(char* language) {
	std::string fString = "PSVita: ";
	fString += language;
	m_profile->setLanguage(fString.c_str());
}

void PSVitaProfile::setName(char* name) {
	std::string fString = "PSVita: ";
	fString += name;
	m_profile->setName(fString.c_str());
}