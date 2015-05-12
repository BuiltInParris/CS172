//----------------------------------------------------------------------------
//
//                                                                             Movie class
//      Implementation
//
//  This class stores movie information.
//  Author: Stevie Parris
//  Date: 4/20/2014
//
//  Modified: 
//
//----------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Movie.h"
using namespace std;

//------------------------------------------------------
//----- Constructors -----------------------------------
//------------------------------------------------------

		Movie::Movie() {  }

		Movie::Movie(string title, string director, Movie_Rating rating, int year, string path, vector<string> actors)
		{
			title_ = title;
			director_ = director;
			rating_ = rating;
			year_ = year;
			path_ = path;
			actors_ = actors;
		}

		Movie::Movie(const Movie & myMovie)
		{
			title_ = myMovie.gettitle();
			director_ = myMovie.getdirector();
			rating_ = myMovie.getrating();
			year_ = myMovie.getyear();
			path_ = myMovie.getpath();
			actors_ = myMovie.getactors();
		}

//------------------------------------------------------
//------- Destructor -----------------------------------
//------------------------------------------------------

		Movie::~Movie()  { }

//------------------------------------------------------
//------- Inspectors -----------------------------------
//------------------------------------------------------

		// This method gets the value of title
		string Movie::gettitle() const
		{
			return title_;
		}

		// This method gets the value of director
		string Movie::getdirector() const
		{
			return director_;
		}

		// This method gets the value of rating
		Movie_Rating Movie::getrating() const
		{
			return rating_;
		}

		// This method gets the value of year
		int Movie::getyear() const
		{
			return year_;
		}

		// This method gets the value of path
		string Movie::getpath() const
		{
			return path_;
		}

		// This method gets the value of actors
		vector<string> Movie::getactors() const
		{
			return actors_;
		}

//------------------------------------------------------
//-------- Mutators ------------------------------------
//------------------------------------------------------

		// This method sets the value of title to the value of the parameter.
		void Movie::settitle(string title)
		{
				title_ = title;
		}

		// This method sets the value of director to the value of the parameter.
		void Movie::setdirector(string director)
		{
				director_ = director;
		}

		// This method sets the value of rating to the value of the parameter.
		void Movie::setrating(Movie_Rating rating)
		{
				rating_ = rating;
		}

		// This method sets the value of year to the value of the parameter.
		void Movie::setyear(int year)
		{
				year_ = year;
		}

		// This method sets the value of path to the value of the parameter.
		void Movie::setpath(string path)
		{
				path_ = path;
		}

		// This method sets the value of actors to the value of the parameter.
		void Movie::setactors(vector<string> actors)
		{
				actors_ = actors;
		}


//------------------------------------------------------
//-------- Facilitators --------------------------------
//------------------------------------------------------

		string Movie::toString()
		{
			//---------------------------------------------------------------------
			//  Fill this code with code that changes your dataType into a string
			//---------------------------------------------------------------------
			return "";
		}
//------------------------------------------------------

		void Movie::output(ostream &out) const
		{
			out << toString();
		}
		ostream& operator<< (ostream & out, const Movie & myFile)
		{
			Movie.output();
			return out;
		}
