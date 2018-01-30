///////////////////////////////
//
// Abdel-Hakeem Badran
// 01/24/2018
// File: main.cpp
//
///////////////////////////////

#include "collection.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(){

	/*Collection<int> testCol;
	testCol.addItem(1);
	testCol.addItem(2);
	testCol.addItem(3);
	
	Collection<int> newCol(testCol);
	newCol.addItem(4);
	std::cout << "Added a 4 to the second list.\n";
	
	std::cout << "First Collection: \n";
	testCol.printCollection();

	std::cout << "Second Collection: \n";
	newCol.printCollection();
    
    Collection<int> newnewCol;
    newnewCol = newCol;
    
    std::cout << "Third Collection = Second Collection: \n";
    newnewCol.printCollection();
    
    newnewCol = newnewCol;*/
	

   // manipulating integers
   Collection<int> cone;
   cout << "Integer collection: ";
   cone.addItem(1); cone.addItem(2); cone.addItem(3);
   cone.printCollection();

   cone.removeItem(2);
   cone.printCollection();

   if(equal(cone, cone))
      cout << "cone is equal to itself" << endl;

   // manipulating strings
   string sa[] = {"yellow", "orange", "green", "blue"};
   Collection<string> ctwo;

   for(auto s : sa)
      ctwo.addItem(s);

   cout << "String collection: ";
   ctwo.printCollection();


   // manipulating character collections

   // individal collections
   Collection<char> a2g, h2n, o2u;
   for(char c='a'; c <='g'; ++c) a2g.addItem(c);
   for(char c='h'; c <='n'; ++c) h2n.addItem(c);
   for(char c='o'; c <='u'; ++c) o2u.addItem(c);

   if(!equal(a2g, h2n))
      cout << "a2g is not equal to h2n" << endl;

   // collection of collections
   Collection<Collection<char>> cpile;

   // adding individual collections
   cpile.addItem(a2g);
   cpile.addItem(h2n);
   cpile.addItem(o2u);

   // printing characters from last collection added
   cout << "Last added character collection: ";
   cpile.lastItem().printCollection(); 

}



