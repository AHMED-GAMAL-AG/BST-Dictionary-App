/* BSP.h contains the declaration of class  BSP*/

#ifndef BINARYS_SPACE_PARTITIONING
#define BINARYS_SPACE_PARTITIONING


#include <iomanip>
#include "new"
#include "string"
#include <fstream>
#include <sstream>
#include <string>
#include "cassert"
#include "iostream"
#include "windows.h"

using namespace std;


typedef  string DataType;

class bsp
{
 public :
	 /**** public Function Members ****/

	bsp();
	 /* 
	    to Construct a BSP object.

        -> constructs an empty BSP.
	 */
	
	
	bool search(const DataType & item) const;
	/* 
	    Search the BSP for item.

       -> Returns true if item(poly) found, and false otherwise.
	*/
	void insert(const DataType & word, DataType meaning);
	/*
	      Insert item into BSP.

          ->item inserted at proper position and maintain BSP property.
	*/

	
	
 private:
	 /***** Node class *****/
	 class BinNode
	 {
	 public:
		 DataType word, meaning;
		 BinNode * front; //left
		 BinNode * back;  //right

		 // BinNode constructors 
		 // Default data part is default DataType value "both links are null"
		 BinNode() : front(0), back(0)
		 {}

		 BinNode(DataType word, DataType meaning) : word(word), meaning(meaning), front(0), back(0) //data part contains item both links are null.
		 {}

	 };// end of BinNode


	 typedef BinNode*BinNodePointer;
	 BinNodePointer myRoot; /* data member*/
	


	

};// end of class bsp

#endif

void add(string w, string m,string f);


