
#include "deck.h"
#include <sstream>

Deck::Deck()
{//constructor
	list=NULL;
	size=0;
}

Deck::~Deck()
{//destructor
    delete [] list;
    size = 0;
}

Deck::Deck (const Deck & copy)
{// copy constructor
	list = copy.listCop();
	size = copy.size;
}

Deck::Deck(Card* & l,int s)
{//changes the value of list and size 
	list=l;
	size=s;
}

Card* Deck::listCop () const
{ //returns the copy of the list
	if(list==NULL) {return NULL;} //returns empty if it is empty
	Card*new_list=new Card[size];
	for (int i = 0; i < size; i++)
	{ new_list[i] = list[i];}
	return new_list;
}

const Deck & Deck::operator = (const Deck & rhs)
{//assignment (=)
	if(this != &rhs)//a=a; situation
	{
		delete[] list;
		size=rhs.size;
		Card* new_list=new Card[size];
		for(int i=0;i<size;i++)
		{new_list[i] = rhs.list[i];}
		list=new_list;
	}
	return *this;
}

Deck Deck:: operator+(const Card & rhs)
{//addition of a deck and one card
	Deck newDeck;
	newDeck.size= size+1;
	newDeck.list=new Card[newDeck.size];//new list with 1 extra slot
	for(int i=0;i<size;i++)
	{newDeck.list[i] = list[i];}
	newDeck.list[size]=rhs; //adds the given card to the last slot
	return newDeck;
}

ostream & operator<<(ostream & os, const Deck & d)
{
	Card* listCop=d.listCop(); //copy of the list
	ostringstream s;
	for(int i=0; i<d.find_size(); i++)
	{ s<<i+1<<": "<<listCop[i].name<<" - "<<listCop[i].energy<<endl; }
	os << s.str();
	return os;
}

Deck Deck::operator + (const Deck & rhs)
{//adds 2 decks 
	Card* lhs_cop=listCop(); //copies lhs and rhs
	Card* rhs_cop=rhs.listCop();

	if(size==0) //add with empty deck
	{
		Deck new_deck(rhs_cop,rhs.size);
		return new_deck;
	}

	int new_size=size+rhs.find_size();
	Card* new_list=new Card[new_size];

	for(int i=0; i<new_size; i++)
	{
		if(i<size) // adding from lhs
		{ new_list[i]=lhs_cop[i]; }

		else //adding from rhs
		{ new_list[i]=rhs_cop[i-size]; }
	}
	Deck new_deck(new_list,new_size);
	return new_deck;
}

Deck Deck::operator - (const int & rhs) 
{
	if(size-rhs<=0)//it need to return an empty deck
	{
		Card* new_list=NULL;
		Deck new_deck(new_list,0);
		return new_deck;
	}

	Card* new_list=new Card[size-rhs];
	int new_list_index=0; int old_list_index=rhs;
	while(old_list_index<size) //assigns values to the new list starting from rhs index
	{
		new_list[new_list_index]=list[old_list_index];
		new_list_index++; old_list_index++;
	}
	Deck new_deck(new_list,size-rhs);
	return new_deck;
} 

bool operator == (const Deck & lhs,const Deck & rhs)
{//returns true if energies are equal false if not
	if(lhs.total_energy()==rhs.total_energy()){return true;}
	return false;
}

bool operator < (const Deck & lhs,const Deck & rhs)
{//returns true if energy of lhs is samller than rhs false otherwise
	if(lhs.total_energy()<rhs.total_energy()){return true;}
	return false;
}

bool operator > (const Deck & lhs,const int & rhs)
{//checks if lhs has more cards than int rhs
	if(lhs.find_size()>rhs){return true;}
	return false;
}

bool operator <= (const Card & lhs,const Deck & rhs)
{//checks is there any same card in the deck
	for(int i=0; i<rhs.find_size(); i++)
	{
		if(rhs[i].name==lhs.name && rhs[i].energy==lhs.energy) //they are same
		{return true;}
	}
	//couldnt find the same card
	return false;
}

void Deck::operator += (const Deck & rhs) //uses defined = and + operators
{ *this=(*this+rhs);} 

Card& Deck:: operator[] (int rhs)const
//returns the addres of the ith element of deck
{return list[rhs];}

int Deck::find_size() const
{return size;}

Card* Deck::find_list()const
{return list;}

int Deck::total_energy()const
{//returns the total energy of the deck
	if(size==0){return 0;} //there is no card => total energy=0
	int sum=0;
	for(int i=0; i<size; i++)
	{sum+=list[i].energy;}
	return sum;
}