//---------------------------------------------------------------------
//
// Random Card Generator
//
//---------------------------------------------------------------------
//
// This program generates a random number between 0 and 51 which is
// to be interpreted as a playing card from a regular bridge deck.
//
// The cards 0-12 are the Ace, Two, ..., Jack, Queen, King of Spades.
// The cards 13-25 are the corresponding cards in the suit of Hearts.
// Likewise, cards 26-38 and 39-51 are the corresponding cards in
// Clubs and Diamonds.
//
// Some of the implementation details have been left for the student.
// The purpose of this exercise is to learn about and understand the use
// of enumerated types and switch statements.
//
// Written:  JL Popyack, Mar. 2003.
//
//---------------------------------------------------------------------

	#include <iostream>
	#include <string>

//-----------------------------------------------------------
// These libraries are included for the initialization 
// and use of the random number generator:
//-----------------------------------------------------------
	#include <cstdlib>
	#include <ctime>
//-----------------------------------------------------------

	using namespace std; 

	enum CardSuit {SPADES, HEARTS, CLUBS, DIAMONDS} ;
	enum CardRank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE} ;

//----------------------------------------------------------------------------
//
//-------------------------------- Prototypes --------------------------------
//
//----------------------------------------------------------------------------

	void translateCard(int card, CardSuit &suit, CardRank &rank) ;
	void printCard(CardSuit suit, CardRank rank) ;

//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

int main(void)
{	
	//-----------------------------------------------------------
	// Initialize the random number generator
	//-----------------------------------------------------------
		srand( static_cast<unsigned int>(time(0)) ) ;	
		
		int card ;

		cout << "Ladies and Gentlemen, Mesdames et Messieurs" << endl
		     << "Welcome to Random Card Picker." << endl
		     << "What is your name, contestant? " ;

		string name ;
		getline(cin,name) ;
		
		cout << endl << "Bien, " << name << ", les jeux sont faits."
		     << endl << "Combiens des pamplemousses avez-vous, here is your card:"
		     << endl ;
	     
	//-----------------------------------------------------------
	// Generate a random choice in the interval [0,51]  
	//-----------------------------------------------------------
		card = (rand()*52.0L)/RAND_MAX ;

		cout << card << endl ;
		
		CardSuit suit ;
		CardRank rank ;
		
		translateCard(card,suit,rank) ;
		printCard(suit,rank) ;
		
		return 0 ;
}
	

//----------------------------------------------------------------------------
//
//-------------------------- Subprogram Definitions --------------------------
//
//----------------------------------------------------------------------------

	void translateCard(int card, CardSuit &suit, CardRank &rank)
	{
	//---------------------------------------------------------------------
	//  This routine is supposed to determine the suit and rank of a card,
	//  according to the following rules:
	//
	//  The cards 0-12 are the Ace, Two, ..., Jack, Queen, King of Spades.
	//  The cards 13-25 are the corresponding cards in the suit of Hearts.
	//  Likewise, cards 26-38 and 39-51 are the corresponding cards in
	//  Clubs and Diamonds.
	//---------------------------------------------------------------------
		if (card < 13)
		suit = SPADES ;
		else if (card < 26 && card >= 13)
			suit = HEARTS;
		else if (card < 39 && card >= 26)
			suit = CLUBS;
		else if (card < 52 && card >= 39)
			suit = DIAMONDS;
		
		if (card % 13 == 0)
			rank = ACE;
		if (card % 13 == 1)
			rank = TWO;
		if (card % 13 == 2)
			rank = THREE;
		if (card % 13 == 3)
			rank = FOUR;
		if (card % 13 == 4)
			rank = FIVE;
		if (card % 13 == 5)
			rank = SIX;
		if (card % 13 == 6)
			rank = SEVEN;
		if (card % 13 == 7)
			rank = EIGHT;
		if (card % 13 == 8)
			rank = NINE;
		if (card % 13 == 9)
			rank = TEN;
		if (card % 13 == 10)
			rank = JACK;
		if (card % 13 == 11)
			rank = QUEEN;
		if (card % 13 == 12)
			rank = KING;
	}
	

//----------------------------------------------------------------------------
//
	void printCard(CardSuit suit, CardRank rank)
	{
	//---------------------------------------------------------------------
	//  This routine should use switch statements to print the suit and
	//  rank of a card, e.g., "Ace of Spades".
	//---------------------------------------------------------------------
		switch (suit)
		{
		case SPADES:
			cout << "The suit is spades ";
			break;
		case HEARTS:
			cout << "The suit is hearts ";
			break;
		case CLUBS:
			cout << "The suit is clubs ";
			break;
		case DIAMONDS:
			cout << "The suit is diamonds ";
			break;
		default:
			cout << "This suit is invalid ";
			break;
		}
		switch (rank)
		{
		case TWO:
			cout << "and the rank is two." << endl;
			break;
		case THREE:
			cout << "and the rank is three." << endl;
			break;
		case FOUR:
			cout << "and the rank is four." << endl;
			break;
		case FIVE:
			cout << "and the rank is five." << endl;
			break;
		case SIX:
			cout << "and the rank is six." << endl;
			break;
		case SEVEN:
			cout << "and the rank is seven." << endl;
			break;
		case EIGHT:
			cout << "and the rank is eight." << endl;
			break;
		case NINE:
			cout << "and the rank is nine." << endl;
			break;
		case TEN:
			cout << "and the rank is ten." << endl;
			break;
		case JACK:
			cout << "and the rank is jack." << endl;
			break;
		case QUEEN:
			cout << "and the rank is queen." << endl;
			break;
		case KING:
			cout << "and the rank is king." << endl;
			break;
		case ACE:
			cout << "and the rank is ace." << endl;
			break;
		default:
			cout << "and the rank is invalid." << endl;
			break;
		}
	}
	
