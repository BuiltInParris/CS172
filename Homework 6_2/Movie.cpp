

#include "Movie.h"
#include "Actor.h"
#include "List.h"

using namespace std;

vector<string> blank;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

//Blank Movie constructor, if no parameters, set values to null
Movie::Movie()
{
	title_ = "";
	director_ = "";
	rating_ = Movie_Rating();
	year_ = 0;
	url_ = "";
	
}

//Title Movie constructor, if only title, assign title value and leave rest blank
Movie::Movie(const string& title)
{
	title_ = title;
	director_ = "";
	rating_ = Movie_Rating();
	year_ = 0;
	url_ = "";
}

//Full Movie constructor, assign values passed to the attributes of the object in the class
Movie::Movie(const string& title = "", 
			 const string& director = "",
			 Movie_Rating rating = Movie_Rating(),
			 unsigned int year = 0,
			 const string& path = "")
{
	title_ = title;
	director_ = director;
	rating_ = rating;
	year_ = year;
	url_ = path;
}

//copy constructor
Movie::Movie(const Movie &old)
{
	title_ = old.getName();
	director_ = old.getDirector();
	rating_ = old.getRating();
	year_ = old.getYear();
	url_ = old.getURL();
}


Movie::~Movie()
{
	actorList_.clear();
}

string Movie::getName() const
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
	return numActors_;
}

string Movie::getActorName(int i) const
{
	//---------------------------------------------------------------------
	//  Retrieves point i from the polygon.
	//---------------------------------------------------------------------

	return actorList_[i]->getName();
}

Actor *Movie::getActor(int i) const
{
	return actorList_[i];
}

void Movie::setName(const string& title)
{
	title_ = title;
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


void Movie::addActor(Actor *p)
{
	//---------------------------------------------------------------------
	//  Adds a new point to the end of the list.
	//---------------------------------------------------------------------
	numActors_++;
	actorList_.push_back(p);
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
	out << "Movie: " << this->getName() << endl; // this returns a string
	out << "Director: " << this->getDirector() << endl; //this returns a string
	out << "Year: " << this->getYear() << endl; // this returns an integer
	out << "Rating: " << nmRating << endl; // this would return a Movie_Rating which has no cout function so it had to be transformed above
	out << "IMDB URL: " << this->getURL() << endl << endl; // this returns a string
	out << "Actors: " << endl;
	for (int j = 0; j < this->getNumberOfActors(); j++)
	{
		cout << this->getActorName(j) << endl;
	}
}

ostream& operator<< (ostream & out, Movie & myFile)
{
	myFile.output(out);
	return out;
}
