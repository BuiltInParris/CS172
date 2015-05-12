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

#include "Movie.h"
#include "Actor.h"

using namespace std;

//----------------------------------------------------------------------------
//
//------------------------------- Prototypes -------------------------------
//
//----------------------------------------------------------------------------

void promptForMovie(Movie & myMovie);
Movie_Rating stringToRating(string rating);
template<typename T>
void swap(T* & a, T* & b);
template<typename T>
int min_position(vector<T*> & a, int from, int to);
template<typename T>
void selection_sort(vector<T*> & a);
void combine_actors(vector<Actor*> & a);
void kill_duplicate_movies(vector<Movie*> & a);
void trim(string& s);
bool same_movie(vector<Movie*> & a, int i);


//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------


int main(void)
{
	Movie_Rating real_rating;
	vector<Movie*> MovieS;
	vector<Actor*> ActorS;


	//Open file
	ofstream myfile;
	myfile.open("output.txt");
	ifstream fin("CS172_Spring2014_Movie_inputs.txt");
	string value;
	
	//Incrementers
	int i = 0, r = 0;

	//GET INFO AND STORE INTO MOVIE AND ACTOR OBJECTS
	while (getline(fin, value)) // try to read value
	{
		trim(value);
		MovieS.push_back(new Movie());
		MovieS[i]->setName(value);
		//STORE TITLE INFO

		getline(fin, value);
		trim(value);
		MovieS[i]->setDirector(value);
		//STORE DIRECTOR INFO

		getline(fin, value);
		trim(value);
		MovieS[i]->setYear(atoi(value.c_str()));
		//STORE YEAR INFO

		getline(fin, value);
		trim(value);
		MovieS[i]->setRating(stringToRating(value));
		//STORE RATING INFO

		getline(fin, value);
		trim(value);
		MovieS[i]->setURL(value);
		//STORE URL INFO

		getline(fin, value);
		trim(value);
		while (value != "$$$$") // try to read value
		{
			ActorS.push_back(new Actor(value));

			MovieS[i]->addActor(ActorS[r]);
			ActorS[r]->addMovie(MovieS[i]);
			getline(fin, value);
			trim(value);
			r++;
		} 
		//STORE ACTOR INFO

		i++;
	}
	


	//Eliminate duplicate movies
	kill_duplicate_movies(MovieS);


	//Combine duplicate actors
	combine_actors(ActorS);

	cout << endl;


	//User input strings
	string ans1, ans2;
	

	while (ans1 != "4")
	{
		cout <<  "\n\nEnter 1 to access a movie's actors. \nEnter 2 to access all movie titles for an actor. \nEnter 3 to access all movie information for an actor.\nEnter 4 to exit.\nInput: ";
		cin >> ans1;
		cin.ignore();
		if (ans1 == "1")
		{
			cout << "Movie title: ";
			getline(cin, ans2);
			trim(ans2);
			for (int i = 0; i < MovieS.size(); i++)
			{
				if (ans2 == MovieS[i]->getName())
				{
					cout << MovieS[i]->getName() << endl;
					cout << "Actors: " << endl;
					for (int j = 0; j < MovieS[i]->getNumberOfActors(); j++)
					{
						cout << MovieS[i]->getActorName(j) << endl;
					}
				}
			}

		
		}
		else if (ans1 == "2")
		{
			cout << "Actor Name: ";
			getline(cin, ans2);
			trim(ans2);
			for (int i = 0; i < ActorS.size(); i++)
			{
				if (ans2 == ActorS[i]->getName())
				{
					cout << ActorS[i]->getName() << endl;
					cout << "Movies: " << endl;
					for (int j = 0; j < ActorS[i]->getNumberOfMovies(); j++)
					{
						cout << ActorS[i]->getMovieName(j) << endl;
					}
				}
			}
		}
		else if (ans1 == "3")
		{
			cout << "Movie Title: ";
			getline(cin, ans2);
			trim(ans2);
			for (int i = 0; i < MovieS.size(); i++)
			{
				if (ans2 == MovieS[i]->getName())
				{
					MovieS[i]->output(cout);
				}
			}
		}
		else if (ans1 == "3")
			cout << "Goodbye." << endl;
		else
			cout << "Invalid entry. Please try again." << endl;
	}

	system("pause");

	return 0;
}


