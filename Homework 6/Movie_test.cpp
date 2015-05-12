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
#include <algorithm>

#include <vector>
#include "Movie.h"

using namespace std;

//----------------------------------------------------------------------------
//
//------------------------------- Prototypes -------------------------------
//
//----------------------------------------------------------------------------

void promptForMovie(Movie & myMovie);
Movie_Rating stringToRating(string rating);
string trim(string s);
void swap(Actor* & a, Actor* & b);
int min_position(vector<Actor*> & a, int from, int to);
void selection_sort(vector<Actor*> & a);
void combine_actors(vector<Actor*> & a);
void combine_movies(vector<Movie*> & a);



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
	vector<Movie*> MovieS;
	vector<Actor*> ActorS;


	//Open file
	ofstream myfile;
	myfile.open("output.txt");
	ifstream fin("CS172_Spring2014_Movie_inputs.txt");
	string value;

	//Create movies
	Movie movie1("Back To The Future");

	//Set information for the first movie
	movie1.setDirector("Robert Zemeckis");
	movie1.setRating(PG);
	movie1.setYear(1985);
	movie1.setURL("http://www.imdb.com/title/tt0088763/");
	Actor actor1("Michael J Fox");
	Actor actor2("Bill Cosby");
	Actor actor3("Ryan Seacrest");

	movie1.addActor(actor1);
	movie1.addActor(actor2);
	movie1.addActor(actor3);
	//cout << movie1.getActorName(2);

	
	MovieS.push_back(new Movie());
	int i = 0;
	int r = 0;

	while (getline(fin, value)) // try to read value
	{
		MovieS[i]->setTitle(value);
		getline(fin, value);
		
		MovieS[i]->setDirector(value);

		getline(fin, value);
		MovieS[i]->setYear(atoi(value.c_str()));

		getline(fin, value);
		MovieS[i]->setRating(stringToRating(value));
		//STORE RATING INFO

		getline(fin, value);
		MovieS[i]->setURL(value);

		getline(fin, value);
		while (value != "$$$$") // try to read value
		{
			ActorS.push_back(new Actor(value));
			ActorS[r]->addMovie(MovieS[i]);
			MovieS[i]->addActor(value);
			getline(fin, value);
			r++;
		}
		MovieS.push_back(new Movie());
		i++;
	}
	//SORT LISTS AND FIND DUPLICATES



	/*for (int i = 0; i < MovieS[0]->getNumberOfActors(); i++)
	{
		cout << MovieS[0]->getTitle() << " with " << MovieS[0]->getActor(i).getName() << endl;
	}*/

	selection_sort(ActorS);
	combine_actors(ActorS);

	for (int j = 0; j < ActorS.size(); j++)
	{
		cout << ActorS[j]->getName() << " acted in: " << endl;;
		for (int i = 0; i < ActorS[j]->getNumberOfMovies(); i++)
			 cout << ActorS[j]->getMovieName(i) << endl;
	}


	//for (int i = 0; i < ActorS.size(); i++)
	//{
	//	cout << ActorS[i]->getName() << endl;
	//}







	/*
	//Sort movies using mergesort, quicksort, or sort





	//compare Movies in the vector for exact duplicates* and:
	//output the names of Movies with duplicates(and the number of duplicates for each);
		//(Two Movies are exact duplicates if all their private data(Title, Director, Year, Rating -- but not Actors) is identical.)
	//remove duplicates so that each Movie appears only once in the vector; 
	//report the original and final size of the vector(after removing duplicates).


	// allow the user to query the database, either to:
	//list all Actors in a Movie
	//list all Movies for a particular Actor (title only)
	//list full info for a given Movie (director, year, etc.)


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
	*/
	system("pause");

	return 0;
}


//write a function string trim(string s) which removes leading and trailing blanks(and other non - printing characters, such as tabs) from a string s
/*
string trim(string s)
{
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
*/
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

void swap(Actor* & a, Actor* & b)
{
	Actor temp = *a;
	*a = *b;
	*b = temp;
}

int min_position(vector<Actor*> & a, int from, int to)
{
	int min_pos = from;
	int i;
	for (i = from + 1; i <= to; i++)
	if (a[i]->getName() < a[min_pos]->getName())
		min_pos = i;
	return min_pos;
}

void selection_sort(vector<Actor*> & a)
{
	int next; // the next position to be set to the minimum

	for (next = 0; next < a.size() - 1; next++)
	{
		int min_pos = min_position(a, next, (a.size() - 1));
		if (min_pos != next)
			swap(a[min_pos], a[next]);
	}
}

bool IsEqual(Actor*joe)
{
	return true;
}

void combine_actors(vector<Actor*> & a)
{
	bool stillCombining = true;
	for (int i = 0; i < a[8]->getNumberOfMovies(); i++)
		cout << a[8]->getName() << " acted in " << a[8]->getMovie(i).getTitle() << endl;

	while (stillCombining)
	{
		stillCombining = false;
		for (int i = a.size() - 1; i > 0; i--)
		{
			if (a[i-1]->getName() == a[i]->getName())
			{
				stillCombining = true;

				for (int j = 0; j < a[i]->getNumberOfMovies(); j++)
				{
					a[i-1]->addMovie(&a[i]->getMovie(j));
				}
				cout << "Duplicate actor: " << a[i-1]->getName() << " appeared in " << a[i-1]->getNumberOfMovies() << " movies." << endl;

				a.pop_back();
				a.emplace(a.begin(), a[i - 1]);
				a.pop_back();
				i--;
			}
		}
		
	}
}

void combine_movies(vector<Movie*> & a)
{
	bool stillCombining = true;
	for (int i = 0; i < a[8]->getNumberOfActors(); i++)
		cout << a[8]->getTitle() << " acted in " << a[8]->getActor(i).getName() << endl;

	while (stillCombining)
	{
		stillCombining = false;
		for (int i = a.size() - 1; i > 0; i--)
		{
			if (a[i - 1]->getTitle() == a[i]->getTitle())
			{
				stillCombining = true;

				for (int j = 0; j < a[i]->getNumberOfActors(); j++)
				{
					a[i - 1]->addActor(a[i]->getActor(j));
				}
				cout << "Duplicate actor: " << a[i - 1]->getTitle() << " appeared in " << a[i - 1]->getNumberOfActors() << " movies." << endl;

				a.pop_back();
				a.emplace(a.begin(), a[i - 1]);
				a.pop_back();
				i--;
			}
		}

	}
}