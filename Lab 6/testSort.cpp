//----------------------------------------------------------------------------
//
//------------------------------- Sorting Test -------------------------------
//
//----------------------------------------------------------------------------
//
// Name    : Sorting Test
// Version : 2.1
//
// This program is used as a driver to test sorting
// methods and count number of comparisons and moves
// used by them.
//
// Lists of integers are generated randomly and sorted,
// with performance statistics reported afterwards.
//
// Author  : JL Popyack
// Date    : May, 1999
// Modified: May, 2002; May, 2011 -- added timer
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <iomanip>
	#include <vector>
	#include <string>
	#include <cstdlib>
	#include <ctime>
	#include <fstream>

	//---------------------------------------------------------------------
	// Global variables for #comparisons and #moves are
	// declared in utilities.h
	//---------------------------------------------------------------------

	#include "utilities.h"    
	#include "selectSort.h"
	#include "quickSort.h"
	using namespace std ;


//----------------------------------------------------------------------------
//
//-------------------------------- Prototypes --------------------------------
//
//----------------------------------------------------------------------------


	// Generate random integers in the range 0..RAND_MAX
	// and store them in v.
	void generateRandom(vector<int> &v) ;
	
	// Display elements of a vector, 10 per line
	void showVector(vector<int> &v) ;
	
	// An improved approach to sorting a list
	void fastSort(vector<int> &v, int left, int right, int &comparisons, int &moves) ;

	void merge(vector<int> & a, int fromIndex, int mid, int toIndex);

	void myMerge(ifstream & Dictionary1, ifstream & Dictionary2, ofstream & Dictionary3);

	double fastPower(double x, int n, int k, int &multiplications);

//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{
		double base = 2.0;
		int exponent = 1023;
		int mod = 10;
		int multiplications = 0;
		//for( exponent = -10; exponent <= 10; exponent++ )
		//{
		cout << "fastPower( " << base << ", " << exponent << ") = "
			<< fastPower(base, exponent, mod, multiplications) << endl;
		//cout << "slowPower( " << base << ", " << exponent << ") = "
		//<< slowPower(base, exponent) << endl;
		//}




		//---------------------------------------------------------------------
		// v is the list to be sorted; 
		// unsortedList holds the unsorted elements for re-use.
		// we don't display the vector elements if it exceeds MAX_REPORT_SIZE 
		//---------------------------------------------------------------------
			/*vector<int> v, unsortedList ; 
			int n ;
			const int MAX_REPORT_SIZE = 100 ;
			clock_t start,stop;
			int comparisons, moves ;
			double elapsedTime ;
			
			ifstream Dictionary1("Dictionary_1.txt");
			ifstream Dictionary2("Dictionary_2.txt");
			ofstream Dictionary3("SUPERDICTIONARY.txt");
			
			myMerge(Dictionary1, Dictionary2, Dictionary3);
			//cout << "Number of elements in list to create: " ;
			//cin >> n ;
		*/
		//---------------------------------------------------------------------
		// Once the desired list size is known, the lists 
		// are resized and a random list is generated. 
		//---------------------------------------------------------------------
			/*
			unsortedList.resize(n) ;
			generateRandom(unsortedList) ;
			v = unsortedList;
			
			if( n<=MAX_REPORT_SIZE )
			{
				cout << endl << "Unsorted list: " << endl;
				showVector(v) ;
			}

		//---------------------------------------------------------------------
		// Sort the list with selectSort and report the results
		//---------------------------------------------------------------------
		
			comparisons=0 ;
			moves=0 ;
			start = clock() ;
		    
			selectSort(v,comparisons,moves) ;	

			stop = clock() ;
			elapsedTime = ( clock() - start ) / (double)CLOCKS_PER_SEC;

			cout << endl << "Sorted by selectSort: " << endl;
			if( n<=MAX_REPORT_SIZE )
				showVector(v) ;

			cout << endl 
			     << "Used " << comparisons 
			     << " comparisons, " << moves 
			     << " moves, in " 
				 << elapsedTime
				 << " seconds"
				 << endl;

		//---------------------------------------------------------------------
		// Sort the list with quickSort and report the results
		//---------------------------------------------------------------------
		
			v = unsortedList;

			comparisons = 0;
			moves = 0;
			start = clock() ;

			fastSort(v, 0, v.size()-1, comparisons, moves) ;	

			stop = clock() ;
			elapsedTime = ( clock() - start ) / (double)CLOCKS_PER_SEC;
			
			cout << endl << "Sorted by fastSort: " << endl;
			if( n<=MAX_REPORT_SIZE )
				showVector(v) ;

			cout << endl 
			     << "Used " << comparisons 
			     << " comparisons, " << moves 
			     << " moves, in " 
				 << elapsedTime
				 << " seconds"
				 << endl;
			*/
			cout << endl << "Done." << endl;
			system("pause");
			
			return 0;
	}



//----------------------------------------------------------------------------
//
//-------------------------- Subprogram Definitions --------------------------
//
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//
	void generateRandom(vector<int> &v)
	{
	//------------------------------------------------------
	// Generate random integers in the range 0..RAND_MAX
	// and store them in v.
	// v random seed is chosen from the system clock so that
	// the list generated will be unique.
	//------------------------------------------------------
	
		srand(time(0)) ;
		for(int i=0; i<v.size(); i++)
			v[i] = rand() ;
	}

		
