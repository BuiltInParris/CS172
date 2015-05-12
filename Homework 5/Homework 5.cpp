#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "spp53_Library.h"
#include "Grid.h"

using namespace std;

void floodFill(Grid & G, int i, int j);

int main(void)
{
	//ESTABLISHING DATA--------------------
	ifstream fin("sample.txt"); //get file

	//vector of the rows
	vector <vector <int>> rows;

	char holder2[256]; // create char array

	int r = 0; //counter
	char zero = '0'; //used for translating char to numb

	while (fin.getline(holder2, 256)) //store each char in a slot in an array.
	{
		vector<int> s(0); // create vector of length 0
		for (int i = 0; i < strlen(holder2); i++)
		{
			s.push_back(abs(zero - holder2[i])); // add all the numbers in the array obtained from the file
		}
		rows.push_back(s); //add number vector to the row vector
	}

	Grid myGrid(rows); //create grid
	cout << myGrid;



	int i = -1, j = -1;
	cout << "Welcome to flood fill!" << endl;

	//run until user enters 999, basic loop to allow multiple fills
	while (i != 999 && j != 999)
	{
		//INSTRUCTIONS
		cout << "Where would you like to begin the fill? (enter the x and y coordinates, separated by a space) [enter 999 to terminate]: ";
		cin >> i >> j;
		while (i < 0 || j < 0)
		{
			cout << endl << "Invalid entry." << endl;
			cout << "Where would you like to begin the fill? (enter the x and y coordinates, separated by a space): ";
			cin >> i >> j;

		}	

		// Run floodFill command5
		floodFill(myGrid, i, j);
		
		//output to screen
		cout << myGrid;

		//save to file
		ofstream fout("newSample.txt");
		fout << myGrid;
	}

	cout << "Thanks for using floodFill!" << endl;

	system("pause");
	return 0;
}

void floodFill(Grid & G, int i, int j)
{
	//test if the spot is legal
	if (G.legalSpot(i, j))
	{
		//change value of that spot
		G.setvalueat(i, j, 1);
		if (G.legalSpot(i + 1, j) == true) // run floodFill with value to the right
			floodFill(G, i + 1, j);
		if (G.legalSpot(i, j + 1) == true) // run floodFill with value to the down
			floodFill(G, i, j + 1);
		if (G.legalSpot(i - 1, j) == true) // run floodFill with value to the left
			floodFill(G, i - 1, j);
		if (G.legalSpot(i, j - 1) == true) // run floodFill with value to the up
			floodFill(G, i, j - 1);
	}
	else
		cout << "Invalid location." << endl ; // error message
}