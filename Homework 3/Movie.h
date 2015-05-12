//----------------------------------------------------------------------------
//
                                                                            //  Movie class
//      Header
//
//  This class stores movie information.
//  Author: Stevie Parris
//  Date: 4/20/2014
//
//  Modified: 
//
//----------------------------------------------------------------------------

#ifndef __Movie__
#define __Movie__

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//  Date: n
//
//  Modified: 
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

class Movie
{
	public:
		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------

			Movie();
			Movie(string title, string director, Movie_Rating rating, int year, string path, vector<string> actors);
			Movie(const Movie & myMovie);

		//------------------------------------------------------
		//------- Destructor -----------------------------------
		//------------------------------------------------------

			~Movie();

		//------------------------------------------------------
		//------- Inspectors -----------------------------------
		//------------------------------------------------------

			// This method gets the value of title
			string gettitle() const;

			// This method gets the value of director
			string getdirector() const;

			// This method gets the value of rating
			Movie_Rating getrating() const;

			// This method gets the value of year
			int getyear() const;

			// This method gets the value of path
			string getpath() const;

			// This method gets the value of actors
			vector<string> getactors() const;


		//------------------------------------------------------
		//-------- Mutators ------------------------------------
		//------------------------------------------------------

			// This method sets the value of title to the value of the parameter.
			void settitle(string title);

			// This method sets the value of director to the value of the parameter.
			void setdirector(string director);

			// This method sets the value of rating to the value of the parameter.
			void setrating(Movie_Rating rating);

			// This method sets the value of year to the value of the parameter.
			void setyear(int year);

			// This method sets the value of path to the value of the parameter.
			void setpath(string path);

			// This method sets the value of actors to the value of the parameter.
			void setactors(vector<string> actors);


		//------------------------------------------------------
		//-------- Facilitators --------------------------------
		//------------------------------------------------------

		//------------------------------------------------------
		//return Movie in string form

			string toString();
		//------------------------------------------------------

		//------------------------------------------------------
		//insert Movie in output stream

			void output(ostream &out) const;
		//------------------------------------------------------

	private:
		string title_;
		string director_;
		Movie_Rating rating_;
		int year_;
		string path_;
		vector<string> actors_;
};

ostream& operator<< (ostream & out, const Movie & myFile);

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif