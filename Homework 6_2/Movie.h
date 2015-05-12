// ----------------------------------------------------------------------------
//
//  Movie class
//    Header
//
//  This class represents a movie, featuring a title, director, rating, 
//  year of release, and URL for further information in the Internet
//  Movie Database (IMDB, http://www.imdb.com ) .
//
// ----------------------------------------------------------------------------
//
//  Author:         JL Popyack
//  Date:           4/4/4
//  Modified:       4/2/14  -- JL Popyack, removed destructor
//					6/4/14  -- Stevie Parris, Revised class to store actors and movies with linked lists
//
// ----------------------------------------------------------------------------

	#ifndef _MYMOVIE_
	#define _MYMOVIE_

	#include <iostream>
	#include <string>
	#include <vector>
	#include <sstream> // used to convert streams to strings
	#include <cstdlib>
	#include <ciso646>
	#include <fstream>
	#include "Actor.h"

	class Actor;

	using namespace std;
	
	enum Movie_Rating { G, PG, PG13, R, NC17, NR };

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

	class Movie
	{
	  
		public:
		// ------------------------------------------------------
		// ----- Constructors -----------------------------------
		// ------------------------------------------------------
			
			Movie();
			Movie(const string & title);
			Movie(const Movie &old);
			Movie(const string & title, 
			      const string & director, 
			      Movie_Rating rating,
			      unsigned int year,
			      const string & path) ;
		  	
		// ------------------------------------------------------
		// ----- Destructor -------------------------------------
		// ------------------------------------------------------
		
			Movie::~Movie();  // To be implemented in a future assignment.
	  	
		// ------------------------------------------------------
		// ----- Inspectors -------------------------------------
		// ------------------------------------------------------

			string getName() const;
			string getDirector() const;
			Movie_Rating getRating() const;
			unsigned int getYear() const;
			string getURL() const;
			int getNumberOfActors() const;
			string getActorName(int i) const;
			Actor *getActor(int i) const;

		// ------------------------------------------------------
		// ----- Mutators ---------------------------------------
		// ------------------------------------------------------

			void output(ostream & out);
			void setName(const string& title);
			void setDirector(const string& director);
			void setRating(Movie_Rating rating);
			void setYear(unsigned int year);
			void setURL(const string& path);
			void addActor(Actor *p);
		  	

	// ----------------------------------------------------------
	// ----------------------------------------------------------

	private:
		string title_ ;
		string director_ ;
		Movie_Rating rating_ ;
		unsigned int year_ ;
		string url_ ;
		List<Actor*> actorList_;
		int numActors_;
	};


	ostream& operator<< (ostream & out, const Movie & myFile);

	//
	//
	//----------------------------------------------------------------------------

	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	// ----------------------------------------------------------------------------
	// ----------------------------------------------------------------------------
	#endif