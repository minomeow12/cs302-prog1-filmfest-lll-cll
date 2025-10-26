
//Evelyn Nguyen, CS302, prog1, 10/8/25
//Workshop cpp file
#include "FilmFest.h"

Workshop::Workshop() : Event(), topic("N/A"), instructor("N/A"), seatsAvailable(0) {}

Workshop::Workshop(const char * init_name, const string & init_topic, const string & init_instructor, int init_seats, float init_price) : Event(init_name, "Workshop Tent", init_price), topic(init_topic), instructor(init_instructor), seatsAvailable(init_seats) {}

Workshop::~Workshop() {}

bool Workshop::registerAttendee(const string & attendee) 
{
	if (seatsAvailable <= 0)
	{
		cout << "Sorry, the workshop is full.\n";
		return false;
	}
	attendees.push_back(attendee);
	--seatsAvailable;
	cout << attendee << " has been registered for the workshop: " << topic << endl;
	return true;
}

bool Workshop::cancelRegistration(const string & attendee) 
{
        bool found = false;	
	for (auto it = attendees.begin(); it != attendees.end() && !found; ++it)
	{
		if (*it == attendee) {
			attendees.erase(it);
			++seatsAvailable;
			cout << attendee << " canceled their registration.\n";
			found =  true;
		}
	}
	if (!found)
		cout << attendee << " is not in the regiter list.\n";
	return found;
}

bool Workshop::printCertificate() const 
{
	cout << "Certificate of Completetion: " << topic << " by " << instructor << endl;
	return true;
}

bool Workshop::display() const
{
    Event::display();
    cout << "Topic: " << topic
         << "\nInstructor: " << instructor
         << "\nSeats Available: " << seatsAvailable
         << "\nAttendees: ";
    for (const auto & a : attendees)
        cout << a << ", ";
    cout << endl;
    return true;
}
