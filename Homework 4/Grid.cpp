//----------------------------------------------------------------------------
//
//                                                                              Grid class
//      Implementation
//
//  This is a class that stores the location of pegs in a grid for a peg game.
//  Author: Stevie Parris
//  Date: 5/5/2014
//
//  Modified: 
//
//----------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Grid.h"
using namespace std;

//------------------------------------------------------
//----- Constructors -----------------------------------
//------------------------------------------------------

		Grid::Grid() {}

		Grid::Grid(vector<vector<int>> vectorHolder)
		{
			for (int i = 0; i < vectorHolder.size(); i++) 
				rows_.push_back(vectorHolder[i]);
		}

//------------------------------------------------------
//------- Destructor -----------------------------------
//------------------------------------------------------

		Grid::~Grid()  { }

//------------------------------------------------------
//------- Inspectors -----------------------------------
//------------------------------------------------------

		// This method gets the value of row1
		vector<int> Grid::getrow(int x) const
		{
			return rows_[x];
		}

		// This method gets the value of a char at a particular entry in the grid, returning whether or not it's a peg or not
		int Grid::getvalueat(int x, int y) const
		{
			vector<int> holder = rows_[y];
			return holder[x];
		}

		bool Grid::legalSpot(int xCoordinate, int yCoordinate) const
		{
			if (yCoordinate < rows_.size())
			{
				vector<int> holder = rows_[yCoordinate];

				if (xCoordinate >= 0 && xCoordinate < holder.size() && yCoordinate >= 0)
				{
					int rap = getvalueat(xCoordinate, yCoordinate);
					if (rap == 0)
						return true;
				}

			}
			return false;
		}


//------------------------------------------------------
//-------- Mutators ------------------------------------
//------------------------------------------------------

		//Sets the value of a pixel at a particular place on the grid.
		void Grid::setvalueat(int x, int y, int c)
		{
			if (c == 0 || c == 1)
			{
					vector<int> temp = rows_[y];
					temp[x] = c;
					rows_[y] = temp;
			}
		
		}

//------------------------------------------------------
//-------- Facilitators --------------------------------
//------------------------------------------------------

		//converts grid to a string
		string Grid::toString()
		{
			string s;
			s = "     \n  +-------------------------+\n";
			for (int j = 0; j < rows_.size(); j++)
			{
				vector<int> temp = rows_[j];
				if (j < 10)
					s = s + " |\n" + to_string(j) + "  | ";
				else
					s = s + " |\n" + to_string(j) + " | ";
				for (int i = 0; i < temp.size(); i++)
					s = s + to_string(temp[i]);
			}
			s = s + " |\n  +-------------------------+\n\n";

			return s;
		}
//------------------------------------------------------

		//converts string to an ostream type
		void Grid::output(ostream &out)
		{
			out << toString();
		}

		//convert ostream and output type to be applicable to the << operator
		ostream & operator<< (ostream & out, Grid & myGrid)
		{
			myGrid.output(out);
			return out;
		}
