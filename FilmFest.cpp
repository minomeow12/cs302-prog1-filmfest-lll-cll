#include "FilmFest.h"

//Default constructor
Event::Event() : name(nullptr), location("Unknown"), price(0.0f) {}

//Argument constructor
Event::Event(const char * init_name, const string & init_location, float init_price) :   name(nullptr), location(init_location), price(init_price)
{
	this->name = new char[strlen(init_name) +1];
	strcpy(this -> name, init_name);
}

//Copy constructor
Event::Event(const Event & source) : name(nullptr), location(source.location), price(source.price) 
{
	this -> name = new char[strlen(source.name) +1];
	strcpy(this -> name, source.name);
}

//Destructor
Event::~Event() {
	delete [] name;
	name = nullptr;
}

//Assignment operator
Event & Event::operator=(const Event & source)
{
	if (this == &source) return *this;
	if (name)
	{
		delete [] name;
		name = nullptr;
	}
        if (source.name)
	{
		name = new char[strlen(source.name) +1];
		strcpy(name, source.name);
	}
	else
		name = nullptr;
	return *this;	
}


//purchase a ticket
bool Event::purchaseTicket(float & balance)
{
	if (balance < price) {
		cout << "Sorry, we don't have enough money for " << name << endl;
		return false;
	}
        balance -= price;
	cout << "Ticket purchased for " << name << " at " << location << endl;
	return true;
}	

// check if affordable 
bool Event::isAffordable(float balance) const {
	return balance >= price;
}

//see discounted price
float Event::getDiscountedPrice(float discountRate) const {
	if (discountRate < 0.0f || discountRate > 1.0f)
		return price;
	return price * (1.0f - discountRate);
}

//display event info
bool Event::display() const {
	cout<< "Event: " << name << "\nLocation: " << location << "\nPrice: $" << price << endl;
	return true;
}

//compare by name
int Event::compare(const char * to_compare) const {
	return strcmp(name, to_compare);
}

//check keyword in name or location
bool Event::match(const string & keyword) const {
	return location.find(keyword) != string::npos || string(name).find(keyword) != string::npos;
}

