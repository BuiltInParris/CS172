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
//
// ----------------------------------------------------------------------------
	#ifndef _MOVIE_
	#define _MOVIE_

	#include <iostream>
	#include <string>
	#include <vector>
	
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
			Movie(const Movie & old);
			Movie(const string & title, 
			      const string & director, 
			      Movie_Rating rating,
			      unsigned int year,
			      const string & path,
				  vector<string> actors) ;
		  	
		// ------------------------------------------------------
		// ----- Destructor -------------------------------------
		// ------------------------------------------------------
		
			Movie::~Movie();  // To be implemented in a future assignment.
	  	
		// ------------------------------------------------------
		// ----- Inspectors -------------------------------------
		// ------------------------------------------------------

			string getTitle() const;
			string getDirector() const;
			Movie_Rating getRating() const;
			unsigned int getYear() const;
			string getURL() const;
			int getNumberOfActors() const;
			string getActorName(int i) const;

		// ------------------------------------------------------
		// ----- Mutators ---------------------------------------
		// ------------------------------------------------------

			void output(ostream & out);
			void setDirector(const string& director);
			void setRating(Movie_Rating rating);
			void setYear(unsigned int year);
			void setURL(const string& path);
			void addActor(const string & name);
		  	

	// ----------------------------------------------------------
	// ----------------------------------------------------------

	private:
		string title_ ;
		string director_ ;
		Movie_Rating rating_ ;
		unsigned int year_ ;
		string url_ ;
		vector <string> actors_ ;
	};
	#endif