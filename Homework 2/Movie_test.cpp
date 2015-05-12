//----------------------------------------------------------------------------
//
//------------------------------ Movie_Tester ------------------------------
//
//----------------------------------------------------------------------------
//
//  Author:         Stevie Parris
//  Date:           4/7/14
//  Modified:       4/8/14  -- Stevie Parris, added comments to code
//
// ----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <vector>
#include "Movie.h"

using std::cout;
using std::cin;
using std::endl;

//----------------------------------------------------------------------------
//
//------------------------------- Prototypes -------------------------------
//
//----------------------------------------------------------------------------

void promptForMovie(Movie & myMovie);
Movie_Rating stringToRating(string rating);

//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------


int main(void)
{
	//declare variables
	string temp, real_title, real_director, rating, year, real_url;
	int real_year, j = 0;
	Movie_Rating real_rating;
	vector<Movie> storage;
	vector<string> actors;

	//Open file
	ofstream myfile;
	myfile.open("example.txt");

	//Create movies
	Movie movie1("Back To The Future"), movie2;

	//Set information for the first movie
	movie1.setDirector("Robert Zemeckis");
	movie1.setRating(PG);
	movie1.setYear(1985);
	movie1.setURL("http://www.imdb.com/title/tt0088763/");
	movie1.addActor("Michael J Fox");
	movie1.addActor("Bill Cosby");
	movie1.addActor("Ryan Seacrest");

	// TRON: Legacy // Joseph Kosinski // PG // 2010 http://www.imdb.com/title/tt1104001/
	promptForMovie(movie2);

	cout << endl;

	//accept file input
	ifstream fin("Movie_setup_spp53.txt");

	//get movie info
	while (getline(fin, real_title))
	{
		getline(fin, real_director);
		getline(fin, rating);
		real_rating = stringToRating(rating);
		getline(fin, year);
		real_year = atoi(year.c_str());
		getline(fin, real_url);


		string holder;

		//get all actors till reaching end of file or "$$$$", end marker
		while (getline(fin, holder) && holder != "$$$$")
		{
			actors.push_back(holder); //add another actor to the vector
		}

		//Create movie object
		Movie amovie(real_title, real_director, real_rating, real_year, real_url, actors);
		storage.push_back(amovie); //add movie to an vector to be recalled later
		actors.resize(0); //empty actors vector
		j++; //count number of movie
		getline(fin, real_title);
	}
	fin.close(); // close file
	
	//output movies
	movie1.output(std::cout);
	movie2.output(std::cout);
	//pull movies from the array storage
	for (int r = 0; r < j; r++)
	{
		Movie myMovie = storage[r];
		myMovie.output(std::cout);
	}
	//Output movies to file
	movie1.output(myfile);
	movie2.output(myfile);
	for (int r = 0; r < j; r++)
	{
		Movie myMovie = storage[r];
		myMovie.output(myfile);
	}
	//Close file
	myfile.close();
	//C:\Users\Stevie\Documents\Visual Studio 2013\Projects\Assignment 1
	//Pause progam for user to review output
	system("pause");

	return 0;
}

// This function is passed a movie object, and then asks the user for information to assign to the movie object.
void promptForMovie(Movie & myMovie)
{
	//declare variables
	string movieTitle, director, rating, url, noactor; 
	int year;
	Movie_Rating nmRating;
	vector<string> actor;

	//Interface with user
	cout << "Please enter the name of the movie: ";
	getline(cin, movieTitle);
	cout << "Please enter the director of the movie: ";
	getline(cin, director);
	cout << "Please enter the rating of the movie (G, PG, PG13, R, NC17, NR): ";
	getline(cin, rating);
	nmRating = stringToRating(rating); //change from string to Movie_Rating type

	// Interface with user
	cout << "Please enter the year of the movie: ";
	cin >> year;
	cout << "Please enter the url of the movie: ";
	cin.ignore(); //to return to getline
	getline(cin, url);
	cout << "Please enter an actor: ";
	getline(cin, noactor);
	actor = { noactor };

	Movie aMovie(movieTitle, director, nmRating, year, url, actor); //Create movie object with the values acquired
	myMovie = aMovie; //assign new movie object to the old

	cout << endl;
}

Movie_Rating stringToRating(string rating) // this function transforms a string to a rating or returns the default rating
{
	Movie_Rating nmRating;
	//Convert string to Movie_Rating
	if (rating == "G")
		nmRating = G;
	else if (rating == "PG")
		nmRating = PG;
	else if (rating == "PG13")
		nmRating = PG13;
	else if (rating == "R")
		nmRating = R;
	else if (rating == "NC17")
		nmRating = NC17;
	else if (rating == "NR")
		nmRating = NR;
	else
		nmRating = Movie_Rating();
	return nmRating;
}