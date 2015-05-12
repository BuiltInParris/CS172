//----------------------------------------------------------------------------
//
//  DU Polygon class
//    Header
//
//	  Includes DUPolygonNode header
//
//  This class represents a polygon in two dimensions as a
//  list of ordered pairs (x,y).
//
//  A DUPolygonNode consists of a DUPoint and a link.
//  A DUPolygon is a linked list of DUPolygonNode elements.
//
//----------------------------------------------------------------------------
//
//  Author:  JL Popyack
//  Course:  MCS172, 1998
//  Date:    05/18/98
//
//  Modified:       Paul Zoski 		05/15/00
//	                modified for Visual C++
//  Modified:       JL Popyack: 5/14/2
//					reformatted
//
//----------------------------------------------------------------------------
	

#ifndef _DUPolygon_h_
#define _DUPolygon_h_

#include "DUPoint.h"
using namespace std ;


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

class DUPolygonNode
{
  public:
  	
		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------
		
		  	DUPolygonNode(DUPoint pt);
		  	DUPolygonNode();
		  	
		//------------------------------------------------------
		//----- Destructor -------------------------------------
		//------------------------------------------------------
		
		  	~DUPolygonNode();
	  	
		//------------------------------------------------------
		//----- Inspectors -------------------------------------
		//------------------------------------------------------
	  	
		  	DUPoint getPoint() const;
		  	DUPolygonNode* link() const;
		  	
		//------------------------------------------------------
		//----- Mutators ---------------------------------------
		//------------------------------------------------------
		  	
			void setLink(DUPolygonNode* target);
			  	
		//------------------------------------------------------
		//----- Facilitators -----------------------------------
		//------------------------------------------------------
		
			//------------------------------------------------------
			// insert DUPolygonNode in output stream
			   void output(ostream& out) const ;
			   DUPoint operator[](int subscript);
  private:
	DUPoint pt_;
	DUPolygonNode* link_ ;
};


//----------------------------------------------------------------------------
//----- DUPolygonNode: auxiliary operator descriptions -----------------------
//----------------------------------------------------------------------------

	ostream& operator<< (ostream& out, const DUPolygonNode& pn) ;
	ostream& operator<< (ostream& out, const DUPolygonNode* ptr) ;



//----------------------------------------------------------------------------
//----------------------------------------------------------------------------



class DUPolygon 

{
  public:
	 	
		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------
		
		  	DUPolygon();
		  	
		//------------------------------------------------------
		//----- Destructor -------------------------------------
		//------------------------------------------------------
		
		  	~DUPolygon();
	  	
		//------------------------------------------------------
		//----- Inspectors -------------------------------------
		//------------------------------------------------------
	  	
		  	int numPoints() const;
		  	DUPoint getPoint(int i) const;
		  	bool isClosed() const;
		  	
		//------------------------------------------------------
		//----- Mutators ---------------------------------------
		//------------------------------------------------------
		  	
		  	void addPoint(const DUPoint &p);     
			void DUPolygon::addPointBefore(const DUPoint &p);
			void closePolygon();
			  	
		//------------------------------------------------------
		//----- Facilitators -----------------------------------
		//------------------------------------------------------
		
			//------------------------------------------------------
			// insert DUPolygon in output stream
			   void output(ostream& out) const ;

  private:
		int numPoints_;
		bool closed_polygon_ ;
		DUPolygonNode* first_ ;
		DUPolygonNode* last_ ;
};


//----------------------------------------------------------------------------
//----- DUPolygon: auxiliary operator descriptions ---------------------------
//----------------------------------------------------------------------------

	ostream& operator<< (ostream& out, const DUPolygon &polygon) ;


#endif

