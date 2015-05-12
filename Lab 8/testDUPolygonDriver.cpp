//----------------------------------------------------------------------------
//
//------------------------ DUPolygon Linked List Tester ----------------------
//
//----------------------------------------------------------------------------
//
//  Program Name: testDUPolygonDriver
//
//  This program investigates pointer concepts through the DUPoint and DULine 
//  classes.
//
//  Author:         JL Popyack
//  Course:         CS172
//  Date:           5/13/98
//
//  Modified:       Paul Zoski 		05/15/00
//	                modified for Visual C++
//  Modified:       JL Popyack: 5/14/2
//					reformatted
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <ciso646>
	using namespace std ;

	#include "DUPoint.h"
	#include "DUPolygon.h"
	
//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{

	//----------------------------------------------------------------------------
	//	Test DUPolygon creation and output
	//----------------------------------------------------------------------------

		DUPoint* p = new DUPoint(3, 8);
			cout << *p << endl;
			cout << p-> << endl;
		system("pause");
		return 0 ;
	}
