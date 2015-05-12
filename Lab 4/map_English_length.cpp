//----------------------------------------------------------------------------
//
//--------------------------------- Map Test ---------------------------------
//
//----------------------------------------------------------------------------
//
// Map Test
//
// This program demonstrates use of the map<> container class:
//   - building maps between strings and English_length 
//     and between English_length and string 
//   - manipulating elements of the map
//
// JL Popyack, April 2006 
//
//----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "English_length.h"
using namespace std ;


enum CardSuit { SPADES, HEARTS, CLUBS, DIAMONDS };



map<CardSuit, string> myMap;
map<string, English_length> equivalent;

//------------------------------------

ostream & operator<< (ostream &out, CardSuit card);

int main(void)
{
//	Create a map that allows us to convert text
//  to English lengths:
//---------------------------------------------

	equivalent["inch"] = English_length(1) ;
	equivalent["foot"] = English_length(12);

	//---------------------------------------------
	//	In this space, create similar declarations
	//  for yard, furlong, and mile.
	//---------------------------------------------
	equivalent["yard"] = English_length(0, 3);
	equivalent["furlong"] = English_length(0, 0, 1220);
	equivalent["mile"] = English_length(0, 0, 1760);

//---------------------------------------------
//	Now the inverse map, that allows us to find
//  the text description of an English length:
//---------------------------------------------

	//---------------------------------------------
	//	In this space, declare the map, named
	//  description, and assign it descriptions for 
	//  inch, foot, yard, furlong, and mile.
	//---------------------------------------------
	map<English_length, string> description;

	description[English_length(1)] = "inch";
	description[English_length(12)] = "foot";
	description[English_length(0, 1)] = "foot";
	description[English_length(0, 3)] = "yard";
	description[English_length(0, 0, 1)] = "yard";
	description[English_length(0, 0, 220)] = "furlong";
	description[English_length(0, 0, 1760)] = "mile";


//---------------------------------------------
//	Investigate contents of map by allowing the
//  user to input a text description of a length
//  e.g., "3 feet" and return an English_length
//  e.g., 3*equivalent["foot"] .
//---------------------------------------------
	int n ;
	string len ;

	map<string, string> myMap;
	string s = "LOL";
	myMap["LOL"] = "Laugh Out Loud";
	myMap["ROTFL"] = "Rolling On The Floor Laughing";
	myMap["CUL8R"] = "See You Later";
	myMap["LTNS"] = "Long Time NO see";
	if (myMap[s] != "")
		cout << myMap[s];

	/*
	do
	{
		cout << "Input a measurement (e.g., '3 feet'): " ;
		cin >> n >> len ;
		if (len == "inches")
			len == "inch";
		else if (len == "feet")
			len = "foot";
		else if (len == "yards")
			len = "yard";
		else if (len == "furlongs")
			len = "furlong";
		else if (len == "miles")
			len = "mile";

		English_length el = n*equivalent[len] ;
		
		cout << el << endl ;
		cout << description[el] << endl;

		//---------------------------------------------
		//	In this space, check whether el is a 'known
		//  unit of measurement' (e.g., 1 mile) by
		//  checking whether it is defined in the map.
		//  If so, print its text description ("1 mile").
		//---------------------------------------------


	} while( n!=0 ) ;

	CardSuit card = HEARTS;

	cout << card << endl;

	*/
	system("pause");

	return 0 ;
}

ostream & operator<< (ostream &out, CardSuit card)
{
	myMap[SPADES] = "SPADES";
	myMap[HEARTS] = "HEARTS";
	myMap[CLUBS] = "CLUBS";
	myMap[DIAMONDS] = "DIAMONDS";

	out << myMap[card];

	return out;
}