//----------------------------------------------------------------------------
//
	void showVector(vector<int> &v)
	{
	//------------------------------------------------------
	// Display elements of a vector, 10 per line
	//------------------------------------------------------
		vector<int> ::iterator it ;
		int count=0 ;
		for(it=v.begin(); it!=v.end(); it++)
		{
			cout << setw(6) << *it ;
			count = (count+1)%10 ;
			if( count==0 ) 
				cout << endl ;
		}
		cout << endl ;
	}
		

//----------------------------------------------------------------------------
//
	void fastSort(vector<int> &v, int left, int right, int &comparisons, int &moves)
	{
	//------------------------------------------------------
	// fastSort is an improved approach to sorting a list,
	// based on the following idea:
	//   - partition the list into two sublists, using
	//     Hoare's partition method.
	//   - Use selectSort on each of the sublists.
	//
	// Since selectSort uses roughly (n*n)/2 operations
	// for a list of size n, it will use roughly (n*n)/8
	// operations on a list of size n/2.
	// If the partitioning is near optimal (two sublists
	// of size n/2), fastSort will use roughly (n*n)/4
	// operations - half the work of selectSort
	//------------------------------------------------------
		int k = partition(v, left, right, comparisons, moves);
		selectSort(v, left, k, comparisons, moves);
		selectSort(v, k+1, right, comparisons, moves);
	}

	void fasterSort(vector<int> &v, int left, int right, int &comparisons, int &moves) {
		int k = partition(v, left, right, comparisons, moves);
		fastSort(v, left, k, comparisons, moves);
		fastSort(v, k + 1, right, comparisons, moves);
	}


	void myMerge(ifstream & Dictionary1, ifstream & Dictionary2, ofstream & Dictionary3)
	{
		string word1, word2;
		string ans_word;
		int numb1, numb2;
		int ans_numb;

		Dictionary1 >> word1;
		Dictionary2 >> word2;

		Dictionary1 >> numb1;
		Dictionary2 >> numb2;


		while (!Dictionary1.eof() || !Dictionary1.eof())
		{
			if (word1.compare(word2) == 0)
			{
				ans_numb = numb1 + numb2;
				Dictionary3 << word1 << "\t" << ans_numb << endl;
			}
			else if (word1.compare(word2) < 0)
				Dictionary3 << word1 << "\t" << numb1 << endl;
			else if (word1.compare(word2) > 0)
				Dictionary3 << word1 << "\t" << numb1 << endl;
			Dictionary1 >> word1;
			Dictionary2 >> word2;

			Dictionary1 >> numb1;
			Dictionary2 >> numb2;
		}

		while (!Dictionary1.eof())
		{
			Dictionary3 << word1 << "\t" << numb1 << endl;
			Dictionary1 >> word1;
			Dictionary1 >> numb1;
		}
		while (!Dictionary2.eof())
		{
			Dictionary3 << word2 << "\t" << numb2 << endl;
			Dictionary2 >> word2;
			Dictionary2 >> numb2;
		}
	}
	
	void merge(vector<int> & a, int fromIndex, int mid, int toIndex)
	{
		int n = toIndex - fromIndex + 1; // size of the range to be merged

		// merge both halves into a temporary vector b
		vector<int> b(n);

		int i1 = fromIndex;  // next element to consider in the first half
		int i2 = mid + 1;    // next element to consider in the second half
		int j = 0;           // next open position in b

		// as long as neither i1 nor i2 is past the end, 
		// move the smaller element into b 

		while (i1 <= mid && i2 <= toIndex)
		{
			if (a[i1] < a[i2])
			{
				b[j] = a[i1];
				i1++;
			}
			else
			{
				b[j] = a[i2];
				i2++;
			}
			j++;
		}

		// note that only one of the two while loops below is executed

		// copy any remaining entries of the first half
		while (i1 <= mid)
		{
			b[j] = a[i1];
			i1++;
			j++;
		}
		// copy any remaining entries of the second half
		while (i2 <= toIndex)
		{
			b[j] = a[i2];
			i2++;
			j++;
		}

		// copy back from the temporary vector
		for (j = 0; j < n; j++)
			a[fromIndex + j] = b[j];
	}


	double fastPower(double x, int n, int k, int &multiplications)
	{
		//------ return values for special cases ----------
		if (x == 0 || x == 1 || n == 1) // no calculation here
			return x;

		if (n == 0) // no calculation here
			return 1;

		if (n < 0) // negative exponent means reciprocal
		{
			return(1.0 / fastPower(fmod(x, k), -n, k, multiplications));

		}

		//-------- powering done here ---------
		if (n % 2 == 0) // n is even
		{
			multiplications++;
			//x = x%k;
			double temp = fastPower(fmod(x, k), n / 2, k, multiplications);
			return temp * temp;

		}
		else { // n is odd
			multiplications++;
			return x * fastPower(fmod(x, k), n - 1, k, multiplications);
		}
	}
