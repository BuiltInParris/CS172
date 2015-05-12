

#include "Movie.h"
#include <cstdlib>
#include <ciso646>
#include <sstream> // used to convert streams to strings
#include <iostream>
#include <vector>

using namespace std;

vector<string> blank;



//----------------------------------------------------------------------------
//----- MovieNode Implementation -----------------------------------------
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//----- Constructors ---------------------------------------------------------
//----------------------------------------------------------------------------

MovieNode::MovieNode(Actor myActor)
{
	myActor_ = myActor;
	link_ = NULL;
}

MovieNode::MovieNode()
{
	link_ = NULL;
}

//----------------------------------------------------------------------------
//----- Destructor -----------------------------------------------------------
//----------------------------------------------------------------------------

MovieNode::~MovieNode()
{
		//delete link_;
}

//----------------------------------------------------------------------------
//----- Inspectors -----------------------------------------------------------
//----------------------------------------------------------------------------

Actor MovieNode::getActor() const
{
	return myActor_;
}

MovieNode* MovieNode::link() const
{
	return link_;
}

//----------------------------------------------------------------------------
//----- Mutators -------------------------------------------------------------
//----------------------------------------------------------------------------

void MovieNode::setLink(MovieNode* target)
{
	link_ = target;
}

//----------------------------------------------------------------------------
//----- Facilitators ---------------------------------------------------------
//----------------------------------------------------------------------------

void MovieNode::output(ostream& out) const
{
	// FIX THIS LINE :
	out << "Actor ";
}

//----------------------------------------------------------------------------
//----- MovieNode: auxiliary operator descriptions -----------------------
//----------------------------------------------------------------------------

ostream& operator<< (ostream& out, const MovieNode& pn)
{
	pn.output(out);
	return out;
}

ostream& operator<< (ostream& out, const MovieNode* myActor)
{
	if (myActor != NULL)
		myActor->output(out);
	return out;
}



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
	first_ = NULL;
	last_ = NULL;
}

//Title Movie constructor, if only title, assign title value and leave rest blank
Movie::Movie(const string& title)
{
	title_ = title;
	director_ = "";
	rating_ = Movie_Rating();
	year_ = 0;
	url_ = "";
	first_ = NULL;
	last_ = NULL;
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
	first_ = NULL;
	last_ = NULL;
}

//copy constructor
Movie::Movie(const Movie &old)
{
	title_ = old.getTitle();
	director_ = old.getDirector();
	rating_ = old.getRating();
	year_ = old.getYear();
	url_ = old.getURL();
	first_ = old.getFirst();
	last_ = old.getLast();
}


Movie::~Movie()
{
	delete first_;
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

MovieNode* Movie::getFirst() const
{
	return first_;
}
MovieNode* Movie::getLast() const
{
	return last_;
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

	MovieNode* ptr;

	if (i<0 or i>numActors_)
		return "Error: Out of bounds.";

	ptr = first_;
	while (i>0 and ptr != NULL)
	{
		ptr = ptr->link();
		i--;
	}
	if (ptr == NULL)
		return "Error: Out of bounds .";
	else
		return ptr->getActor().getName();
}

Actor Movie::getActor(int i) const
{
	//---------------------------------------------------------------------
	//  Retrieves point i from the polygon.
	//---------------------------------------------------------------------

	MovieNode* ptr;

	if (i<0 or i>numActors_)
		return "Error: Out of bounds.";

	ptr = first_;
	while (i>0 and ptr != NULL)
	{
		ptr = ptr->link();
		i--;
	}
	if (ptr == NULL)
		return "Error: Out of bounds .";
	else
		return ptr->getActor();
}

void Movie::setTitle(const string& title)
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


void Movie::addActor(const Actor &p)
{
	//---------------------------------------------------------------------
	//  Adds a new point to the end of the polygon.
	//---------------------------------------------------------------------

	MovieNode* myActor;
	myActor = new MovieNode(p);
	if (last_ != NULL)
		last_->setLink(myActor);
	last_ = myActor;
	if (first_ == NULL)
		first_ = last_;
	numActors_++;
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
	//for (int i = 0; i < getNumberOfActors(); i++)
	//	out << "   " << this->getActorName[i] << endl;
}