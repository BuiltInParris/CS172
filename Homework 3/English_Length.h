//----------------------------------------------------------------------------
//
                                                                            //  English_Length class
//      Header
//
//  This class represents an integer length in yards, feet, inches.
//  Author: Stevie Parris
//  Date: 4/20/2014
//
//  Modified: 
//
//----------------------------------------------------------------------------

#ifndef __English_Length__
#define __English_Length__

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

class English_Length
{
	public:
		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------

			English_Length();
			English_Length(int inches, int feet, int yards);
			English_Length(const English_Length & myEnglish_Length);

		//------------------------------------------------------
		//------- Destructor -----------------------------------
		//------------------------------------------------------

			~English_Length();

		//------------------------------------------------------
		//------- Inspectors -----------------------------------
		//------------------------------------------------------

			// This method gets the value of inches
			int getinches() const;

			// This method gets the value of feet
			int getfeet() const;

			// This method gets the value of yards
			int getyards() const;


		//------------------------------------------------------
		//-------- Mutators ------------------------------------
		//------------------------------------------------------

			// This method sets the value of inches to the value of the parameter.
			void setinches(int inches);

			// This method sets the value of feet to the value of the parameter.
			void setfeet(int feet);

			// This method sets the value of yards to the value of the parameter.
			void setyards(int yards);


		//------------------------------------------------------
		//-------- Facilitators --------------------------------
		//------------------------------------------------------

		//------------------------------------------------------
		//return English_Length in string form

			string toString();
		//------------------------------------------------------

		//------------------------------------------------------
		//insert English_Length in output stream

			void output(ostream &out) const;
		//------------------------------------------------------

	private:
		int inches_;
		int feet_;
		int yards_;
};
ostream& operator<< (ostream & out, const English_Length & myFile);

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif