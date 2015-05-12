//----------------------------------------------------------------------------
//
//-------------------------------- Personality -------------------------------
// 
//----------------------------------------------------------------------------
//
//  Program Name: Person.cpp
//
//  This is a test program for investigating use of pointers in class design
//  and implementation.
//
//  This program contains a partial class declaration and definition for a
//  Person class
//
//----------------------------------------------------------------------------
//
//  Author:         P Zoski, JL Popyack
//  Date:           05/10/3
//
//----------------------------------------------------------------------------


	#include <iostream>
	#include <string>
	#include <ciso646>
	using namespace std ;

	
//----------------------------------------------------------------------------
//
//  Person class
//    Declaration
//
//----------------------------------------------------------------------------


	class Person
	{
		public:

		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------

			Person() ;
			Person(string name) ;
			~Person() ;

		//------------------------------------------------------
		//----- Inspectors -------------------------------------
		//------------------------------------------------------

			string getName() ;
			Person * getSpouse() ;
			
		//------------------------------------------------------
		//----- Mutators ---------------------------------------
		//------------------------------------------------------

			bool marry(Person & p) ;
			void adoptSon(Person & p);
			void adoptDaughter(Person & p);
			void addSibling(Person & p);
			
		private:
			string name_ ;
			Person * spouse_ ;
			Person * son_ ;
			Person * daughter_ ;
			Person * sibling_;
	} ;

	
//----------------------------------------------------------------------------
//
//  Person class
//    Implementation
//
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//----- Constructors ---------------------------------------------------------
//----------------------------------------------------------------------------

	Person::Person()
	{ 
		name_ = "";
		spouse_ = nullptr;
		son_ = nullptr;
		daughter_ = nullptr;
		sibling_ = nullptr;
	}

	Person::Person(string name)
	{ 
		spouse_ = new Person;
		son_ = new Person;
		daughter_ = new Person;
		sibling_ = new Person;
		name_ = name ;

	}

	Person::~Person()
	{ }

//----------------------------------------------------------------------------
//----- Inspectors -----------------------------------------------------------
//----------------------------------------------------------------------------

	string Person::getName()
	{ 
		return name_ ;
	}

	Person * Person::getSpouse()
	{
		return spouse_ ;
	}

	Person * newborn(string name)
	{
		Person p(name);
		return &p;
	}


	Person * newkid(string name)
	{
		Person * p = new Person(name);
		return p;
	}

//----------------------------------------------------------------------------
//----- Mutators -------------------------------------------------------------
//----------------------------------------------------------------------------

	void Person::adoptSon(Person & p)
	{
		son_ = &p;
	}

	void Person::adoptDaughter(Person & p)
	{
		daughter_ = &p;
		if (getSpouse() != nullptr)
		{
			Person q = *getSpouse();
			

		}
	}
	void Person::addSibling(Person & p)
	{
		sibling_ = &p;
	}

	bool Person::marry(Person & p)
	{ 
	//----------------------------------------------------------------------------
	// parameter must be passed by reference, otherwise implicit
	// object will marry a copy of p
	//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		// can't get married if a Person is already married
		//----------------------------------------------------------------------------
			if (spouse_ != NULL or p.spouse_ != NULL)
				 return false ; 
	     
		//----------------------------------------------------------------------------
		// implicit Person marries person p
		// p marries implicit Person
		//----------------------------------------------------------------------------
			spouse_ = & p; 
			p.spouse_ = this ;  
		
		return true;  
	}

	
//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{
		Person George("George Jetson"), 
		       Jane("Jane Jetson"), 
		       Judy("Judy Jetson"), 
		       Elroy("Elroy Jetson") ;

		Person * d = newkid("Jessy");
		Person * e = newkid("Josh");
		Person * f = newkid("Ben");
		//d->marry(*e);
		//cout << d->getSpouse()->getName() << endl;
		//cout << e->getSpouse()->getName() << endl;

		George.marry(Jane);
		George.adoptDaughter(*d);

		system("pause");
		return 0 ;
	}

