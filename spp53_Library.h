//Stevie Parris version 1.0
//Revision History:
//Created February 25, 2014 : added promptForString function - include iostream/string
#ifndef

#include <string>
#include <iostream>
using namespace std;

static string promptForString(string prompt); //prototype

static string promptForString(string prompt) // function that asks user for string and returns it
{
	cout << prompt << endl; // print the user prompt
	string input;
	getline(cin, input); //store user's string
	return input;
}

bool createNewFile(ofstream& out, string filename)
{
	bool test = false;
	string input;
	fstream fin;
	fin.open(filename.c_str(), ios::in);

	if(fin.is_open())
    {
		fin.close();
		test = true;
    }
    fin.close();

    if(test == true)
	{
		cout << "A file with this name already exists. \n Would you like to overwrite this file? (y or n)\n";
		cin >> input;
		if(input == "n")
		{
			cout << "Would you like to cancel or change the name of the file? (c or n)\n";
			cin >> input;
			if (input == "n")
			{
				cout << "Enter a new filename: \n";
				cin >> filename;
				out.open(filename);
				return true;
			}
		}
	}
	else
	{
		ofstream myfile;
		out.open(filename);
		return true;
	}

	return false;
}



#endif