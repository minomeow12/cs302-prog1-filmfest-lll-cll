
//Evelyn Nguyen, CS302, prog1, 10/8/25
//Screening  cpp file
//---SCREENING CLASS ---
#include "FilmFest.h"
#include <iomanip>

Screening::Screening() : Event(), filmTitle(nullptr), genre(""), duration(0), avgRating(0.0f), numRatings(0) {}


Screening::Screening(const char * init_name, const char * init_filmTitle, const string & init_genre, int init_duration, float init_price) : Event(init_name, "Theater", init_price), filmTitle(nullptr), genre(init_genre), duration(init_duration), avgRating(0.0f), numRatings(0)
{
	filmTitle = new char[strlen(init_filmTitle) +1];
	strcpy(filmTitle, init_filmTitle);
	
}

Screening::Screening(const Screening & source) : Event(source), filmTitle(nullptr), genre(source.genre), duration(source.duration), avgRating(source.avgRating), numRatings(source.numRatings)
{
	filmTitle = new char[strlen(source.filmTitle) +1];
	strcpy(filmTitle, source.filmTitle);
}

Screening::~Screening()
{
	delete [] filmTitle;
        filmTitle = nullptr;	
}

Screening& Screening::operator =(const Screening & source)
{
	if (this == &source) return *this;
	Event::operator=(source); // copy base data
	if (filmTitle)
	{
		delete [] filmTitle;
		filmTitle = nullptr;
	} 
	if (source.filmTitle)
	{
		filmTitle = new char[strlen(source.filmTitle) +1];
		strcpy(filmTitle, source.filmTitle);
	}
	else
		filmTitle = nullptr;
	genre = source.genre;
	duration = source.duration;
	avgRating = source.avgRating;
	numRatings = source.numRatings;
	return *this;
}

bool Screening::purchaseTicket(float & balance)
{
	return Event::purchaseTicket(balance);
}

bool Screening::viewSchedule() const
{
	cout << "Film: " << filmTitle << " (" << genre << "), Duration: " << duration << " min\n";
	return true;
}

bool Screening::rateFilm(int rating)
{
	if (rating <1 || rating > 5) return false;
	avgRating =  ((avgRating * numRatings) + rating)/ (numRatings +1);
	++numRatings;
        cout << "Thanks for rating: " << fixed << setprecision(2) << avgRating << endl; 	
	return true;
}

bool Screening::display() const {
	Event::display();
	cout << "Film Title: " << filmTitle
	     <<"\nGenre: " << genre
	     <<"\nDuration: " << duration << " minutes"
	     <<"\nAverage Rating: " << fixed << setprecision(2)  << avgRating;
	return true;
}
