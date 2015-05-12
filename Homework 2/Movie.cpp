

#include "Movie.h"
#include <cstdlib>
#include <ciso646>
#include <sstream> // used to convert streams to strings
#include <iostream>
#include <vector>

using namespace std;

vector<string> blank;

//Blank Movie constructor, if no parameters, set values to null
Movie::Movie()
{
	title_ = "";
	director_ = "";
	rating_ = Movie_Rating();
	year_ = 0;
	url_ = "";
	actors_;
}

//Title Movie constructor, if only title, assign title value and leave rest blank
Movie::Movie(const string& title)
{
	title_ = title;
	director_ = "";
	rating_ = Movie_Rating();
	year_ = 0;
	url_ = "";
	actors_;
}

//Full Movie constructor, assign values passed to the attributes of the object in the class
Movie::Movie(const string& title = "", 
			 const string& director = "",
			 Movie_Rating rating = Movie_Rating(),
			 unsigned int year = 0,
			 const string& path = "", 
			 vector<string> actors = blank)
{
	title_ = title;
	director_ = director;
	rating_ = rating;
	year_ = year;
	url_ = path;
	actors_ = actors;
}

//copy constructor
Movie::Movie(const Movie & old)
{
	this->title_ = old.title_;
	this->director_ = old.director_;
	this->rating_ = old.rating_;
	this->year_ = old.year_;
	this->url_ = old.url_;
	this->actors_ = old.actors_;
}


Movie::~Movie()
{
	actors_.resize(0);
}

string Movie::getTitle() const
{
	return title_;
}

string Movie::getDirector() const
{
	return director_;
}

Movie_Rating Movie::getRating() const
{
	return rating_;
}

unsigned int Movie::getYear() const
{
	return year_;
}
string Movie::getURL() const
{
	return url_;
}
int Movie::getNumberOfActors() const
{
	return actors_.size();
}
string Movie::getActorName(int i) const
{
	if (0 <= i && i <= getNumberOfActors())
		return actors_[i];
	else
		return "";
}


void Movie::setDirector(const string& director)
{	
	director_ = director;
}
void Movie::setRating(Movie_Rating rating)
{
	rating_ = rating;
}
void Movie::setYear(unsigned int year)
{
	year_ = year;
}
void Movie::setURL(const string& path)
{
	url_ = path;
}

void Movie::addActor(const string & name)
{
	actors_.push_back(name);
}

void  Movie::output(ostream & out)
{
	Movie_Rating rating = this->getRating();
	string nmRating;
	//this->command() is the same as (*this).command()
	//both of these call the object that you call the function on Ex:
	// Movie.getRating(PARAMETER)   "Movie" is the (*this)    or   this->

	// so, when you're trying to compare two different English_length's, you use the object argument and the one it's being performed on.
	//"Movie" is the thing it's being performed on, PARAMETER is the object argument, then you just compare their values

	// Convert Movie_Rating to string
	if (rating == G)
		nmRating = "G";
	if (rating == PG)
		nmRating = "PG";
	if (rating == PG13)
		nmRating = "PG13";
	if (rating == R)
		nmRating = "R";
	if (rating == NC17)
		nmRating = "NC17";
	if (rating == NR)
		nmRating = "NR";


	// Output the information to the source passed
	out << "Movie: " << this->getTitle() << endl; // this returns a string
	out << "Director: " << this->getDirector() << endl; //this returns a string
	out << "Year: " << this->getYear() << endl; // this returns an integer
	out << "Rating: " << nmRating << endl; // this would return a Movie_Rating which has no cout function so it had to be transformed above
	out << "IMDB URL: " << this->getURL() << endl << endl; // this returns a string
	out << "Actors: " << endl;
	for (int i = 0; i < getNumberOfActors(); i++)
		out << "   " << actors_[i] << endl;
}