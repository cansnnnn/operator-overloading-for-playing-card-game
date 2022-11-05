
#include <iostream>
#include <string>
using namespace std;

#ifndef _cansinnarsahin_Narsahin_Cansin_hw5_deck_H
#define _cansinnarsahin_Narsahin_Cansin_hw5_deck_H

struct Card 
{ 
	string name;
	int energy;
};

class Deck
{
private:
	Card * list;	//a pointer to the top of the daynamic array
	int size;		//size of the deck

public:

	
	Deck();										//constructors
	Deck::Deck (const Deck & copy);				//Deep copy constructor
	Deck(Card* & l, int s);						//changes the value of list and size 
	~Deck();									//Destructor
	const Deck & operator = (const Deck & rhs);	//Assignment operator
	Card * listCop () const;					//Generates the copy of the list
	Card* find_list()const;						//returns the list
	int find_size() const;						//returns the size 
	Deck operator+(const Card & rhs);			//sum of a deck and a card
	Deck operator + (const Deck & rhs);			//sum of 2 decks
	Deck operator - (const int & rhs);			//removes top rhs card
	int total_energy() const;			//retruns the total energy of the deck
	void operator += (const Deck & rhs);		//Assignment operator
	Card& operator[] (int rhs)const;			//returns the addres of the ith element of deck
	
	
	
	
};

//free functions
ostream & operator<<(ostream & os, const Deck & d);		//returns ostream for cout
bool operator == (const Deck & lhs,const Deck & rhs);	//check wheter 2 Decks' total energies are same or not
bool operator < (const Deck & lhs,const Deck & rhs);	//compare 2 Decks' total energies
bool operator > (const Deck & lhs,const int & rhs);		//checks if deck have more cards than rhs
bool operator <= (const Card & lhs,const Deck & rhs);	//checks is there any same card in the deck

#endif