//Trim, eliminate the whitespace on either side of the string
void trim(string& s)
{
	int start = s.find_first_not_of(" ");
	int end = s.find_last_not_of(" ");
	s = s.substr(start, end - start + 1);
}


//Turn a string to a rating object
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

//SELECTION SORT ALGORITHMIC FUNCTIONS

template<typename T>
void swap(T* & a, T* & b)
{
	T *temp = a;
	a = b;
	b = temp;
}

template<typename T>
int min_position(vector<T*> & a, int from, int to)
{
	int min_pos = from;
	int i;
	for (i = from + 1; i <= to; i++)
	if (a[i]->getName() < a[min_pos]->getName())
		min_pos = i;
	return min_pos;
}

template<typename T>
void selection_sort(vector<T*> & a)
{
	int next; // the next position to be set to the minimum

	for (next = 0; next < a.size() - 1; next++)
	{
		int min_pos = min_position(a, next, (a.size() - 1));
		if (min_pos != next)
			swap(a[min_pos], a[next]);
	}
}

//eliminate duplicate movies
void kill_duplicate_movies(vector<Movie*> & a)
{
	selection_sort(a);
	int i = 0;
	int x = 1;
	vector<Movie*>::iterator MovieIterator = a.begin();
	int original = a.size();

	for (int i = 0; i < a.size() - 1; i++)
	{
		MovieIterator++;
		int instancesOfMovie = 0;
		if (same_movie(a, i))
		{
			while (same_movie(a, i))
			{
				a[i + 1]->~Movie();
				MovieIterator = a.erase(MovieIterator);			
				instancesOfMovie++;
			}
			cout << "Duplicate movie: " << a[i]->getName() << " had " << instancesOfMovie << " duplicates." << endl;
		}

	}
	cout << "The original size of the vector was: " << original << endl << "The new size of the vector is: " << a.size() << endl << endl;
}

//bool formula to test if movie at point in a vector is the same
bool same_movie(vector<Movie*> & a, int i)
{
	if (a[i]->getName() == a[i + 1]->getName())
	{
		if (a[i]->getDirector() == a[i + 1]->getDirector())
		{
			if (a[i]->getURL() == a[i + 1]->getURL())
			{
				if (a[i]->getRating() == a[i + 1]->getRating())
				{
					if (a[i]->getYear() == a[i + 1]->getYear())
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

//Combines duplicate actors' data to obtain a list of movies.
void combine_actors(vector<Actor*> & a)
{
	selection_sort(a);
	int i = 0;
	int x = 1;
	vector<Actor*>::iterator ActorIterator = a.begin();
	int original = a.size();

	for (int i = 0; i < a.size() - 1; i++)
	{
		ActorIterator++;
		if (a[i]->getName() == a[i + 1]->getName())
		{
		while (a[i]->getName() == a[i + 1]->getName())
		{
			//Taking care of duplicate actors with deleted duplicate movies
			while (a[i]->getMovieName(0) == "")
			{
				a[i]->~Actor();
				ActorIterator--;
				ActorIterator = a.erase(ActorIterator);
				ActorIterator++;
			}

			// If it's not a null duplicate, combine movie selection
			if (a[i + 1]->getMovieName(0) != "")
			{
				a[i]->addMovie(a[i + 1]->getMovie(0));
			}
			//eliminate extracted elements from vector, info passed to new object above
			a[i + 1]->~Actor(); 
			ActorIterator = a.erase(ActorIterator);
		}
		//print duplicate info
		cout << "Duplicate actor: " << a[i]->getName() << " had " << a[i]->getNumberOfMovies() << " duplicate." << endl;
		}

	}

	cout << "The original size of the vector was: " << original << endl << "The new size of the vector is: " << a.size() << endl << endl;
}