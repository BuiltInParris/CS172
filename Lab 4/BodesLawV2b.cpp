//----------------------------------------------------------------------------
//
//-------------------------- Bode's Law Calculation --------------------------
//
//----------------------------------------------------------------------------
//
// Name   : Bode's Law
// Version : 2.0b
// Purpose: Demonstration program to be used for 
//          examining output in scientific notation.
//          This program uses Bode's formula for 
//          estimating the distance between the Sun
//          and the planets in our solar system.
//
// Author  : Jeffrey L. Popyack
// Date    : Feb. 5, 1998
// Modified: Feb. 26, 2001; April 22, 2002; April 20, 2003
//
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	#include <iomanip>
	#include <vector>
	using namespace std; 


//----------------------------------------------------------------------------
//
//-------------------------------- Prototypes --------------------------------
//
//----------------------------------------------------------------------------

//	Draw column guides up to NumColumns wide
	void columnGuides(int NumColumns) ;



//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{
	//------------------------------------------------------------------------
	// Bode's formula estimates the distance from planet n
	// to the Sun according to the following formula:
	//                   (n-2)
	//    dist = (4 + 3*2     )/10,
	// where dist is given in astronomical units, and
	// one astronomical unit equals 93,000,000 miles.
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// PLANET_2, PLANET_3, etc. are the names of the planets.
	//------------------------------------------------------------------------
	
		vector<string> PLANET = {"Mercury", "Venus", "Earth", "Mars", "", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

	//------------------------------------------------------------------------
	//  dist2, dist 3, etc. are estimated distances of
	//  planets from the Sun, using Bode's Law:
	//  e.g., dist2 is the distance from PLANET_2 to the Sun.
	//------------------------------------------------------------------------

		vector<double> dist;
		

		dist.push_back((4) / 10.0);

		for (int i = 1; i <= 256; (i = i * 2))
		{
			if (i != 8)
				dist.push_back((4 + 3 * i) / 10.0);
			else
				dist.push_back(NULL);
		}
		columnGuides(40) ;
		
		vector<double> actualdist = { 0.39, 0.72, 1.00, 1.52, 0, 5.20, 9.54, 19.18, 30.06, 39.44 };

	//------------------------------------------------------------------------
	//  Output table of estimated distances from planets to the Sun.
	//------------------------------------------------------------------------
		cout << "Planet  Astro Units (est.)  Miles (est.)  Actual Distances" << endl ;

		for (int i = 0; i < 10; i++)
		{
			cout << left << setw(8) << PLANET[i];
			cout << right << fixed << setw(11) << setprecision(3) << dist[i];
			cout << scientific << setw(19) << setprecision(2) << dist[i] * 93000000;
			cout << fixed << setw(19) << setprecision(2) << actualdist[i];
			cout << endl;
		}
		
		system("pause");

		return 0 ;
	}


//----------------------------------------------------------------------------
//
//-------------------------- Subprogram Definitions --------------------------
//
//----------------------------------------------------------------------------

	void columnGuides(int NumColumns)
	{
	//------------------------------------------------------------------------
	/**
	   This procedure draws column guides of the form
	  
	              1         2         3    
	     123456789012345678901234567890123 ...
	     ---------------------------------
	  
	     @param NumColumns - the desired column width  
	  
	*/
	//------------------------------------------------------------------------
		
		int i ;
		
		for(i=1; i<=NumColumns/10; i++)
			cout << setw(10) << i ;
		cout << endl ;

		for(i=1; i<=NumColumns; i++)
			cout << i%10 ;
		cout << endl ;
		
		cout << setfill('-') << setw(NumColumns) << right << "-" << endl ;
		cout << setfill(' ') << resetiosflags(ios::right) ;
	}