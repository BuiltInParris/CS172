//----------------------------------------------------------------------------
//
                                                                            //  Grid class
//      Header
//
//  This is a class that stores the location of pegs in a grid for a peg game.
//  Author: Stevie Parris
//  Date: 5/5/2014
//
//  Modified: 
//
//----------------------------------------------------------------------------

#ifndef __Grid__
#define __Grid__

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

class Grid
{
	public:
		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------

			Grid();
			Grid(vector<vector<int>> vectorHolder);

		//------------------------------------------------------
		//------- Destructor -----------------------------------
		//------------------------------------------------------

			~Grid();

		//------------------------------------------------------
		//------- Inspectors -----------------------------------
		//------------------------------------------------------

			// This method gets the value of row1
			vector<int> getrow(int x) const;

			//the value (0 or 1) at a location
			int Grid::getvalueat(int x, int y) const;

			//test if the spot is legal
			bool legalSpot(int i, int j) const;

			

		//------------------------------------------------------
		//-------- Mutators ------------------------------------
		//------------------------------------------------------

			//set the value of a point
			void Grid::setvalueat(int x, int y, int c);

		//------------------------------------------------------
		//-------- Facilitators --------------------------------
		//------------------------------------------------------

		//------------------------------------------------------
		//return Grid in string form

			string toString();
		//------------------------------------------------------

		//------------------------------------------------------
		//insert Grid in output stream

			void output(ostream &out);
		//------------------------------------------------------

	private:
		vector<vector<int>> rows_;
};

ostream& operator<< (ostream & out, Grid & myFile);

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif