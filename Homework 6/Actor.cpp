

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Movie.h"
#include <ciso646>

using namespace std;

//----------------------------------------------------------------------------
//----- ActorNode Implementation -----------------------------------------
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//----- Constructors ---------------------------------------------------------
//----------------------------------------------------------------------------

ActorNode::ActorNode(Movie *myMovie)
{
	myMovie_ = myMovie;
	link_ = NULL;
}

ActorNode::ActorNode()
{
	link_ = NULL;
}

//----------------------------------------------------------------------------
//----- Destructor -----------------------------------------------------------
//----------------------------------------------------------------------------

ActorNode::~ActorNode()
{
	delete link_;
}

//----------------------------------------------------------------------------
//----- Inspectors -----------------------------------------------------------
//----------------------------------------------------------------------------

Movie ActorNode::getMovie() const
{
	return *myMovie_;
}

ActorNode* ActorNode::link() const
{
	return link_;
}

//----------------------------------------------------------------------------
//----- Mutators -------------------------------------------------------------
//----------------------------------------------------------------------------

void ActorNode::setLink(ActorNode* target)
{
	link_ = target;
}

//----------------------------------------------------------------------------
//----- Facilitators ---------------------------------------------------------
//----------------------------------------------------------------------------

void ActorNode::output(ostream& out) const
{
	// FIX THIS LINE :
	out << "Movie ";
}

//----------------------------------------------------------------------------
//----- ActorNode: auxiliary operator descriptions -----------------------
//----------------------------------------------------------------------------

ostream& operator<< (ostream& out, const ActorNode& pn)
{
	pn.output(out);
	return out;
}

ostream& operator<< (ostream& out, const ActorNode* myMovie)
{
	if (myMovie != NULL)
		myMovie->output(out);
	return out;
}




//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------



	//------------------------------------------------------
	//----- Constructors -----------------------------------
	//------------------------------------------------------

	Actor::Actor()
	{
		name_ = "";
		first_ = NULL;
		last_ = NULL;
	}
	Actor::Actor(string name)
	{
		name_ = name;
		first_ = NULL;
		last_ = NULL;
	}
	//------------------------------------------------------
	//------- Destructor -----------------------------------
	//------------------------------------------------------

	Actor::~Actor()
	{
		delete first_;
		last_ = NULL;
	}

	//------------------------------------------------------
	//------- Inspectors -----------------------------------
	//------------------------------------------------------

	string Actor::getName() const
	{
		return name_;
	}

	int Actor::getNumberOfMovies() const
	{
		return numMovies_;
	}

	string Actor::getMovieName(int i) const
	{
		//---------------------------------------------------------------------
		//  Retrieves point i from the polygon.
		//---------------------------------------------------------------------

		ActorNode* ptr;

		if (i<0 or i>numMovies_)
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
			return ptr->getMovie().getTitle();
	}

	Movie Actor::getMovie(int i) const
	{
		//---------------------------------------------------------------------
		//  Retrieves point i from the polygon.
		//---------------------------------------------------------------------

		ActorNode* ptr;

		if (i<0 or i>numMovies_)
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
			return ptr->getMovie();
	}

	void Actor::addMovie(Movie *p)
	{
		//---------------------------------------------------------------------
		//  Adds a new point to the end of the polygon.
		//---------------------------------------------------------------------
		ActorNode* myMovie;
		myMovie = new ActorNode(p);
		if (last_ != NULL)
			last_->setLink(myMovie);
		last_ = myMovie;
		if (first_ == NULL)
			first_ = last_;
		numMovies_++;
	}


	//------------------------------------------------------
	//-------- Mutators ------------------------------------
	//------------------------------------------------------

	// This method sets the value of name to the value of the parameter.
	//void addMovie(Movie myMovie){
		
	//}
	//void removeMovie(Movie myMovie){}

	//------------------------------------------------------
	//-------- Facilitators --------------------------------
	//------------------------------------------------------

	//------------------------------------------------------
	//return Actor in string form

	string Actor::toString()
	{
		return "";
	}
	//------------------------------------------------------

	//------------------------------------------------------
	//insert Actor in output stream

	void Actor::output(ostream &out) const
	{
		out << "Actor ";
	}
	//------------------------------------------------------

	ostream& operator<< (ostream & out, const Actor & myFile)
	{
		//Actor.output(out);
		return out;
	}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------