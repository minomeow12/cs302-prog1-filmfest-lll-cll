//Evelyn Nguyen, CS302, prog1, 10/6/25
//Octoberfest header file.

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int NAME_SIZE = 51; //dynamically allocated array
			

// =====================
// PART 1 - Base class: Event
class Event 
{
	public: 
		//Constructors
		Event(); //default
		Event(const char * init_name, const string & init_location, float init_price); //argument
	        Event(const Event & source); //copy
	
 		//Destructor
		~Event();

		//Assignment op
		Event & operator = (const Event & source);
		
		//Shared functions
	        bool display() const;
		int compare(const char * to_compare) const;
		bool match(const string & keyword) const;

		//3 functions
		bool purchaseTicket(float & balance);
		bool isAffordable(float balance) const;
		float getDiscountedPrice(float discountRate) const;	

	protected:
		char * name;
		string location;
		float price;
};

// =====================
// PART 2 - Derived class: Screening
class Screening : public Event
{
	public: 
		//Constructors
		Screening();
		Screening(const char * init_name, const char * init_filmTitle, const string & init_genre, int init_duration, float init_price);
		Screening(const Screening & source);

		//Destructor
		~Screening();

		//Assm op
		Screening& operator = (const Screening & source);

		//3 new functions (for customers)
		bool purchaseTicket(float & balance);
		bool viewSchedule() const;
		bool rateFilm(int rating);
		//display
		bool display() const;

	private:
		char * filmTitle;
		string genre;
		int duration;
		float avgRating;
		int numRatings;
};


// =====================
// PART 3 - Derived class: Workshop
class Workshop : public Event
{
	public:
		//constructors
		Workshop();
		Workshop(const char * init_name, const string & init_topic, const string & init_instructor, int init_seats, float init_price);
		
		//destructor
		~Workshop();

		//3 new functions
		bool registerAttendee(const string & attendee);
		bool cancelRegistration(const string & attendee);
		bool printCertificate() const;
		//display
		bool display() const;

	private:
		string topic;
		string instructor;
		int seatsAvailable;
		vector<string> attendees;
};

// =====================
// PART 4 - Derived class: MerchBooth
class MerchBooth : public Event
{
	public: 
		//constructor
		MerchBooth();
		MerchBooth(const char * name, const vector<string> & init_items, const vector<float> & init_prices, float init_price);
		

		//Destructor
		~MerchBooth();

		//3 new functions
		bool listItems() const;
		bool purchaseItem(const string & itemName, float & balance);
		bool restock(const string & itemName, float price);
		//display
		bool display() const;
		bool removeItem(const string & itemName); 
	private:
		vector<string> items;
		vector<float> prices;
};
