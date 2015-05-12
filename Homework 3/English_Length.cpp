//----------------------------------------------------------------------------
//
//                                                                    English_Length class
//      Implementation
//
//  This class represents an integer length in yards, feet, inches.
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
#include "English_Length.h"
using namespace std;

//------------------------------------------------------
//----- Constructors -----------------------------------
//------------------------------------------------------

		English_Length::English_Length() {  }

		English_Length::English_Length(int inches, int feet, int yards)
		{
			inches_ = inches;
			feet_ = feet;
			yards_ = yards;
		}

		English_Length::English_Length(const English_Length & myEnglish_Length)
		{
			inches_ = myEnglish_Length.getinches();
			feet_ = myEnglish_Length.getfeet();
			yards_ = myEnglish_Length.getyards();
		}

//------------------------------------------------------
//------- Destructor -----------------------------------
//------------------------------------------------------

		English_Length::~English_Length()  { }

//------------------------------------------------------
//------- Inspectors -----------------------------------
//------------------------------------------------------

		// This method gets the value of inches
		int English_Length::getinches() const
		{
			return inches_;
		}

		// This method gets the value of feet
		int English_Length::getfeet() const
		{
			return feet_;
		}

		// This method gets the value of yards
		int English_Length::getyards() const
		{
			return yards_;
		}

//------------------------------------------------------
//-------- Mutators ------------------------------------
//------------------------------------------------------

		// This method sets the value of inches to the value of the parameter.
		void English_Length::setinches(int inches)
		{
				inches_ = inches;
		}

		// This method sets the value of feet to the value of the parameter.
		void English_Length::setfeet(int feet)
		{
				feet_ = feet;
		}

		// This method sets the value of yards to the value of the parameter.
		void English_Length::setyards(int yards)
		{
				yards_ = yards;
		}


//------------------------------------------------------
//-------- Facilitators --------------------------------
//------------------------------------------------------

		string English_Length::toString()
		{
			//---------------------------------------------------------------------
			//  Fill this code with code that changes your dataType into a string
			//---------------------------------------------------------------------
			return "";
		}
//------------------------------------------------------

		void English_Length::output(ostream &out) const
		{
			out << toString();
		}
		ostream& operator<< (ostream & out, const English_Length & myFile)
		{
			English_Length.output();
			return out;
		}
