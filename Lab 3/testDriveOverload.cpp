//----------------------------------------------------------------------------
//
//-------------------------- DUPoint, DULine Tester --------------------------
//
//----------------------------------------------------------------------------
//
//  Program Name: testDriver b
//
//  This program tests implementations of DUPoint and DULine classes.
//	In particular, implementations of overloaded operators "<<" and ">>"
//
//  Author:         Hoi Man Chang
//  Course:         MCS172
//  Date:           02/06/98
//
//  Modified:       JL Popyack: 04/28/98, 5/13/98, 4/22/99, 4/15/2
//
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	#include "DUPoint.h"
	#include "DULine.h"
	using namespace std;


	template<typename T3>
	ostream& operator<< (ostream & out, T3 & line);
//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{

	//----------------------------------------------------------------------------
	//	Portions of this program's code have been "commented out".
	//	Some code needs to be provided before these sections of code can be used.
	//	Instructions are provided in the lab manual.
	//----------------------------------------------------------------------------

	    DUPoint p1(1,2), p2(3,4) ;
		cout << p1;
		
	//----------------------------------------------------------------------------
	//	Test code for DUPoint overloaded ">>" INPUT operator:
	//----------------------------------------------------------------------------

	/*
		cout << "Please input the first point in the format (x,y): ";
		cin >> p1;
		cout << "Please input the second point in the format (x,y): ";
		cin >> p2;
	*/
	
	//----------------------------------------------------------------------------
		/*
	    cout << "Output using accessor methods:" << endl;
		cout << "  p1: (" << p1.getX() << "," << p1.getY() << ")" << endl ;
		cout << "  p2: (" << p2.getX() << "," << p2.getY() << ")" << endl ;
		

	//----------------------------------------------------------------------------
	//	Test code for DUPoint output facilitator:
	//----------------------------------------------------------------------------

		cout << endl << "DUPoints output using facilitator method:" << endl ;
	   
		p1.output(cout);
		p2.output(cout);
	    
	    
	//----------------------------------------------------------------------------
	//	Test code for DUPoint overloaded "<<" OUTPUT operator:
	//----------------------------------------------------------------------------

		cout << endl ; 
		cout << endl << "DUPoints output using overloaded << operator:" << endl ;   
		

		cout << "p1=" << p1 << " ; p2=" << p2 << endl;


		DULine line1(-5,-3,2,4) ;
		DULine line2(p1,p2) ;

	
	//----------------------------------------------------------------------------
	//	Test code for DULine overloaded ">>" INPUT operator:
	//----------------------------------------------------------------------------

		cout << endl << "Please input 2 points for a line in the format"
		     << endl << "(x1,y1),(x2,y2): " << endl ;
		cin >> p1;
		cout << endl << "  Line1: " << line1 << endl;

		cout << endl ; 
	    cout << endl << "DULines output using facilitator method:" << endl ;
		

	//----------------------------------------------------------------------------
	//	Test code for DULine output facilitator:
	//----------------------------------------------------------------------------

		line1.output(cout);
		line2.output(cout);
	    
	    
	//----------------------------------------------------------------------------
	//	Test code for DULine overloaded "<<" OUTPUT operator:
	//----------------------------------------------------------------------------

		cout << endl ; 
		cout << endl << "DULines output using overloaded << operator:" << endl   
		     << "Line2: " << line2 << endl;
		string mystring1 = "Hey";
		int myint1 = -5;
		string mystring2 = myint1 + mystring1;
		puts(mystring2.c_str());
		*/
		system("pause");
	
	    return 0;
	}

	template<typename T3>
	ostream& operator<< (ostream & out, T3 & line)
	{
		//		T3 line2 = line;
		line.output();
		return out;
	}