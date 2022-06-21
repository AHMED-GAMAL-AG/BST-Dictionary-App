
/*  test test test */
#include "pch.h"
#include "binary_space_partitioning.h"

using namespace std;


int main()
{
	int ch, ch2 = -111111, ch3; 
	double time; string filename, word, w, m;

	cout << "****CHOOSE A DICTIONARY****" << endl;
	cout << "1- En->French\n2- En->German\n3- En->Italian\n4- En->Portuguese\n5- En->Spanish\n6-Exit" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:filename = "French.txt"; break;
	case 2:filename = "German.txt"; break;
	case 3:filename = "Italian.txt"; break;
	case 4:filename = "Portuguese.txt"; break;
	case 5:filename = "Spanish.txt"; break;
	case 6:exit(0);
	default:cout << " wrong input using default language " << "French" << endl; filename = "French.txt"; break;
	}
	cout << " Reading from : " << filename << "..." << endl;
	cout << endl;

	DWORD start = GetTickCount();

	bsp b;
	ifstream in;
	in.open(filename);
	assert(in.is_open());
	string line;
	string s1, s2;
	while (getline(in, line))
	{

		stringstream getdic(line);
		getline(getdic, s1, '	');
		getline(getdic, s2);
		b.insert(s1, s2);
		

	}

	DWORD end = GetTickCount();
	time = (end - start) / 1000.0;

	cout << " tree constructed in :" << time << endl;
	cout << endl;
	
	cout << "to search the dictionary press 1\nto add to the dictionary press 2" << endl;
	cin >> ch3;

	if (ch3 == 1)
	{
		do
		{
			cout << " enter word to search for " << endl;
			cin >> word;
			if (b.search(word))
			{
				cout << "" << endl;
			}
			else cout << " not found" << endl;

			cout << "press 0 to exit or any number to search again" << endl;
			cin >> ch2;
		} while (ch2 != 0);
	}
	else
	{
		 
		do
		{
			cout << " enter the word " << endl;
			cin >> w;
			cout << " enter the meaning " << endl;
			cin >> m;
			add(w, m,filename);
			cout << "press 0 to exit or any number to insert again" << endl;
			cin >> ch2;
		} while (ch2 != 0);
	}
}



