#include"pch.h"
#include "binary_space_partitioning.h"


// Definition of class constructor

 bsp::bsp():myRoot(0)
{
}

bool bsp::search(const DataType & item) const
{
	bsp::BinNodePointer locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->word)                // descend left
		{
			locptr = locptr->front;
		}
		else if (locptr->word < item)         // descend right     
		{
			locptr = locptr->back;
		}
		else                                // item found
		{
			cout << "meaning :" << locptr->meaning << endl; found = true;
		}
	}
	return found;
}



void bsp::insert(const DataType & word, DataType meaning)
{
	bsp::BinNodePointer
		locptr = myRoot,      // search pointer
		parent = 0;          // pointer to parent of current node
	bool found = false;     // indicates if item already in bsp

	while (!found && locptr != 0)
	{
		parent = locptr;
		if (word < locptr->word)         // descend left
			locptr = locptr->front;
		else if (locptr->word < word)  // descend right
			locptr = locptr->back;
		else                         // item found
			found = true;
	}

	if (!found)

	{  // construct node containing item
		locptr = new bsp::BinNode(word,meaning);
		if (parent == 0) // empty tree
			myRoot = locptr;
		else if (word < parent->word) // insert to left of parent
			parent->front = locptr;
		else // insert to right of parent
			parent->back = locptr;
	}
	//else cout << "Item already in the tree"<<endl;
}


void add(string w, string m,string f)
{
	ofstream s;
	s.open(f, ios::app);
	s << w << '	' << m << endl;
	s.close();
	
}